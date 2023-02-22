#pragma once

#define N 3

class TicTacToe
{
	char GameBoard[N][N];

public:
	TicTacToe();

	bool checkRowsColumn(int i, char playerInput);
	bool checkDiagonal(int i, int j, char playerInput);
	bool checkWin(char playerInput);
	bool play(int posX, int posY, char playerInput);

	inline char getGridPosition(int posX, int posY);
	inline void setGridPosition(int posX, int posY, char pi);

	void printGameBoard();
};