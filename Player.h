#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED
#include "Board.h"

struct AI_Move 
{
	AI_Move() {};
	AI_Move(int Score) : score(Score) {};
	int r;
	int c;
	int score;
};

// AI
class Player {
public:
	void init();
	void makeMove(Board& board);
	Player();
	~Player();
private:
	AI_Move getBestMove(Board& board, int plyr);
	int aiPlyr;
	int otherPlyr;
};
#endif // !PLAYER_INCLUDED

