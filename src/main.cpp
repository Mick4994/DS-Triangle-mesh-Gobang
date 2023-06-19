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
int ChessBoard::count = 0;

int main() {
    ChessBoard chessBoard;
    LoadChessBoardUI(chessBoard);

    bool isExit = false;

    while (!isExit) {
        ExMessage exMessage = getmessage(EM_MOUSE);
        bool isDown = false;
        switch (exMessage.message) {
            case WM_LBUTTONDOWN:
                if(!isDown) {
                    isDown = true;
                    ChessDotAction(exMessage, chessBoard, ChessBoard::count);
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