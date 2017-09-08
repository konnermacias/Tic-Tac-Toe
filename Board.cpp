#include "Board.h"
#include "Game.h"
#include <iostream>
using namespace std;

Board::Board() {}
Board::~Board() {}

void Board::init() 
{
	clear();
}

void Board::clear()
{
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			grid[r][c] = isFREE;
}


void Board::display() const
{
	cout << "  "; // 2 space indent
	for (int c = 0; c < SIZE; c++)
		cout << c << " ";
	cout << endl << " _______" << endl;
	for (int r = 0; r < SIZE; r++)
	{
		cout << r << "|"; // beginning of each row
		for (int c = 0; c < SIZE; c++)
		{
			if (grid[r][c] != isX && grid[r][c] != isO)
				cout << isFREE << "|";
			else
				cout << grid[r][c] << "|";
		}
		cout << endl << " _______" << endl;
	}
}


int Board::checkVictory() const 
{
	int count = 1;
	// checking columns
	for (int r = 0; r < SIZE; r++)
	{
		count = 1;
		for (int c = 0; c < SIZE - 1; c++)
		{
			if ((getVal(r, c) == getVal(r, c + 1)) && (getVal(r, c) != isFREE))
			{
				count++;
				if (count == NEED_IN_A_ROW)
					return WON;
			}
			else 
			{
					count = 1;
			}
		}
	}
	// checking rows
	for (int c = 0; c < SIZE; c++)
	{
		count = 1;
		for (int r = 0; r < SIZE - 1; r++)
		{
			if ((getVal(r, c) == getVal(r + 1, c)) && (getVal(r, c) != isFREE))
			{
				count++;
				if (count == NEED_IN_A_ROW)
					return WON;
			}
			else 
			{
				count = 1;
			}
		}
	}
	// check diag
	if (getVal(0, 0) == getVal(1, 1) && getVal(1, 1) == getVal(2, 2) && getVal(0,0) != isFREE)
		return WON;
	// check anti-diag
	if (getVal(2, 0) == getVal(1, 1) && getVal(1, 1) == getVal(0, 2) && getVal(2, 0) != isFREE)
		return WON;

	// check for tie
	for (int r = 0; r < SIZE; r++) 
	{
		for (int c = 0; c < SIZE; c++) 
		{
			if (grid[r][c] == isFREE)
				return NADA; // not done yet
		}
	}
	return TIE;
}
