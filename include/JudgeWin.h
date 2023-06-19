//
// Created by Mick4994 on 2023/6/18.
//

#ifndef EASYX_JUDGEWIN_H
    #define EASYX_JUDGEWIN_H
#pragma once
    extern int Line_Length[15];
    #define CONTINUE 0
    #define BLACK_WIN 1
    #define WHITE_WIN 2

    int getLine_x(int row, int cel);
    int getLine_y(int row, int cel);
    int getLine_z(int row, int cel);

    int JudgeWin(int chessBoard[][15], int row, int cel);
    void PrintJudgeWin(int chessBoard[][15], int row, int cel, int& res);
    void StopGame(int chessBoard[][15]);
#endif //EASYX_JUDGEWIN_H
