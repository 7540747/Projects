/** ***************************************************************************
 * @file
 *
 * @brief contains the main function that processes binary records and checks for
 * errors
 *****************************************************************************/
/** ***************************************************************************
 * @mainpage Program 1 - Radio Operator Records
 *
 * @section course_section Course Information
 *
 * @authors Ricky E. Clark III
 *
 * @date March, 19th 2021
 *
 * @par Instructor:
 *        Professor Roger Schrader
 *
 * @par Course:
 *        CSC215 - Programming Techniques - 9:00 AM
 *
 * @par Location:
 *         McLaury Building Room 306
 *
 * @section program_section Program Information
 *
 * @details The purpose of this program is to error check Radio Operator records
 * for the company. The program will take a binary file of records and read in one
 * record at a time. The program will then process the record one at a time
 * checking for any errors in the record. If an error is found in the record, the error
 * will then be written to a vector of strings containing all errors found in the record. 
 * If there are no errors found in the record, the record will
 * then just be written to the new binary file holding all correct records. Any records
 * with errors will be written to the text file with the corresponding errors so they 
 * can be corrected if need be.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog1.exe dbham.bin newdbham.bin errors.txt
           dbham.bin - old binary records
           newdbham.bin - new binary records
           errors.txt - text file for records with errors
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug validZip4 - Did not account for the zipcode being zero
 * @bug validCallSign2 - Did not account for some characters being valid and others invalid
 * @bug validRadioClass - Did not account for lowercase radio class letters
 * @bug validState - Was not accounting for one valid letter and an invalid letter
 *
 * @todo Error check more records to verify correctness of program.
 * @todo Finish Doxygen Documentation
 *
 *  * @par Modifications and Development Timeline:
 *     <a href="https://gitlab.mcs.sdsmt.edu/rschrade/moduleproblems/-/commits/master" target=_blank>
 *     Gitlab Commit Log</a>
 ******************************************************************************/
#define CATCH_CONFIG_RUNNER
#include "prog1.h"
#include "..\\catch.hpp"

/**
 * @var RUNCATCH
 * @brief The variable used to toggle catch runner. True being on and false being off.
 */
const bool RUNCATCH = true;
/***************************************************************************//**
 * @author Professor Roger Schrader
 *
 * @par Description:
 * This function will create the main for the catch runner and all test cases for Program 2.
 *
 * @param[in] myargc - total count of command line arguments
 * @param[in] myargv - character array of command line arguments
 * 
 * @returns none
 ******************************************************************************/
void makeCATCH( int& myargc, char**& myargv );

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * The program will first check that all command line arguments are provided. Next, the
 * program will then open any necessary files and check that they opened. The program will
 * output corresponding errors if arguments or files are incorrect. If all files and arguments
 * are correct, it will then process each record one at time checking for erorrs. Any records
 * containing errors will be written to a text file with the corresponding errors. All records
 * with no errors will be written to the new binary file.
 *
 * @param[in] argc - the number of command line arguments
 * @param[in] argv - 2D array holding the arguments
 * 
 * @returns 0 program ran successfully
 ******************************************************************************/
int main( int argc, char** argv )
{
    // declare variables here
    ifstream recIn;
    ofstream recOut;
    ofstream errorOut;

    //////////////////////////////////// Do not edit this section
    int result = 1;
    int myargc;
    char** myargv;
    if ( RUNCATCH )
    {
        makeCATCH( myargc, myargv );
        result = Catch::Session( ).run( myargc, myargv );
        if ( result != 0 )
        {
            cout << "You have errors in your functions" << endl;
            return 0;
        }
    }
    //////////////////////////////////// Place your code here


    // write your code here
    //Check for commmand line arguments
    if ( argc != 4 )
    {
        cout << "Usage: prog1.exe oldrecords.bin newrecords.bin errorfile.txt" << endl;
        exit( 0 );
    }

    //Open files
    recIn.open( argv[1], ios::in || ios::binary );
    recOut.open( argv[2], ios::out || ios::binary );
    errorOut.open( argv[3] );

    //Check if files opened
    if ( !recIn.is_open( ) )
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        recIn.clear( );
        recIn.close( );
        exit( 0 );
    }
    if ( !recOut.is_open( ) )
    {
        cout << "Unable to open binary file: " << argv[2] << endl;
        recOut.clear( );
        recOut.close( );
        exit( 0 );
    }
    if ( !errorOut.is_open( ) )
    {
        cout << "Unable to open text file: " << argv[3] << endl;
        errorOut.clear( );
        errorOut.close( );
        exit( 0 );
    }

    //Process records and check for errors 
    processRecords( recIn, recOut, errorOut );

    //Close files
    closeFiles( recIn, recOut, errorOut );

    return 0;
}