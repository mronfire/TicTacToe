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
 * FUNCTION GetPlayers
 *_______________________________________________________________________
 * This function prompts the user and gets the input for the players’ names.
 * playerX will always contain the name of the player that is using the X
 * 		   token.
 * playerO will always contain the name of the player that is using the O
 * 	       token.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	Nothing.
 *
 * POST-CONDITIONS
 * 		This function will return nothing. It will just assign names to the
 * 		variables passed by reference.
 ************************************************************************/
void GetPlayers(string& playerX, // OUT - player X’s name
			    string& playerO) // OUT - player O’x name
{
	char option;	//CALC & OUT - Option to choose a token
	char choice;    //CALC & OUT - Token chosen by user
	string temp;	//CALC 		 - Variable holding temporary token
	bool valid;		//CALC       - Correct input by user
	bool wrong;		//CALC		 - Wrong input by user

	cout << endl;
	cout << "Enter the name of player #1: ";
	getline(cin, playerX);

	cout << "Enter the name of player #2: ";
	getline(cin, playerO);

	//DO-WHILE - Error check for wrong input
	do
	{
		cout << "\nWould you like to choose your token (Yes or No)? ";
		cin.get(option);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		option = toupper(option);

		//IF-ELSE - This statement will allow the user to choose a token of
		//		    choice or it will assign a token to each one if the user
		//		    doesn't want to choose a token
		if(option == 'Y')
		{
			cout << "\nPlease choose your token(X or O):\n";

			    //DO-WHILE - Error check for wrong input
				do
				{
				   cout << playerX << ", what token would you like? ";
				   cin.get(choice);
				   cin.ignore(numeric_limits<streamsize>::max(), '\n');

				   choice  = toupper(choice);

				   //If-STATEMENT - If not X or O it will be invalid input
				   valid = choice == 'X' || choice == 'O';
				   if(!valid)
				   {
					   cout << "\nInvalid input. Please choose X or O!\n";
				   }
				}
				while(!valid);

				//IF-STATEMENT - If first player chooses X, then it will
				//				 assign O to second player. Else, it will
				//				 swap players to chosen token
			   if(choice == 'X')
			   {
				   cout << playerX << " you are the X's!";
				   cout << endl;

				   cout << playerO << " you are the O's!"
						<< endl;
			   }
			   else
			   {
				   temp = playerX;
				   playerX = playerO;
				   playerO = temp;
				   cout << playerX << " you are the X's!"
						<< endl;

				   cout << playerO << " you are the O's!"
						<< endl;
			   }

		}else if(option == 'N')
		{
			cout << playerX << " you are the X's!" << endl;
			cout << playerO << " you are the O's!" << endl;
		}

		//IF-STATEMENT - If input is not Y or N, it will be invalid input
		wrong = option != 'Y' && option != 'N';
		if(wrong)
		{
			cout << "\n***Error, wrong input!!!***\n";
		}
	}while(wrong);

}




