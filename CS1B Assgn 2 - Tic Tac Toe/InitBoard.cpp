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
 * FUNCTION InitBoard
 *_______________________________________________________________________
 * This function initializes each spot in the board to a space ' '.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	boardAr[][NUM_COLS] - It has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will return nothing. It will initialize the board with
 * 		spaces.
 ************************************************************************/
void InitBoard(char boardAr[][NUM_COLS])
{
	int row; //CALC - Row for board
	int col; //CALC - Column for board

	//FOR-LOOP - It will run thru every row and column and initialze with
	//			 spaces
	for(row = 0; row < NUM_ROWS; row++)
	{
		for(col = 0; col < NUM_COLS; col++)
		{
			boardAr[row][col] = ' ';
		}
	}

}
