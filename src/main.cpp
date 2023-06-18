//
// Created by Mick4994 on 2023/6/17.
//

#include <iostream>
#include "../lib64/graphics.h"
#include <conio.h>
#include <vector>

#include "../include/ChessBoardUI.h"
#include "../include/ChessBoardInit.h"

int ChessBoard::full = 0;

int main() {
    ChessBoard chessBoard;
    initgraph((BOARD_WEIGHT + 1) * WEIGHT_GRAPE, (BOARD_WEIGHT + 1) * WEIGHT_GRAPE);  // 创建绘图窗口
    IMAGE background;
    loadimage(&background,
              _T("../res/chessboard.png"));
    putimage(0, 0, &background);

    CircleBUTTON circleButton[BOARD_WEIGHT][BOARD_HEIGHT];
    DrawCloseButton();

    for (int i = 0; i < BOARD_WEIGHT; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (chessBoard.Board[i][j].status == 0) {//二维数组打印测试,以下4行运行其一
                setfillcolor(BLACK);
                fillcircle(
                        j * HEIGHT_GRAPE + HEIGHT_GRAPE / 2 + X_MOVE,
                        i * WEIGHT_GRAPE + WEIGHT_GRAPE,
                        DRAW_RADIUS
                        );
            }
        }
    }

//    std::vector<GomokuNode*> xyz[3][15];

    GomokuNode* xyzBoard[3][15][15];

    bool isExit = false;
    int count = 0;
    while (!isExit) {
        ExMessage exMessage = getmessage(EM_MOUSE);
        bool isDown = false;
        switch (exMessage.message) {
            case WM_LBUTTONDOWN:
                if(!isDown) {
                    isDown = true;
                    ChessDotAction(exMessage, chessBoard, count);
                    CloseWindowAction(exMessage, isExit);
                }
                break;
            case WM_LBUTTONUP:
                isDown = false;
                break;
            default:
                break;
        }
    }
    closegraph();
    return 0;
}