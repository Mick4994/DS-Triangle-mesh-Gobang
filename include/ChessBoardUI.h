//
// Created by Mick4994 on 2023/6/17.
//

#ifndef EASYX_CHESSBOARDUI_H
    #define EASYX_CHESSBOARDUI_H
#pragma once

    #include "ChessBoardInit.h"

    #define BOARD_WEIGHT 29
    #define BOARD_HEIGHT 15

    #define HEIGHT_GRAPE 30
    #define WEIGHT_GRAPE 20
    #define X_MOVE 60 + WEIGHT_GRAPE / 2

    #define DRAW_RADIUS 5
    #define ACTION_RADIUS 15
    #define CHESS_RADIUS 15

    #define CLOSE_X 580
    #define CLOSE_Y 20
    #define CLOSE_R 15

    #define BLACK_CHESS 1
    #define WHITE_CHESS 2

    typedef struct CircleBUTTON {
        int x, y, radius;
    } CircleBUTTON;

    void DrawCloseButton();
    void ChessDotAction(ExMessage& exMessage, ChessBoard& chessBoard, int& count);
    void CloseWindowAction(ExMessage& exMessage, bool& isExit);
#endif //EASYX_CHESSBOARDUI_H
