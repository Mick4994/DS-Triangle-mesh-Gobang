//
// Created by Mick4994 on 2023/6/17.
//

#ifndef EASYX_CHESSBOARDINIT_H
    #define EASYX_CHESSBOARDINIT_H
#pragma once
    class GomokuNode {
    public:
        int status;
        int Line_x, Line_y, Line_z;
        GomokuNode();
    };

    class ChessBoard {
    public:
        static int full;    //棋盘的落子数，用于判断落子是否已满
        GomokuNode **Board;//二维数组棋盘
        ChessBoard();

    private:
        void ChessBoardInit();
    };
#endif //EASYX_CHESSBOARDINIT_H
