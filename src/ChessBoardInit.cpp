//
// Created by Mick4994 on 2023/6/17.
//

#include "../include/ChessBoardInit.h"
#include <cmath>


GomokuNode::GomokuNode() {
    status = -1;
    Line_x = Line_y = Line_z = -1;
}

ChessBoard::ChessBoard() {
    Board = new GomokuNode *[29];
    for (int i = 0; i < 29; i++) {
        Board[i] = new GomokuNode[15];
    }
    ChessBoardInit();
}

//计算
void ChessBoard::ChessBoardInit() {
    for (int row = 0; row <= 7; row++) {//第0行到第7行
        for (int cel = 7 - row; cel <= 7 + row; cel += 2) {
            Board[row][cel].status = 0;
            Board[row][cel].Line_x = abs(row - cel + 7) / 2;
            Board[row][cel].Line_y = cel;
            Board[row][cel].Line_z = (row + cel - 7) / 2;
        }
    }
    for (int row = 8; row <= 21; row++) {//第8行到第21行
        for (int cel = (row + 1) % 2; cel <= 14; cel += 2) {
            Board[row][cel].status = 0;
            Board[row][cel].Line_x = abs(row - cel + 7) / 2;
            Board[row][cel].Line_y = cel;
            Board[row][cel].Line_z = (row + cel - 7) / 2;
        }
    }
    for (int row = 22; row <= 28; row++) {//第22行到第28行
        for (int cel = row - 21; cel <= 35 - row; cel += 2) {
            Board[row][cel].status = 0;
            Board[row][cel].Line_x = abs(row - cel + 7) / 2;
            Board[row][cel].Line_y = cel;
            Board[row][cel].Line_z = (row + cel - 7) / 2;
        }
    }
};