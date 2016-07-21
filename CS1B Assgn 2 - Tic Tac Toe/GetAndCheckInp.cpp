/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #2    : Multi-Dimensional Arrays - TIC TAC TOE
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 2/29/16
 ************************************************************************/

#include "tictacheader.h"

 /***********************************************************************
 *
 * FUNCTION GetAndCheckInp
 *_______________________________________________________________________
 * This function will get and check the users input. It will prompt the user
* by name, and then check for unexpected input, outside boundaries input,
* and if the spot chosen to play is already taken.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	boardAr[][NUM_COLS] - It contains the board for game
 *	token				- Token assign to players
 *	playerX				- First player
 *	playerO				- Second player
 *
 * POST-CONDITIONS
 * 		This function will return nothing, it will just assign a token
 * 		into the board.
 ************************************************************************/
void GetAndCheckInp(char boardAr[][NUM_COLS], //IN  - Board game
				    char token, 			  //IN  - Players token
					string playerX,			  //OUT - First player
				    string playerO)			  //OUT - Second player
{
	bool valid; //CALC     - Users move
	short row;  //IN & OUT - Row in the board
	short col;	//IN & OUT - Column in the board

	valid = false;

	//ERROR CHECKING - For wrong input and if spot is already taken
	do
	{
		if(token == 'X')
		{
			cout << playerX;
		}
		else
		{
			cout << playerO;
		}

		//INPUT - User will input the row and column to play
		cout << "\'s turn! What is your play?: ";
		cin  >> row >> col;

		row--;
		col--;

		//IF-STATEMENT - If input is outside the row size and column size
		//				 it will ask the user to input again. As well if
		//				 the spot is already taken.
		if(row > NUM_ROWS - 1 || row < 0)
		{
			cout << "Invalid row - Please try again!\n\n";
		}
		else if(col > NUM_COLS - 1 || col < 0)
		{
			cout << "Invalid column - Please try again!\n\n";
		}
		else if(!isspace(boardAr[row][col]))
		{
			cout << "That spot is taken already - try again!\n\n";
		}
		else
		{
			valid = true;
		}
	}while(!valid);

	boardAr[row][col] = token; //Assign token to chosen spot
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
