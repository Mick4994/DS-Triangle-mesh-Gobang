//
// Created by 22843 on 2023/6/19.
//
#include <vector>
#include "../include/ChessBoardUI.h"

#include "../include/JudgeWin.h"

#include "../include/AIChess.h"

// 极大极小搜索算法
int minimax(ChessBoard &board, int depth, int alpha, int beta, bool maximizingPlayer) {
    // 终止条件：达到最大搜索深度或棋盘已满
    if (depth == MAX_DEPTH || board.full) {
        return CONTINUE;
    }

    // 当前局面评估分数
    int score = 0;

    // 最大化搜索
    if (maximizingPlayer) {
        score = MIN_NUM;

        // 遍历棋盘的每个空位置
        for (int i = 0; i < BOARD_WEIGHT; i++) {
            for (int j = 0; j < BOARD_HEIGHT; j++) {
                if (board.Board[i][j] == NONE) {
                    // 在当前位置落子
                    board.Board[i][j] = BLACK_CHESS;
                    // 判断当前局面是否获胜
                    if (JudgeWin(board.Board,i,j) == BLACK_WIN) {
                        score = WIN_SCORE;
                    } else {
                        // 递归进行极大极小搜索
                        score = std::max(score, minimax(board, depth + 1, alpha, beta, false));
                    }

                    // 恢复当前位置的状态
                    board.Board[i][j] = NONE;

                    // 进行剪枝
                    alpha = std::max(alpha, score);
                    if (alpha >= beta) {
                        return score;
                    }
                }
            }
        }
    } else {
        // 最小化搜索
        score = MAX_NUM;

        // 遍历棋盘的每个空位置
        for (int i = 0; i < BOARD_WEIGHT; i++) {
            for (int j = 0; j < BOARD_HEIGHT; j++) {
                if (board.Board[i][j] == NONE) {
                    // 在当前位置落子
                    board.Board[i][j] = WHITE_CHESS;
                    // 判断当前局面是否获胜
                    if (JudgeWin(board.Board,i,j) == BLACK_WIN) {
                        score = -WIN_SCORE;
                    } else {
                        // 递归进行极大极小搜索
                        score = std::min(score, minimax(board, depth + 1, alpha, beta, true));
                    }

                    // 恢复当前位置的状态
                    board.Board[i][j] = NONE;

                    // 进行剪枝
                    beta = std::min(beta, score);
                    if (alpha >= beta) {
                        return score;
                    }
                }
            }
        }
    }

    return score;
}

// AI 下棋
void aiMakeMove(ChessBoard &board, int& bestRow, int& bestCol) {
    int bestScore = MIN_NUM;

    // 遍历棋盘的每个空位置
    for (int i = 0; i < BOARD_WEIGHT; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (board.Board[i][j] == NONE) {
                // 在当前位置落子
                board.Board[i][j] = BLACK_WIN;
                //board.printBoard();
                // 评估当前局面分数
                int score = minimax(board, 0, MIN_NUM, MAX_NUM, false);

                // 恢复当前位置的状态
                board.Board[i][j] = NONE;

                // 更新最佳位置
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    // 在最佳位置落子
    if (board.Board[bestRow][bestCol] == NONE) {
        board.Board[bestRow][bestCol] = WHITE_CHESS;
    }
}