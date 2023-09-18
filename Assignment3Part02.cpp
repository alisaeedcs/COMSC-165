//Description: This program is a tic-tac-toe game!
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/17/23
//Status: Complete


#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;

//function prototypes
void displayBoard(char [][COLUMNS]);
void playerTurn(char [][COLUMNS], char);
bool gameOver(char [][COLUMNS]);
bool playerWins(char [][COLUMNS], char);
bool playerCanWin(char [][COLUMNS], char);
void displayWinner(char [][COLUMNS]);

int main() {
	//game board array
	char gameBoard[ROWS][COLUMNS] = { '*', '*', '*',
									 '*', '*', '*',
									 '*', '*', '*' };

	do
	{
		//display game board
		displayBoard(gameBoard);

		//player 1 turn
		playerTurn(gameBoard, 'X');

		//display game board again
		displayBoard(gameBoard);

		//if game not over, player 2 turn
		if (!gameOver(gameBoard))
			playerTurn(gameBoard, 'O');

	} while (!gameOver(gameBoard));

	//display board one last time
	displayBoard(gameBoard);

	//display winner
	displayWinner(gameBoard);

	return 0;
}

//displayBoard function displays content of board
void displayBoard(char board[][COLUMNS])
{
	//display column headings
	cout << "       Columns" << endl;
	cout << "	1 2 3" << endl;;

	//displays rows
	for (int row = 0; row < ROWS; row++)
	{
		//row label
		cout << "Row " << (row + 1) << ":  ";

		//row contents
		for (int col = 0; col < COLUMNS; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}

//playerturn functiuon allows a player to take turn
void playerTurn(char board[][COLUMNS], char symbol) {
	//isAvailable flag is set to true when player sleects location on board that is available
	bool isAvailable = false;

	int row; //row where symbol is inputted
	int col; //col where symbol is inputted

	//prompt location
	cout << "Player " << symbol << "'s turn." << endl;
	cout << "Enter a row and column to place an " << symbol << "." << endl;

	//get and validate location
	while (!isAvailable) {
		//get row
		cout << "Row: ";
		cin >> row;

		//validate row
		while (row < 1 || row > ROWS) {
			cout << "Invalid Row!" << endl;
			cout << "Row: ";
			cin >> row;
		}

		//get column
		cout << "Column: ";
		cin >> col;

		//validate column
		while (col < 1 || col > COLUMNS) {
			cout << "Invalid Column!" << endl;
			cout << "Column: ";
			cout << col;
		}

		//determine whether selected cell available
		if (board[row - 1][col - 1] == '*')
			isAvailable = true;
		else
		{
			cout << "That location is not available. " << "Select another location." << endl;
		}
	}
	//place player symbol on board
	board[row - 1][col - 1] = symbol;
}

//gameOver functiuon returns true if game over, this case when either player has won or tie
bool gameOver(char board[][COLUMNS]) {
	bool status; //status flag

	//if either player has won, gasme over
	if (playerWins(board, 'X') || playerWins(board, 'O'))
		status = true;

	//if player can still win, game not over
	else if (playerCanWin(board, 'X') || playerCanWin(board, 'O'))
		status = false;

	//otherwise tie, game over
	else
		status = true;
	return status;
}

//playerWins function accepts game board and symbols, returns if player has won
bool playerWins(char board[][COLUMNS], char symbol) {
	//status flag, intialized to false
	bool status = false;

	//checks first horizontal row
	if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
		status = true;

	//checks second horizontal row
	if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
		status = true;

	//checks third horizontal row
	if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol)
		status = true;

	//checks first column 
	if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
		status = true;

	//checks second column 
	if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
		status = true;

	//checks third column 
	if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
		status = true;

	//checks diagonal
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
		status = true;

	//if we make it this far, player did not win
	return status;
}

//playerCanWin function returns true if player can still win
bool playerCanWin(char board[][COLUMNS], char symbol) {
	//status flag initialized to false
	bool status = false;

	//checks first horizontal row for possibility
	if ((board[0][0] == symbol || board[0][0] == '*') && (board[0][1] == symbol || board[0][1] == '*') && (board[0][2] == symbol || board[0][2] == '*'))
		status = true;

	//checks second horizontal row for possibility
	if ((board[1][0] == symbol || board[1][0] == '*') && (board[1][1] == symbol || board[1][1] == '*') && (board[1][2] == symbol || board[1][2] == '*'))
		status = true;

	//checks third horizontal row for possibility
	if ((board[2][0] == symbol || board[3][0] == '*') && (board[2][1] == symbol || board[2][1] == '*') && (board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	//checks first column for possibility
	if ((board[0][0] == symbol || board[0][0] == '*') && (board[1][0] == symbol || board[1][0] == '*') && (board[2][0] == symbol || board[2][0] == '*'))
		status = true;

	//checks second column for possibility
	if ((board[0][1] == symbol || board[0][1] == '*') && (board[1][1] == symbol || board[1][1] == '*') && (board[2][1] == symbol || board[2][1] == '*'))
		status = true;

	//checks third column for possibility
	if ((board[0][2] == symbol || board[0][2] == '*') && (board[1][2] == symbol || board[1][2] == '*') && (board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	//checks diagonal for possibility
	if ((board[0][0] == symbol || board[0][0] == '*') && (board[1][1] == symbol || board[1][1] == '*') && (board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	//if we make it this far, player cannot win
	return status;
}

//displayerWinner function displays winner(straightforward)
void displayWinner(char board[][COLUMNS]) {
	if (playerWins(board, 'X'))
		cout << "Player 1 (X) WINS!!!!!" << endl << endl;
	else if (playerWins(board, 'O'))
		cout << "Player 2 (O) WINS!!!!!" << endl << endl;
	else
		cout << "Game Over... It's a TIE!" << endl << endl;
}