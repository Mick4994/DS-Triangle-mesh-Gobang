//
// Created by Mick4994 on 2023/6/17.
//

#include <cmath>
#include <iostream>

#include "../lib64/graphics.h"
#include "../include/ChessBoardUI.h"
#include "../include/JudgeWin.h"

void LoadChessBoardUI(ChessBoard& chessBoard) {
    initgraph((BOARD_WEIGHT + 1) * WEIGHT_GRAPE, (BOARD_WEIGHT + 1) * WEIGHT_GRAPE);  // 创建绘图窗口
    IMAGE background;
    loadimage(&background,
              _T("../res/chessboard.png"));
    putimage(0, 0, &background);

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
}

void DrawCloseButton() {
    RECT R1={CLOSE_X - CLOSE_R, CLOSE_Y - CLOSE_R, CLOSE_X + CLOSE_R, CLOSE_Y + CLOSE_R};
    setfillcolor(RED);
    fillcircle(CLOSE_X, CLOSE_Y, CLOSE_R);
    settextcolor(WHITE);
    setbkmode(TRANSPARENT);
    drawtext('x',&R1,DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}

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
                    PrintJudgeWin(chessBoard.Board, i, j);
                    count++;
                }
            }
        }
    }
}

void DrawRes(int res) {
    RECT R1={WIN_DISPLAY_X1,
             WIN_DISPLAY_Y1,
             WIN_DISPLAY_X2,
             WIN_DISPLAY_Y2};
    settextcolor(WHITE);
    LPCTSTR lpszFace;
    settextstyle(
            WIN_DISPLAY_Y2 - WIN_DISPLAY_Y1,
            (WIN_DISPLAY_X2 - WIN_DISPLAY_X1 ) / 10,
            lpszFace
    );
    setbkmode(OPAQUE);
    setbkcolor(BLACK);
    if(res == CONTINUE) {
        drawtext("Continue",&R1,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    } else if(res == WHITE_WIN) {
        drawtext("White win",&R1,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    } else if(res == BLACK_WIN)
        drawtext("Black win",&R1,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CloseWindowAction(ExMessage& exMessage, bool& isExit) {
    if(pow(exMessage.x - CLOSE_X, 2) + pow(exMessage.y - CLOSE_Y, 2) <= pow(CLOSE_R, 2)) {
        std::cout << "Exit!" << std::endl;
        isExit = true;
    }
}
