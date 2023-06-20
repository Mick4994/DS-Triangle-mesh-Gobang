//
// Created by Mick4994 on 2023/6/17.
//

#include "../lib64/graphics.h"

#include "../include/ChessBoardUI.h"


int ChessBoard::full = 0;
int ChessBoard::count = 0;
bool ChessBoard::end = false;

int main() {
    bool isVsAI = false;
    int chooseMode = MessageBox(NULL, _T("Vs AI Or Vs Person?\n OK for Vs AI, Cancel for Vs Person"), _T("Start Game"),MB_OKCANCEL);
    if(chooseMode == IDOK) {
        isVsAI = true;
    }
    ChessBoard chessBoard;
    LoadChessBoardUI(chessBoard, isVsAI);

    bool isExit = false;

    while (!isExit) {
        ExMessage exMessage = getmessage(EM_MOUSE);
        bool isDown = false;
        switch (exMessage.message) {
            case WM_LBUTTONDOWN:
                if(!isDown) {
                    isDown = true;
                    ChessDotAction(exMessage, chessBoard, ChessBoard::count, isVsAI);
                    CloseWindowAction(exMessage, isExit);
                }
                break;
            case WM_LBUTTONUP:
                isDown = false;
                break;
            default:
                break;
        }
        if(ChessBoard::end) {
            ChessBoard::end = false;
            int choose = MessageBox(NULL, _T("Start a new Game?"), _T("Game Over"),MB_OKCANCEL);
            if(choose == IDOK) {
                closegraph();
                chessBoard.ChessBoardInit();
                chooseMode = MessageBox(NULL, _T("Vs AI Or Vs Person?\n OK for Vs AI, Cancel for Vs Person"), _T("Start Game"),MB_OKCANCEL);
                if(chooseMode == IDOK) {
                    isVsAI = true;
                } else {
                    isVsAI = false;
                }
                LoadChessBoardUI(chessBoard, isVsAI);
            }
        }
    }
    closegraph();
    return 0;
}