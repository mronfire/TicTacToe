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
 * FUNCTION OutputWinner
 *_______________________________________________________________________
 * This function receives as input a character indicating which player won
* or if the game was a tie and outputs an appropriate message. This function
* does not return anything as it simply outputs the appropriate message to
* the screen.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 *	whoWon  - It has to be previosly defined
 *	playerX - The name of first player
 *	playerO	- The name of second player
 *
 * POST-CONDITIONS
 * 		This function will return nothing. It will display the winner.
 ************************************************************************/
void OutputWinner(char whoWon,    //IN & CALC & OUT - Game winner
				  string playerX, //OUT				- First player
				  string playerO) //OUT				- Second player
{
	//If-STATEMENT - It will display the correct winner according to who won
	//				 the game.
	if(whoWon == 'X')
	{
		cout << endl;
		cout << playerX << " won the game!\n";
	}
	else if(whoWon == 'O')
	{
		cout << playerO << " won the game!\n";
	}
	else
	{
		cout << "It\'s a Tie!\n";
	}

}
