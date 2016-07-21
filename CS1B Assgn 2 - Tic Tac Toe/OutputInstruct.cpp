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
 * FUNCTION OutputInstruct
 *_______________________________________________________________________
 * This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	Nothing.
 *
 * POST-CONDITIONS
 * 		This function will return nothing. Just output instructions.
 ************************************************************************/
void OutputInstruct()
{
	/********************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------
	 * WELC - The width size for the welcome to tic tac toe
	 * INST - The width size for all instructions
	 ********************************************************************/
	const short WELC = 42;
	const short INST = 65;

	cout << setw(WELC) << "*********************************" << endl;
	cout << setw(WELC) << "***WELCOME TO TIC TAC TOE GAME***" << endl;
	cout << setw(WELC) << "*********************************";
	cout << endl << endl;

	cout << left;
	cout << setw(INST) << "Here are instructions on how to play:" << endl;
	cout << setw(INST) << "You will be asked to make an selection from the Menu.";
	cout << setw(INST) << endl << "Simply choose an option and follow the prompts.";
	cout << endl << endl;

	cout <<	setw(INST) << "How to make a move:" << endl;
	cout <<	setw(INST) << "Once is your turn, type in the numbers, separated by"
		 << endl;
	cout << setw(INST) << "space indicating where you desire to place your move."
		 << endl;
	cout << setw(INST) << "Enter your play by typing the row number first and";
	cout <<	setw(INST) << endl << "then the column number.";
	cout << endl << endl;

	cout << setw(INST) <<	"Press <enter> to play Tic-Tac-Toe! Good Luck...:)";
	cout << endl;
	cout << right;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
