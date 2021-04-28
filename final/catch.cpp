/** ****************************************************************************
 * @file
 *
 * @brief This file contains the catch main function for all test cases in Program 2
 *****************************************************************************/
#include "final.h"

 /***************************************************************************//**
  * @author Professor Roger Schrader
  *
  * @par Description:
  * This function will create main for the catch runner and all test cases for Program 2.
  *
  * @param[in] myargc - total count of command line arguments
  * @param[in] myargv - character array of command line arguments
  *
  * @returns none
  ******************************************************************************/
void makeCATCH( int& myargc, char**& myargv )
{

    myargc = 1;
    myargv = new ( nothrow ) char* [myargc];

    myargv[0] = new ( nothrow ) char[strlen( "x64\\debug\\prog2.exe" ) + 1];
    strcpy( myargv[0], "x64\\debug\\prog2.exe" );
}