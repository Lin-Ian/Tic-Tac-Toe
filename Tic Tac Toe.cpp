/*
Name: Tic Tac Toe.cpp
Purpose: Tic Tac Toe game game using 2D arrays and user defined functions

Author: Lin.I

Created: 23/12/2020
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 3;
const string EMPTY = "#", P1 = "X", P2 = "O";
const int MAX_ROUNDS = 5;

void make_move(istream & in, string board[BOARD_SIZE][BOARD_SIZE], string player)
{	
	bool move_not_made = true;
	int x_pos = 0, y_pos = 0;

	while (move_not_made)
	{			
		if  (in == cin)
		{
			if (player == P1)
			{
				cout << "Player 1, Enter an x and y location: ";			
			}
			if (player == P2)
			{
				cout << "Player 2, Enter an x and y location: ";
			}
		}
		
		in >> x_pos >> y_pos;
			
		if (x_pos >= 1 && x_pos <= 3 && y_pos >= 1 && y_pos <= 3 &&
			board[y_pos-1][x_pos-1] == EMPTY)
			{
				board[y_pos-1][x_pos-1] = player;
				move_not_made = false;
			}
		}
}
		
bool check_horizontal(string board[BOARD_SIZE][BOARD_SIZE], string player)
{
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		if (board[row][0] == player &&
			board[row][1] == player &&
			board[row][2] == player)
			return true;
	}
	return false;
}

bool check_vertical(string board[BOARD_SIZE][BOARD_SIZE], string player)
{
	for (int col = 0; col < BOARD_SIZE; col++)
	{
		if (board[0][col] == player &&
			board[1][col] == player &&
			board[2][col] == player)
			return true;
	}
	return false;
}

bool check_upward_diagonal(string board[BOARD_SIZE][BOARD_SIZE], string player)
{
	if (board[0][0] == player &&
		board[1][1] == player &&
		board[2][2] == player)
		return true;
	return false;
}

bool check_downward_diagonal(string board[BOARD_SIZE][BOARD_SIZE], string player)
{
	if (board[2][0] == player &&
		board[1][1] == player &&
		board[0][2] == player)
		return true;

	return false;
}

bool check_win(string board[BOARD_SIZE][BOARD_SIZE], string player)
{
	return check_horizontal(board, player) ||
		   check_vertical(board, player) ||
		   check_upward_diagonal(board, player) ||
		   check_downward_diagonal(board, player);
}

void setup_board(string character, string board[BOARD_SIZE][BOARD_SIZE])
{
	for (int row = 0; row < BOARD_SIZE; row++)
		for (int col = 0; col < BOARD_SIZE; col++)
			board[row][col] = character;
}

void output_board(ostream & out, string board[BOARD_SIZE][BOARD_SIZE])
{
	for (int row = 1; row <= BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			out << board[BOARD_SIZE-row][col] << " ";
		}
	out << endl;
	}
}


int main()
{
	string board[BOARD_SIZE][BOARD_SIZE];
	setup_board(EMPTY, board);

	output_board(cout, board);
	cout << endl;
	
	bool game_over = false;
	int round = 0;
	
	while (!game_over)
	{
		make_move(cin, board, P1);
		output_board(cout, board);

		if (check_win(board, P1))
		{
			game_over = true;
			cout << "Player 1 Wins!";
		}

		round++;

		if (round == MAX_ROUNDS)
		{
			game_over = true;
			cout << "Tie Game!";
		}
		cout << endl;
		
		if (!game_over)
		{
			make_move(cin, board, P2);
			output_board(cout, board);
			
			if (check_win(board, P2))
			{
				game_over = true;
				cout << "Player 2 Wins!";
			}
		
			cout << endl;
		}

	}

	return EXIT_SUCCESS;
}

