#include <iostream>
#include "TicTacToe.h"

 TicTacToe:: TicTacToe()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			GameBoard[i][j] = '-';
		}
	}
}

inline char  TicTacToe::getGridPosition(int posX, int posY)
{
	return GameBoard[posX][posY];
}

inline void  TicTacToe::setGridPosition(int posX, int posY, char pi)
{
	GameBoard[posX][posY] = pi;
}
                                   
bool TicTacToe::checkRowsColumn(int i, char playerInput)
{
	bool win = true;
	int j = 0;

	while (j < 3)
	{
		if (GameBoard[i][j] != playerInput)
		{
			win = false;
			j = 0;
			break;
		}
		
		j++;
	}

	win = true;

	while (j < 3)
	{
		if (GameBoard[j][i] != playerInput)
		{
			win = false;
			break;
		}

		j++;
	}

	return win;
}

bool TicTacToe::checkDiagonal(int i, int j, char playerInput)
{
	if (GameBoard[i][j] != playerInput)
	{
		return false;
	}

	return true;
}

bool  TicTacToe::checkWin(char playerInput)
{
	int diagonal = 0, r_diagonal = 0;

	for (int i = 0; i < N; i++)
	{
		if (checkRowsColumn(i, playerInput))
		{
			return true;
		}

		if (checkDiagonal(i, i, playerInput))
		{
			diagonal++;
		}

		//Cheching secondary diagonal
		if (checkDiagonal(i, (N - 1) - i, playerInput))
		{
			r_diagonal++;
		}
	}

	if (diagonal == 3 || r_diagonal == 3)
	{
		return true;
	}

	return false;
}

bool  TicTacToe::play(int posX, int posY, char playerInput)
{
	if (GameBoard[posX][posY] == '-')
	{
		GameBoard[posX][posY] = playerInput;
		return checkWin(playerInput);
	}
	else
	{
		std::cout << "The position [" << posX << "] , [" << posY << "] is already filled.\n";
		return false;
	}
}

void  TicTacToe::printGameBoard()
{
	std::cout << "The current Game Board is: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << GameBoard[i][j] << " ";
		}

		std::cout << "\n";
	}
}