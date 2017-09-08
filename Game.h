#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Board.h"
#include "Player.h"

class Game {
public:
	Game();
	~Game();
	void play();
private:
	void changePlyr();
	void humanMove();
	void aiMove();
	void whatHappened(int result);

	Board board;
	int currentPlyr;
	int humanPlyr = isX;
	int pcPlyr = isO;
	Player ai;
};


#endif // !GAME_INCLUDED
