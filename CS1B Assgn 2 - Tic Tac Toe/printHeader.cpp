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
 * FUNCTION PrintHeader
 *_______________________________________________________________________
 * This function receives an assignment name, type
 *  and number then outputs the appropriate header -
 *  returns nothing.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 * 		asNameF: Assignment Name has to be previously defined
 * 		asTypeF: Assignment Type has to be previously defined
 * 		asNumF : Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 ************************************************************************/

string PrintHeader(string asNameF,  // IN - assignment Name
 				   char asTypeF,    // IN - assignment type
	 	 	 	 				    //      (LAB or ASSIGNMENT)
 				   int asNumF)      // IN - assignment number
{

	ostringstream header;

	header << left;
	header << "**************************************************\n";
	header << "* PROGRAMMED BY : Mario Rodriguez";
	header << "\n* " << setw(14) << "STUDENT ID" << ": 1028268";
	header << "\n* " << setw(14) << "CLASS" << ": CS1B –-> MWF - 8am";
	header << "\n* " ;

	// IF STATEMENT - The user will be able to choose if its a Lab or
	//				  assignment and output the proper output.
	if (toupper(asTypeF) == 'L')
	{
		header << "LAB #" << setw(9);
	}
	else
	{
		header << "ASSIGNMENT #" << setw(2);
	}

	header << asNumF << ": " << asNameF;
	header << "\n**************************************************\n\n";
	header << right;

	return header.str();
}
