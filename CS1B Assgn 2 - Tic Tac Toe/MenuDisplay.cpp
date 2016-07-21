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
 * FUNCTION MenuDisplay
 *_______________________________________________________________________
 * This function will display the menu for the users with options to choose
* from. There are no input or output parameters to this function as it only
* displays the menu for the user.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *
 *
 * POST-CONDITIONS
 * 		This function will return the user input from menu.
 ************************************************************************/
short MenuDisplay()
{
	short userInput;  //OUT  - user input
	bool menuInvalid; //CALC - invalid input

	//ERROR CHECKING FOR INPUT
		do
		{
			cout << "\nMAIN MENU\n";
			cout << "0 - Exit\n"
				    "1 - Set Player Names\n"
				    "2 - Play in Two Player Mode\n"
					"3 - Play in One Player Mode\n";
			cout << "Enter your selection: ";
			cin  >> userInput;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			menuInvalid = userInput != EXIT       &&
						  userInput != PLAYERS    &&
						  userInput != TWO_PLAYER &&
						  userInput != ONE_PLAYER;

			if(menuInvalid)
			{
				cout << "\n***Invalid Input. Please enter 0, 1, 2 or 3 to"
						" move on!***\n";
			}
		}while(menuInvalid);

	return userInput;
}
