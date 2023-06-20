//
// Created by Mick4994 on 2023/6/17.
//

#ifndef EASYX_CHESSBOARDUI_H
    #define EASYX_CHESSBOARDUI_H
#pragma once

    #include "../include/ChessBoardInit.h"

    #include "../lib64/graphics.h"

    #include <iostream>

    #define NOT_READY -1
    #define NONE 0

    #define HEIGHT_GRAPE 30
    #define WEIGHT_GRAPE 20
    #define X_MOVE 60 + WEIGHT_GRAPE / 2

    #define DRAW_RADIUS 5
    #define ACTION_RADIUS 15
    #define CHESS_RADIUS 15

    #define WIN_DISPLAY_X1 20
    #define WIN_DISPLAY_Y1 20
    #define WIN_DISPLAY_X2 150
    #define WIN_DISPLAY_Y2 70

    #define MODE_DISPLAY_X1 500
    #define MODE_DISPLAY_Y1 40
    #define MODE_DISPLAY_X2 595
    #define MODE_DISPLAY_Y2 70

    #define WHODROP_DISPLAY_X1 490
    #define WHODROP_DISPLAY_Y1 80
    #define WHODROP_DISPLAY_X2 595
    #define WHODROP_DISPLAY_Y2 105

    #define CLOSE_X 580
    #define CLOSE_Y 20
    #define CLOSE_R 15

    #define BLACK_CHESS 1
    #define WHITE_CHESS 2

    void LoadChessBoardUI(ChessBoard& chessBoard, bool isVsAI);

    void DrawCloseButton();
    void DrawMode(bool isVsAI);
    void DrawWhoDrop(std::string whodrop);
    void DrawRes(int res);

    void ChessDotAction(ExMessage& exMessage, ChessBoard& chessBoard, int& count, bool isVsAI);
    void CloseWindowAction(ExMessage& exMessage, bool& isExit);
    void AIAction(ChessBoard& chessBoard, int& res);
#endif //EASYX_CHESSBOARDUI_H
