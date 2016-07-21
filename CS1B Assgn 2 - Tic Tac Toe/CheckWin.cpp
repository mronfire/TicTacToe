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
 * FUNCTION CheckWin
 *_______________________________________________________________________
 * This function checks to see if either player has run. Once it is
* possible for a win condition to exist, this should run after each a
* player makes a play.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	boardAr[][NUM_COLS] - The board with all plays made
 *
 * POST-CONDITIONS
 * 		This function will return the character value of the player that
* 		won or a value that indicates a tie.
 ************************************************************************/
char CheckWin(const char boardAr[][NUM_COLS]) //IN - The game board
{
	char  win;		//CALC & OUT - Variable holding the win in board
	short row;		//OUT 		 - The row in the board
	short col;		//OUT		 - The column in the board

	win = ' ';

	//Checks for a winner in the columns
	for(col = 0; col < NUM_COLS; col++)
	{
		//IF-STATEMENT - If column is all white space, ignore it
		if(win == ' ')
		{
			//IF-STATEMENT - If all three boxes in the column match, thats
			//				 the winner
			if(boardAr[0][col] == boardAr[1][col] &&
			   boardAr[2][col] == boardAr[1][col])
			{
				win = boardAr[0][col];
			}
		}
	}

	//checks for a winner in the rows
	for(row = 0; row < NUM_ROWS; row++)
	{
		//IF-STATEMENT - If row is all white space, ignore it
		if(win == ' ')
		{
			//IF-STATEMENT - If all three boxes in the row match, thats the
			//				 winner
			if(boardAr[row][0] == boardAr[row][1] &&
					boardAr[row][1] == boardAr[row][2])
			{
				win = boardAr[row][0];

			}
		}
	}

	//checks for a winner in diagonal ways
	if((boardAr[0][0] == boardAr[1][1] && boardAr[1][1] == boardAr[2][2]) ||
	   (boardAr[0][2] == boardAr[1][1] && boardAr[1][1] == boardAr[2][0]))
	{
		win = boardAr[1][1];
	}

	return win;
}

