#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;

Game::Game() {}
Game::~Game() {}

void Game::changePlyr()
{
	if (currentPlyr == humanPlyr)
		currentPlyr = pcPlyr;
	else
		currentPlyr = humanPlyr;
}

void Game::humanMove()
{
	bool validMove = false;
	while (!validMove)
	{
		int r, c;
		printf("Enter R: ");
		std::cin >> r;
		printf("Enter C: ");
		std::cin >> c;

		if (board.getVal(r, c) == isFREE)
		{
			board.setVal(r, c, humanPlyr);
			validMove = true;
		}
		else
		{
			printf("Invalid Location \n");
		}
	}
}

void Game::aiMove() 
{
	ai.makeMove(board);
}

void Game::whatHappened(int result)
{
	if (result == WON)
	{
		if (currentPlyr == humanPlyr)
			printf("Congrats! You WON!!");
		else
			printf("You lost! Try again if you dare!");
	}
	else 
	{
		printf("Cat's Game");
	}
}

void Game::play()
{
	board.init(); // initializing a board and beginning play
	bool quit = false;
	currentPlyr = humanPlyr;
	while (!quit)
	{
		board.display();
		if (currentPlyr == humanPlyr) 
			humanMove();
		else
			aiMove();

		int result = board.checkVictory(); 
		if (result == WON || result == TIE) // end of game
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
			board.display();
			whatHappened(result); 

			bool validInput = false;
			while (!validInput)
			{
				cout << endl << "press (q) to quit or (t) to try again: ";
				char input;
				cin >> input;
				if (input == 'q')
				{
					quit = true;
					validInput = true;
				}
				else if (input == 't')
				{
					board.init();
					currentPlyr = humanPlyr;
					validInput = true;
				}
				else 
				{
					validInput = false;
				}
			}
		}
		else // otherwise, keeping changing whose turn it is
		{ 
			changePlyr();
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
	}
}