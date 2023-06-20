//
// Created by Mick4994 on 2023/6/17.
//

#include "../include/ChessBoardInit.h"
#include "../include/ChessBoardUI.h"


ChessBoard::ChessBoard() {
    ChessBoardInit();
}

//计算
void ChessBoard::ChessBoardInit() {
    memset(Board, NOT_READY, sizeof(Board));
    for (int row = 0; row <= 7; row++) {//第0行到第7行
        for (int cel = 7 - row; cel <= 7 + row; cel += 2) {
            Board[row][cel] = 0;
        }
    }
    for (int row = 8; row <= 21; row++) {//第8行到第21行
        for (int cel = (row + 1) % 2; cel <= 14; cel += 2) {
            Board[row][cel] = 0;
        }
    }
    for (int row = 22; row <= 28; row++) {//第22行到第28行
        for (int cel = row - 21; cel <= 35 - row; cel += 2) {
            Board[row][cel] = 0;
        }
    }
};