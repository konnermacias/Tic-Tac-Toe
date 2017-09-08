#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

class Game;

const char isFREE = ' ';
const char isX = 'X';
const char isO = 'O';

const int NADA = 0; // nothing happened
const int TIE = -1;
const int WON = 10;
const int SIZE = 3;
const int NEED_IN_A_ROW = 3;

class Board {
public:
	Board();
	~Board();
	void init();
	void clear();
	void display() const;
	int checkVictory() const;

	void setVal(int r, int c, char cellState) 
	{
		grid[r][c] = cellState;
	}

	char getVal(int r, int c) const 
	{
		return grid[r][c];
	}

private:
	char grid[3][3];
};
#endif // !BOARD_INCLUDED

