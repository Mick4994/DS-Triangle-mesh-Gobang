//
// Created by 29539 on 2023/6/19.
//
#include "../include/BoardEvaluate.h"
#include <cmath>

/*
五元组：棋盘上任意连续的五个点。
对棋盘的估分方法为：把棋盘上所有五元组的估分加起来
可调用函数：int evaluate(int chessBoard[][15])，
	调用该函数即可返回对整个棋盘的估分（传入的参数为棋盘的二维数组）。
*/
#define WHITE 1
#define BLACK 2

//估分数组(预先算好五元组所有组合情况)
int score[32] = { 0,1,1,10,1,10,10,100,1,10,
                  10,100,10,100,100,1000,1,10,10,100,10,100,100,
                  1000,10,100,100,1000,100,1000,1000,1000000 };

int getScore(int s[6], int status) {//获得五元组的估分，辅助棋盘估分
    //对五元组解码，运用到了二叉树的性质5
    int count = 1;//相当于根节点编号为1
    int t = 5;//最大循环次数
    int i = s[5];//五元组的起始位置
    while (t--) {
        if (s[i] == 0)
            count = count * 2;//相当于遍历左孩子
        else if(s[i] == status)
            count = count * 2 + 1;//相当于遍历右孩子
        else {
            count = 32;
            break;
        }
        i = (i + 1) % 5;
    }
    if (count == 46 && status == BLACK) return 2000;//处理特殊情况形如“0BBB0”的情况
    return score[count - 32];
}

//以下3个方法为：根据线的下标返回该线的起始坐标
void initPointX(int &row_x, int &cel_x, int lineIndex) {
    row_x = abs(7 - lineIndex);
    cel_x = lineIndex;
}
void initPointY(int &row_y, int &cel_y, int lineIndex) {
    row_y = lineIndex <= 7 ? lineIndex : lineIndex * 2 - 7;
    cel_y = 14 < 7 + lineIndex ? 14 : 7 + lineIndex;
}
void initPointZ(int &row_z, int &cel_z, int lineIndex) {
    row_z = lineIndex <= 7 ? lineIndex : lineIndex * 2 - 7;
    cel_z = 0 > 7 - lineIndex ? 0 : 7 - lineIndex;
}


int evaluate(int chessBoard[][15]) {//对当前整个棋盘状态的估分函数
    //运用循环队列的思想存储五元组(棋盘上任意连续的五个点)
    int s_x[6], s_y[6], s_z[6];//用于存储五元组，最后一个元素(s[5])存储起始元素的下标
    int row_x, cel_x, row_y, cel_y, row_z, cel_z;
    int lineLength;
    int totalScore = 0;
    for (int i = 0; i < 15; i++) {
        lineLength = 15 - abs(7 - i);//初始化长度
        //根据第i条线来初始化该线的起始坐标
        initPointX(row_x, cel_x, i);
        initPointY(row_y, cel_y, i);
        initPointZ(row_z, cel_z, i);
        s_x[5] = s_y[5] = s_z[5] = 0;//开始时起始元素的下标为0
        int j = 0;
        for (j = 0; j < 5; j++) {//前五个元素入队列（数组）
            s_x[j] = chessBoard[row_x][cel_x];
            row_x += 2;
            s_y[j] = chessBoard[row_y++][cel_y--];//row_y++; cel_y--;
            s_z[j] = chessBoard[row_z++][cel_z++];//row_z++;cel_z++;
        }
        totalScore += getScore(s_x, WHITE) - getScore(s_x, BLACK);
        totalScore += getScore(s_y, WHITE) - getScore(s_y, BLACK);
        totalScore += getScore(s_z, WHITE) - getScore(s_z, BLACK);
        for (j = 5; j < lineLength; j++) {
            //对于x轴线上的五元组
            s_x[s_x[5]] = chessBoard[row_x][cel_x];
            row_x += 2;
            s_x[5] = (s_x[5] + 1) % 5;
            totalScore += getScore(s_x, WHITE) - getScore(s_x, BLACK);
            //对于y轴线上的五元组
            s_y[s_y[5]] = chessBoard[row_y++][cel_y--];//row_y++; cel_y--;
            s_y[5] = (s_y[5] + 1) % 5;
            totalScore += getScore(s_y, WHITE) - getScore(s_y, BLACK);
            //对于z轴线上的五元组
            s_z[s_z[5]] = chessBoard[row_z++][cel_z++];//row_z++;cel_z++;
            s_z[5] = (s_z[5] + 1) % 5;
            totalScore += getScore(s_z, WHITE) - getScore(s_z, BLACK);
        }
    }
    return totalScore;
}