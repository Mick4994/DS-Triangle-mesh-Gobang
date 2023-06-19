//
// Created by 29539 on 2023/6/19.
//

//#ifndef EASYX_JUDGEWIN_H
//    #define EASYX_JUDGEWIN_H
#pragma once
//#include <iostream>
#include <cmath>
#include "../include/AIChess.h"
/*
五元组：棋盘上任意连续的五个点。
对棋盘的估分方法为：把棋盘上所有五元组的估分加起来
可调用函数：int evaluate(int chessBoard[][15])，
	调用该函数即可返回对整个棋盘的估分（传入的参数为棋盘的二维数组）。
*/

    //估分数组(预先算好五元组所有组合情况)
    extern int score[32];
    int getScore(int s[6], int status); //获得五元组的估分，辅助棋盘估分

    //以下3个方法为：根据线的下标返回该线的起始坐标
    void initPointX(int &row_x, int &cel_x, int lineIndex);
    void initPointY(int &row_y, int &cel_y, int lineIndex);
    void initPointZ(int &row_z, int &cel_z, int lineIndex);

    int evaluate(int chessBoard[][15]); //对当前整个棋盘状态的估分函数

//#endif //EASYX_JUDGEWIN_H