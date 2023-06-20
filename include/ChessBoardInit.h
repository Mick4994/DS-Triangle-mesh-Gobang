//
// Created by Mick4994 on 2023/6/17.
//

#ifndef EASYX_CHESSBOARDINIT_H
    #define EASYX_CHESSBOARDINIT_H
//#pragma once
    #define BOARD_WEIGHT 29
    #define BOARD_HEIGHT 15
    class ChessBoard {
    public:
        static int full;    //棋盘的落子数，用于判断落子是否已满
        static int count;
        static bool end;
        int Board[BOARD_WEIGHT][BOARD_HEIGHT];//二维数组棋盘
        ChessBoard();
        int lastrow;
        int lastcel;
        void ChessBoardInit();
    };
#endif //EASYX_CHESSBOARDINIT_H
