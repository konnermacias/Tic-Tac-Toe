#include "Player.h"
#include <vector>

void Player::init()
{
	aiPlyr = isO; 
	otherPlyr = isX;
}

void Player::makeMove(Board& board) 
{
	Player::init();
	AI_Move bestMove = getBestMove(board, aiPlyr);
	board.setVal(bestMove.r, bestMove.c, aiPlyr);
}

Player::Player() {}
Player::~Player() {}

AI_Move Player::getBestMove(Board& board, int plyr) // minimax recursive algorithm
{
	// base case conditions
	int result = board.checkVictory(); 
	if (result == WON && plyr == aiPlyr)
		return AI_Move(-10);
	else if (result == WON && plyr == otherPlyr)
		return AI_Move(10);
	else if (result == TIE)
		return AI_Move(0);

	std::vector<AI_Move> moves; // each move has a coordinate and score

	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (board.getVal(r, c) == isFREE)
			{
				AI_Move move;
				move.r = r;
				move.c = c;
				board.setVal(r, c, plyr); // temporarily marking the move
				if (plyr == aiPlyr)
					move.score = getBestMove(board, otherPlyr).score;
				else
					move.score = getBestMove(board, aiPlyr).score;
				moves.push_back(move);
				board.setVal(r, c, isFREE); // making it free again
			}
		}
	}

	int bestMove = 0;
	if (plyr == aiPlyr) // maximize ai's result
	{
		int bestScore = -1000000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else { // minimize human's result
		int bestScore = 10000000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	return moves[bestMove]; // return the best move
}
