/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #2    : Multi-Dimensional Arrays - TIC TAC TOE
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 2/29/16
 ************************************************************************/

#include "tictacheader.h"

/*************************************************************************
 * Multi-Dimensional Arrays - TIC TAC TOE
 * _______________________________________________________________________
 * This program will allow the users to play a classic game called Tic Tac
 * Toe with other users or against the computer. It will allow the user
 * to input the player names, and the option to choose the tokens, if the
 * user doesn't want to choose tokens, the program will assign tokens to
 * each player. Then the program will provide a menu for the user to either
 * play against another user or against the computer. After each game, the
 * program will output the game winner and allow the user to play again.
 * _______________________________________________________________________
 *  INPUT:
 *	playerX - First player in the game
 *	playerO - Second player in the game
 *	boardAr - The array for the board game
 *
 * 	OUTPUT:
 *	whoWins - The winner of the game
 ************************************************************************/
int main()
{
	/********************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------
	 * MIN_PLAYS - The minimum plays needed for a possible win(5 total moves)
	 * MAX_PLAYS - The maximum plays for one game(9 total moves)
	 ********************************************************************/
	const short MIN_PLAYS = 5;
	const short MAX_PLAYS = 9;

	char   boardAr[NUM_ROWS][NUM_COLS]; //IN & CALC& OUT - Board game
	char   whoWins;						//CALC & OUT     - Game winner
	char   token;						//CALC			 - Player token
	char   playAgain;					//CALC			 - Reset game
	string playerX;						//IN & OUT		 - First player
	string playerO;						//IN & OUT		 - Second player
	short  selection;					//CALC			 - Menu selection
	bool   invalid;						//CALC  		 - Invalid input
	bool   keepPlaying;					//CALC			 - Continue playing
	short  playCount;					//CALC			 - Moves played
	short  comPlay;						//CALC           - Computer turns

	playerX = "Player 1"; //Default name for playerX
	playerO = "Player 2"; //Default name for playerO

	//PrintHeader - This function will output the Class Heading
	cout << PrintHeader("Tic Tac Toe", 'A', 2);

	//OutputInstruct - It will display instructions for the game
	OutputInstruct();

	//MenuDisplay - This function will display the menu for the user
	selection = MenuDisplay();

	//WHILE-LOOP - This loop will run until the user exits the program
	while(selection != EXIT)
	{
		//IF-STATEMENT - It will execute part of code according to what the
		//				 user chooses to do
		if(selection == PLAYERS)
		{
			//GetPlayers - This function will get the player names
			GetPlayers(playerX, playerO);
		}
		else if(selection == TWO_PLAYER)
		{
			keepPlaying = true;//This will stay true until user decides not
							   //to play anymore

			//WHILE-LOOP - This loop will run as long as the user wants to
			//			   play more games. When the user decides not to play
			//			   another game it will exit the loop
			while(keepPlaying == true)
			{
				token   = 'X';
				whoWins = ' ';
				playCount = 0;

				//InitBoard - It will initialize the board with spaces
				InitBoard(boardAr);

				cout << "Get ready to play...\n";

				//DO-WHILE-LOOP - It will run until there is a winner
				do
				{
					system("cls");//Clear screen

					//DisplayBoard - This function will display the board
					DisplayBoard(boardAr);

					//GetAndCheckInput - Thie will get and check users input
					GetAndCheckInp(boardAr, token, playerX, playerO);

					playCount++;

					//IF-STATMENT - It will check the winner after 5 moves
					if(playCount >= MIN_PLAYS)
					{
						//CheckWin - This will check for a winner
						whoWins = CheckWin(boardAr);
					}
					//SwitchToken - This will switch tokens for players
					token = SwitchToken(token);

				}while(whoWins == ' ' && playCount < MAX_PLAYS);

				system("cls");//Clear screen

				//DisplayBoard - This function will display the board
				DisplayBoard(boardAr);

				//OutputWinner - This will output the winner for the game
				OutputWinner(whoWins, playerX, playerO);

				//DO-WHILE-LOOP - Error checking input
				do
				{
					cout << endl;
					cout << "Do you want to play again(Y or N)? ";
					cin.get(playAgain);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					playAgain = toupper(playAgain);

					invalid = playAgain != 'Y' && playAgain != 'N';

					if(invalid)
					{
						cout << "\n***Invalid input. Try again!***\n";
					}

				}while(invalid);

				//IF-STATEMENT - It will return to main menu if user decides
				//				 to not play another game
				if(playAgain == 'N')
				{
					keepPlaying = false;
				}
			}
		}
		else if(selection == ONE_PLAYER)
		{
			srand(time(NULL));//Generates random moves

			keepPlaying = true;//This will stay true until user decides not
			   	   	   	   	   //to play anymore

			//WHILE-LOOP - This loop will run as long as the user wants to
			//			   play more games. When the user decides not to play
			//			   another game it will exit the loop
			while(keepPlaying == true)
			{
				token     = 'X';
				whoWins   = ' ';
				playCount = 0;
				comPlay   = 1;

				//InitBoard - It will initialize the board with spaces
				InitBoard(boardAr);

				cout << "Get ready to play...\n";

				//DO-WHILE-LOOP - It will run until there is a winner
				do
				{
					system("cls");//Clear screen

					//DisplayBoard - This function will display the board
					DisplayBoard(boardAr);

					//GetAndCheckInput - Thie will get and check users input
					GetAndCheckInp(boardAr, token, playerX, playerO);

					playCount++;

					//IF-STATMENT - It will check the winner after 5 moves
					if(playCount >= MIN_PLAYS)
					{
						//CheckWin - This will check for a winner
						whoWins = CheckWin(boardAr);
					}

					system("cls");
					//DisplayBoard - This function will display the board
					DisplayBoard(boardAr);

					//IF-STATEMENT - If user won the game there is no need
					//				 to check for computer play
					if(whoWins != 'X' && whoWins != 'O' && playCount < MAX_PLAYS)
					{
						//SwitchToken - This will switch tokens for players
						token = SwitchToken(token);

						//GetComputerPlay - This will get a computer play
						GetComputerPlay(boardAr, token, comPlay);

						comPlay++;

						playCount++;

						//IF-STATMENT - It will check the winner after 5 moves
						if(playCount >= MIN_PLAYS)
						{
							//CheckWin - This will check for a winner
							whoWins = CheckWin(boardAr);
						}
						//SwitchToken - This will switch tokens for players
						token = SwitchToken(token);
				    }

				}while(whoWins == ' ' && playCount < MAX_PLAYS);

				system("cls");//Clear screen

				//DisplayBoard - This function will display the board
				DisplayBoard(boardAr);

				//OutputWinner - This will output the winner for the game
				OutputWinner(whoWins, playerX, playerO);

				//DO-WHILE-LOOP - Error checking input
				do
				{
					cout << endl;
					cout << "Do you want to play again(Y or N)? ";
					cin.get(playAgain);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					playAgain = toupper(playAgain);

					invalid = playAgain != 'Y' && playAgain != 'N';

					if(invalid)
					{
						cout << "\n***Invalid input. Try again!***\n";
					}

				}while(invalid);

				//IF-STATEMENT - It will return to main menu if user decides
				//				 to not play another game
				if(playAgain == 'N')
				{
					keepPlaying = false;
				}
			}
		}//END IF-ELSE-IF

		//MenuDisplay - This function will display the menu for the user
		selection = MenuDisplay();

	}//END WHILE LOOP

	cout << endl;
	cout << "Thank You for playing my Tic Tac Toe version. I hope you had"
			" fun. Good Bye!" << endl << endl;

		system("pause");

	return 0;
}
