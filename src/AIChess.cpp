//
// Created by 22843 on 2023/6/19.
//
#include "../include/ChessBoardInit.h"
#include "../include/AIChess.h"
#include "../include/JudgeWin.h"
#include "vector"

using namespace std;
const int MAX_DEPTH = 4;
const int WIN_SCORE = 100000;
// 极大极小搜索算法
int minimax(ChessBoard &board, int depth, int alpha, int beta, bool maximizingPlayer)
{
    // 终止条件：达到最大搜索深度或棋盘已满
    if (depth == MAX_DEPTH || board.full)
    {
        return 0;
    }

    // 当前局面评估分数
    int score = 0;

    // 最大化搜索
    if (maximizingPlayer)
    {
        score = -999999;

        // 遍历棋盘的每个空位置
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (board.Board[i][j] == 0)
                {
                    // 在当前位置落子
                    board.Board[i][j] = 2;
                    // 判断当前局面是否获胜
                    if (JudgeWin(board.Board,i,j) == 2)
                    {
                        score = WIN_SCORE;
                    }
                    else
                    {
                        // 递归进行极大极小搜索
                        score = max(score, minimax(board, depth + 1, alpha, beta, false));
                    }

                    // 恢复当前位置的状态
                    board.Board[i][j] = 0;

                    // 进行剪枝
                    alpha = max(alpha, score);
                    if (alpha >= beta)
                    {
                        return score;
                    }
                }
            }
        }
    }
        // 最小化搜索
    else
    {
        score = 999999;

        // 遍历棋盘的每个空位置
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (board.Board[i][j] == 0)
                {
                    // 在当前位置落子
                    board.Board[i][j] = 1;
                    // 判断当前局面是否获胜
                    if (JudgeWin(board.Board,i,j) == 2)
                    {
                        score = -WIN_SCORE;
                    }
                    else
                    {
                        // 递归进行极大极小搜索
                        score = min(score, minimax(board, depth + 1, alpha, beta, true));
                    }

                    // 恢复当前位置的状态
                    board.Board[i][j] = 0;

                    // 进行剪枝
                    beta = min(beta, score);
                    if (alpha >= beta)
                    {
                        return score;
                    }
                }
            }
        }
    }

    return score;
}

// AI 下棋
void aiMakeMove(ChessBoard &board)
{
    int bestScore = -999999;
    int bestRow = -1;
    int bestCol = -1;

    // 遍历棋盘的每个空位置
    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board.Board[i][j] == 0)
            {
                // 在当前位置落子
                board.Board[i][j] = 1;
                //board.printBoard();
                // 评估当前局面分数
                int score = minimax(board, 0, -999999, 999999, false);

                // 恢复当前位置的状态
                board.Board[i][j] = 0;

                // 更新最佳位置
                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    // 在最佳位置落子
    board.Board[bestRow][bestCol] = 1;
}
