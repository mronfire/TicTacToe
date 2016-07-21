/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #2    : Multi-Dimensional Arrays - TIC TAC TOE
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 2/29/16
 ************************************************************************/
#ifndef TICTACHEADER_H_
#define TICTACHEADER_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ios>
#include <limits>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

//GLOBAL CONSTANTS
const short NUM_ROWS = 3; //Number of rows
const short NUM_COLS = 3; //Number of columns

enum menuOptions //Makes the menu options more readable
{
	EXIT,
	PLAYERS,
	TWO_PLAYER,
	ONE_PLAYER
};

//PROTOTYPES
/***********************************************************************
*PrintHeader
* This function receives an assignment name, type and number then outputs
* the appropriate header - returns the header box with information from the
* programmer.
************************************************************************/
string PrintHeader(string asNameF, //IN & OUT - Name of assignment or lab
 				   char asTypeF,   //IN & OUT - Lab or Assignment
 				   int asNumF);	   //IN & OUT - Number of Lab or assignment

/**************************************************************************
* OutputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
**************************************************************************/
void OutputInstruct();

/**************************************************************************
* MenuDisplay
* This function will display the menu for the users with options to choose
* from. There are no input or output parameters to this function as it only
* displays the menu for the user.
*
* RETURNS: It will return the users choice from the menu
**************************************************************************/
short MenuDisplay();

/**************************************************************************
* InitBoard
* This function initializes each spot in the board to a space ' '.
*
* RETURNS: Board initialized with all spaces
**************************************************************************/
void InitBoard(char boardAr[][NUM_COLS]); // OUT - tic tac toe board

/**************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
* 			1 		2		3
* 		 [1][1] | [1][2] | [1][3]
* 				| 		 |
* 	1 			| 		 |
* 				| 		 |
* 		--------------------------
* 		 [2][1] | [2][2] | [2][3]
* 				|		 |
* 	2 			|		 |
* 				|		 |
* 		--------------------------
* 		 [3][1] | [3][2] | [3][3]
* 				|		 |
* 	3 			|		 |
*				|		 |
*
* RETURNS: nothing
* -> outputs the current state of the board
* ***********************************************************************/
void DisplayBoard(const char boardAr[][NUM_COLS]);// IN - tic tac toe board

/*************************************************************************
* GetPlayers
* This function prompts the user and gets the input for the players’ names.
* playerX will always contain the name of the player that is using the X token.
* playerO will always contain the name of the player that is using the O token.
*
* RETURNS: the players names through the variables playerX and playerO.
**************************************************************************/
void GetPlayers(string& playerX,  // OUT - player X’s name
			    string& playerO); // OUT - player O’x name

/*************************************************************************
* GetAndCheckInp
* This function will get and check the users input. It will prompt the user
* by name, and then check for unexpected input, outside boundaries input,
* and if the spot chosen to play is already taken.
*
* RETURNS: It will return nothing, just assign the token to the chosen
* 		   spot.
**************************************************************************/
void GetAndCheckInp(char boardAr[][NUM_COLS],// IN - tic tac toe board
				    char token, 			 // IN - current player’s token
					string playerX,			 // OUT - player X’s name
				    string playerO);		 // OUT - player O’x name

/*************************************************************************
* SwitchToken
* This function switches the active player.
* It takes in a parameter representing the current player's token
* as a character value (either an X or an O) and returns the opposite.
* For example, if this function receives an X it returns an O. If it
* receives and O it returns and X.
*
* RETURNS: the token opposite of the one in which it receives.
**************************************************************************/
char SwitchToken(char token); // IN - current player’s token ('X' or 'O')

/*************************************************************************
* GetComputerPlay
* This function will get the computer play and depending on the computer
 * turn it will make a half-intelligent move in order to block any possible
 * wins from user.
*
* RETURNS: The computers play to the assign spot.
**************************************************************************/
void GetComputerPlay(char boardAr[][NUM_COLS],// IN - tic tac toe board
				     char token,    		  // IN - current player’s token
					 short comPlay);		  // IN - Computer turns

/**************************************************************************
* CheckWin
* This function checks to see if either player has run. Once it is
* possible for a win condition to exist, this should run after each a
* player makes a play.
*
* RETURNS the character value of the player that won or a value that
* indicates a tie.
**************************************************************************/
char CheckWin(const char boardAr[][NUM_COLS]); // IN - tic tac toe board

/**************************************************************************
* OutputWinner
* This function receives as input a character indicating which player won
* or if the game was a tie and outputs an appropriate message. This function
* does not return anything as it simply outputs the appropriate message to
* the screen.
*
* RETURNS: nothing
* Displays the winner’s name
**************************************************************************/
void OutputWinner(char whoWon,    // IN - represents the winner or a value
							      // indicating a tied game.
			      string playerX, // OUT - player X’s name
				  string playerO);// OUT - player O’x name

#endif /* TICTACHEADER_H_ */
