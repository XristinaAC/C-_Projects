#include <iostream>
#include "TicTacToe.h"

bool choosePosition(int& row, int& col, char players[], int turn)
{
	std::cout << "Turn: player " << players[turn] << ".\n";

	std::cout << "Give the row position you want to play(0-2).\n";
	std::cin >> row;
	std::cout << "Give the column position you want to play(0-2).\n";
	std::cin >> col;

	std::cin.clear();
	std::cin.ignore(256, '\n');

	if ((row > 2 || row < 0) || (col > 2 || col < 0))
	{
		std::cout << "The position you gave is wrong, try again.\n\n";
		return false;
	}

	return true;
}

void winGame(TicTacToe game, char players[], int turn)
{
	game.printGameBoard();
	std::cout << "The winner is: " << players[turn] << ".\n";
}

void continueRound(int& plays, bool win, TicTacToe game, int& turn)
{
	plays--;
	std::cout << "\nplays: " << plays << "\n";

	if (plays == 0 && win == false)
	{
		game.printGameBoard();
		std::cout << "The game ended in a draw!!\n";
	}
	else
	{
		turn++;
		if (turn == 2)
		{
			turn = 0;
		}
	}
}

void ticTacToeGame()
{
	TicTacToe game;

	char players[2] = { 'X', 'O' };
	int turn = 0, plays = N * N;
	int  row = -1, col = -1;
	bool win = false;

	while (!win && plays > 0)
	{
		game.printGameBoard();

		if (!choosePosition(row, col, players, turn))
		{
			continue;
		}

		win = game.play(row, col, players[turn]);
		if (win)
		{
			winGame(game, players, turn);
		}
		else
		{
			continueRound(plays, win, game, turn);
		}
	}
}