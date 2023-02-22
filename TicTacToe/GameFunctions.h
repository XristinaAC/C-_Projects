#pragma once

bool choosePosition(int& row, int& col, char players[], int turn);
void winGame(TicTacToe game, char players[], int turn);
void continueRound(int& plays, bool win, TicTacToe game, int& turn);
void ticTacToeGame();