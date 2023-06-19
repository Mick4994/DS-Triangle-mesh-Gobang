//
// Created by 22843 on 2023/6/19.
//

#include "../include/ChessBoardInit.h"


#ifndef EASYX_AICHESS_H
    #define EASYX_AICHESS_H
    #define MAX_NUM 999999
    #define MIN_NUM -999999
    #define MAX_DEPTH 4
    #define WIN_SCORE 100000
    int minimax(ChessBoard &board, int depth, int alpha, int beta, bool maximizingPlayer);
    void aiMakeMove(ChessBoard &board, int& bestRow, int& bestCol);
#endif //EASYX_AICHESS_H
