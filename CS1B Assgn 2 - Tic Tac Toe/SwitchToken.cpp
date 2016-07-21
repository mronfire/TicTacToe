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
 * FUNCTION SwitchToken
 *_______________________________________________________________________
 * This function switches the active player.
 * It takes in a parameter representing the current player's token
 * as a character value (either an X or an O) and returns the opposite.
 * For example, if this function receives an X it returns an O. If it
 * receives and O it returns and X.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	token - It has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will return the token opposite of the one in which
 * 		it receives.
 ************************************************************************/
char SwitchToken(char token) //IN & CALC - Players token
{
	char newToken; //CALC & OUT - The opposite token

	//IF-STATEMENT - It will assign to newToken the opposite token of which
	//				 it receives
	if(token == 'X')
	{
		newToken = 'O';
	}
	else
	{
		newToken = 'X';
	}

	return newToken;
}
