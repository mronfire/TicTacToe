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
 * FUNCTION GetComputerPlay
 *_______________________________________________________________________
 * This function will get the computer play and depending on the computer
 * turn it will make a half-intelligent move in order to block any possible
 * wins from user.
 * Game difficulty = Medium
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	boardAr[][NUM_COLS] - The game board
 *	token				- Players token
 *	comPlay				- Computer turns
 *
 * POST-CONDITIONS
 * 		This function will return nothing. But it will assign the computer
 * 		play into the game board.
 ************************************************************************/
void GetComputerPlay(char boardAr[][NUM_COLS], //IN - Game board
			         char token,			   //IN - Players token
					 short comPlay)		       //IN - Computer turns
{

	bool  invalid;		//CALC 		- Invalid move
	bool  found;		//CALC		- Block move found
	bool  hasCenter;	//CALC 		- Computer has center box
	short row;			//IN & CALC - Row in board game
	short col;			//IN & CALC - Column in board game

	invalid   = false;
	found     = false;
	hasCenter = false;


	//If center is not taken, TAKE IT!
	if(boardAr[1][1] != 'X' && comPlay == 1)
	{
		boardAr[1][1] = token;
		hasCenter = true;
	}

	//If CENTER box is already taken, make random move!
	if(hasCenter == false && comPlay < 2)
	{
		do
		{
			row = rand() % 3;
			col = rand() % 3;

			if(isspace(boardAr[row][col]))
			{
				invalid = true;
			}
		}while(!invalid);

		boardAr[row][col] = token;
	}

	//This If-then-else-if will check if there's a possible block in every
	//possible win diagonally!

	//x
	// x
	//  ?
	if(boardAr[0][0] == 'X' && boardAr[1][1] == 'X' &&
	   boardAr[2][2] == ' ' && comPlay >= 2 && found == false)
	{
		boardAr[2][2] = token;
		found = true;
	}

	//  x
	// x
	//?
	else if(boardAr[0][2] == 'X' && boardAr[1][1] == 'X' &&
			boardAr[2][0] == ' ' && comPlay >= 2 && found == false)
	{
		boardAr[2][0] = token;
		found = true;
	}

	//?
	// x
	//  x
	else if(boardAr[2][2] == 'X' && boardAr[1][1] == 'X' &&
			boardAr[0][0] == ' ' && comPlay >= 2 && found == false)
	{
		boardAr[0][0] = token;
		found = true;
	}

	//  ?
	// x
	//x
	else if(boardAr[2][0] == 'X' && boardAr[1][1] == 'X' &&
			boardAr[0][2] == ' ' && comPlay >= 2 && found == false)
	{
		boardAr[0][2] = token;
		found = true;
	}

	//Blocking if there is a possible win in columns
	for(col = 0; col < NUM_COLS; col++)
	{
		//x
		//x
		//?
		if(boardAr[0][col] == 'X' && boardAr[1][col] == 'X' &&
		   boardAr[2][col] == ' ' && comPlay >= 2 && found == false)
		{
			boardAr[2][col] = token;
			found = true;
		}
		//x
		//?
		//x
		else if(boardAr[0][col] == 'X' && boardAr[1][col] == ' ' &&
				boardAr[2][col] == 'X' && comPlay >= 2 && found == false)
		{
			boardAr[1][col] = token;
			found = true;
		}
		//?
		//x
		//x
		else if(boardAr[0][col] == ' ' && boardAr[1][col] == 'X' &&
				boardAr[2][col] == 'X' && comPlay >= 2 && found == false)
		{
			boardAr[0][col] = token;
			found = true;
		}
	}

	//Blocking if there is a possible win in rows
	for(row = 0; row < NUM_ROWS; row++)
	{
		//x x ?
		if(boardAr[row][0] == 'X' && boardAr[row][1] == 'X' &&
		   boardAr[row][2] == ' ' && comPlay >= 2 && found == false)
		{
			boardAr[row][2] = token;
			found = true;
		}
		//x ? x
		else if(boardAr[row][0] == 'X' && boardAr[row][1] == ' ' &&
				boardAr[row][2] == 'X' && comPlay >= 2 && found == false)
		{
			boardAr[row][1] = token;
			found = true;
		}
		//? x x
		else if(boardAr[row][0] == ' ' && boardAr[row][1] == 'X' &&
				boardAr[row][2] == 'X' && comPlay >= 2 && found == false)
		{
			boardAr[row][0] = token;
			found = true;
		}
	}

	//If there is nowhere to block and computer turn is after 2, it will
	//make a random move
	if(found == false && comPlay >= 2)
	{
		do
		{
			row = rand() % 3;
			col = rand() % 3;

			if(isspace(boardAr[row][col]))
			{
				invalid = true;
			}
		}while(!invalid);

		boardAr[row][col] = token;
	}

}
