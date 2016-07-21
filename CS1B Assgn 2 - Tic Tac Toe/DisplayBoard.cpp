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
 * FUNCTION DisplayBoard
 *_______________________________________________________________________
 * This function outputs the tic tac toe board including the tokens
 * played in the proper format.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	boardAr[][NUM_COLS] - It has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will return nothing, but output the board for game
 ************************************************************************/
void DisplayBoard(const char boardAr[][NUM_COLS])//OUT - Board game
{
	int row;	//IN & CALC - Row for board
	int column; //IN & CALC - Column for board

	/*******************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------
	 * COL1 - Width size for the first column
	 * ROW2 - Width size for second row
	 * DASH - Width size for the dash line
	 *******************************************************************/
	const short COL1 = 10;
	const short ROW2 = 14;
	const short DASH = 32;

	cout << setw(COL1) << "1" << setw(COL1 - 2)
		 << "2" << setw(COL1 - 1) << "3\n";

	//FOR-LOOP - This loop will go thru each row and output the boxes
	//			 indicating each box number
	for (row = 0; row < NUM_COLS; row++)
	{
		cout << setw(ROW2 - 7) << "[" << row+1 << "][1] | " << "[" << row+1;
		cout << "][2] | " << "["  << row+1 << "][3]" << endl;
		cout << setw(ROW2) << "|" << setw(ROW2 - 5) << "|" << endl;

		//FOR-LOOP - This loop will output the row number to the left, and
		//			 then assign the space to place token, and output lines
		//			 to divide each respective box
		for (column = 0; column < NUM_COLS; column++)
		{
			switch(column)
			{
			case 0: cout << row + 1 << setw(9) << boardAr[row][column];
			 	 	cout << setw(4) << "|";
			 	 	break;
			case 1: cout << setw(4) << boardAr[row][column];
			 	 	cout << setw(5) << "|";
			 	 	break;
			case 2: cout << setw(4) << boardAr[row][column] << endl;
					break;
			default: cout <<"ERROR!\n\n";
			}
		}
		cout << setw(ROW2)<< "|" << setw(COL1) << "|\n";

		//IF-STATEMENT - While row is under 1 it will output dash lines
		//				 dividing the rows in board
		if (row != 2)
		{
			cout << setw(DASH) << "--------------------------\n";
		}
	}
	cout << endl << endl;

}

