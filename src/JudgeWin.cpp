//
// Created by Mick4994 on 2023/6/18.
//
#include <iostream>
#include <cmath>
#include "../include/ChessBoardInit.h"
#include "../include/JudgeWin.h"
#include "../include/ChessBoardUI.h"

int Line_Length[15] = { 8,9,10,11,12,13,14,15,14,13,12,11,10,9,8 };

int getLine_x(int row, int cel) {
    return cel;
}

int getLine_y(int row, int cel) {
    return (row + cel - 7) / 2;
}

int getLine_z(int row, int cel) {
    return abs(row - cel + 7) / 2;
}

//判断胜负，参数为棋盘和落子的坐标，返回值为0（无胜负），1（白子胜），2（黑子胜）   chessBoard[row][cel] 为color
int JudgeWin(int chessBoard[][15], int row, int cel) {

    //x方向，y方向，z方向上的线的编号
    int Line_x = getLine_x(row, cel);
    int Line_y = getLine_y(row, cel);
    int Line_z = getLine_z(row, cel);

    //x方向，y方向，z方向上的连续相同棋子的最大个数
    int max_x = 0;
    int max_y = 0;
    int max_z = 0;

    //x方向，y方向，z方向上的遍历起点坐标
    int start_row_x = abs(7 - Line_x);
    int start_cel_x = Line_x;

    int start_row_y = Line_y <= 7 ? Line_y : Line_y * 2 - 7;
    int start_cel_y = 14 < 7 + Line_y ? 14 : 7 + Line_y;

    int start_row_z = Line_z <= 7 ? Line_z : Line_z * 2 - 7;
    int start_cel_z = 0 > 7 - Line_z ? 0 : 7 - Line_z;


    //x方向，y方向，z方向上的遍历长度
    int len_x = Line_Length[Line_x];
    int len_y = Line_Length[Line_y];
    int len_z = Line_Length[Line_z];

    //当前落子的颜色（1为白子，2为黑子）
    int color = chessBoard[row][cel];

    //遍历x方向上的线
    for (int i = 0; i < len_x; i++) {

        int cur_color = chessBoard[start_row_x + i * 2][start_cel_x];//获取当前遍历到的棋子的颜色

        if (cur_color == color) {	//如果当前颜色与落子颜色相同，则最大连续相同棋子个数加一
            max_x++;

            if (max_x == 5) {			//如果最大连续相同棋子个数达到5，则返回落子颜色
                return color;
            }
        }
        else {						//否则，最大连续相同棋子个数归零
            max_x = 0;
        }
    }

    //遍历y方向上的线
    for (int i = 0; i < len_y; i++) {
        int cur_color = chessBoard[start_row_y + i][start_cel_y - i];
        if (cur_color == color) {
            max_y++;
            if (max_y == 5) {
                return color;
            }
        }
        else {
            max_y = 0;
        }
    }

    //遍历z方向上的线
    for (int i = 0; i < len_z; i++) {
        int cur_color = chessBoard[start_row_z + i][start_cel_z + i];
        if (cur_color == color) {
            max_z++;
            if (max_z == 5) {
                return color;
            }
        }
        else {
            max_z = 0;
        }
    }

    return CONTINUE;//如果没有达到五子连珠的情况，则返回0
}

void StopGame(int chessBoard[][15]) {
    for(int i = 0; i < BOARD_WEIGHT; i++) {
        for(int j = 0; j < BOARD_HEIGHT; j++) {
            chessBoard[i][j] = NOT_READY;
        }
    }
    ChessBoard::end = true;
}

void PrintJudgeWin(int chessBoard[][15], int row, int cel, int& res)
{
    res = JudgeWin(chessBoard, row, cel);
    if (res == CONTINUE) {
        if(ChessBoard::full) {
            std::cout << "Drawn game" << std::endl;
            StopGame(chessBoard);
        } else {
//            std::cout << "Continue" << std::endl;
        }
    }
    else if (res == WHITE_WIN) {
        std::cout << "White win" << std::endl;
        StopGame(chessBoard);
    }
    else if (res == BLACK_WIN) {
        std::cout << "Black win" << std::endl;
        StopGame(chessBoard);
    }
    DrawRes(res);
}