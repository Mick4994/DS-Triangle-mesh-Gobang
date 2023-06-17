//
// Created by Mick4994 on 2023/6/17.
//
#include <graphics.h>
#include <cmath>
#include <iostream>
#include "../include/ChessBoardUI.h"

void DrawCloseButton() {
    setfillcolor(RED);
    fillcircle(CLOSE_X, CLOSE_Y, CLOSE_R);
};

void ChessDotAction(ExMessage& exMessage, ChessBoard& chessBoard, int& count) {
    for (int i = 0; i < BOARD_WEIGHT; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (chessBoard.Board[i][j].status == 0) {

                int x = j * HEIGHT_GRAPE + HEIGHT_GRAPE / 2 + X_MOVE;
                int y = i * WEIGHT_GRAPE + WEIGHT_GRAPE;

                if(pow(exMessage.x - x, 2) + pow(exMessage.y - y, 2) <= pow(ACTION_RADIUS, 2)) {
                    chessBoard.Board[i][j].status = count % 2 + 1;
                    if(count % 2 + 1 == BLACK_CHESS) {
                        setfillcolor(BLACK);
                    } else {
                        setfillcolor(WHITE);
                    }
                    fillcircle(x, y, CHESS_RADIUS);
                    std::cout << "count:" << count << " x:" << i << " y:" << j << std::endl;
                    count++;
                }
            }
        }
    }
}

void CloseWindowAction(ExMessage& exMessage, bool& isExit) {
    if(pow(exMessage.x - CLOSE_X, 2) + pow(exMessage.y - CLOSE_Y, 2) <= pow(CLOSE_R, 2)) {
        std::cout << "Exit!" << std::endl;
        isExit = true;
    }
}
