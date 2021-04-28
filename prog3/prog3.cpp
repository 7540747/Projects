/** ****************************************************************************
 * @file
 *
 * @brief This file contains main and all function definitions for Program 3
 *****************************************************************************/
/** ***************************************************************************
  * @mainpage Program 3 - The Knights Tour
  *
  * @section M01 CSC 215
  *
  * @authors Ricky Clark III
  *
  * @par Professor:
  *         Prof. Roger Schrader
  *
  * @par Course:
  *         CSC215 - M001 - Programming Techniques
  *
  * @par Location:
  *         McLaury - M306
  *
  * @date Due April 30, 2021
  *
  * @section program_section Program Information
  *
  * @details This program will focus on the concept of recursion and backtracking. 
  * Specifically, to solve a knight's tour. What sequence of moves will allow the knight
  * to move to each square on the board visiting it only once? Using this bruteforce
  * algorithm, the program will recursively visit each square on the board "mimmicking"
  * the moves of a knight until a solution is found. Following this, the solution will then be 
  * provided to user via a file they provide or the terminal. 
  * 
  * There are 2 ways to use this program! The first option is to not provide a file as an
  * argument when beginning the execution of the program. If a file is not provided, the
  * program will then prompt the user to chose a board size, different starting
  * coordinates for the knight on the board, or to exit the menu and solve the puzzle! A
  * default board size of 8x8 is provided and default starting coordinates of [7, 7]. The
  * coordinates for the knight on the boards is indexed starting at 0. Lastly, if a solution
  * is not found for the provided board size and coordinates, then the message "No 
  * solutions for this case" will be displayed to the user.
  * 
  * If the user wishes to utilize the program second part of the program to solve files of
  * puzzles, they must pass tourfile full of puzzles to the program at execution. The files
  * must be formatted
    @verbatim
        n - [NxN board size]
        x y - [starting X coordinate and Y coordinate for knight]
    @endverbatim
  * The program will read in each puzzle parameter for the tour and solve the tour.
  * Then the tour will be outputted to the "Solutions.tours" file in the directory. This will
  * solve one tour at a time until all puzzles have been solved or a solution was not found.
  * 
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      none - a straight compile and link with no external libraries.
  *
  * @par Usage:
    @verbatim
        c:\>csc215\prog3.exe
        c:\>csc215\prog3.exe tourfile
    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug Found error in the function to fill the board array with padding - Only
  * half of the board filled with padding
  * @bug Found error when printing tour to ostream - No endl printing before
  * or after the tour
  * @bug Found error in knights tour - Tour not ending when one solution is found
  *
  * @todo None
  *
  * @par Modifications and Development Timeline:
  * This is a link to gitlab's commit. To view <a target="_blank"
  * href="https://gitlab.mcs.sdsmt.edu/7540747/csc215s21programs/-/commits/master/
  ">click here.</a>
  *
 ******************************************************************************/
#include "prog3.h"

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This is the main function of the program. Main is responsible for handling the command
 * arguments for the program. If only one argument is passed, main will prompt the user
 * with a main and solve the knights tour. If a file is also passed as an argument, main will
 * instead, read in each parameter for the tour in the file and solve each tour individually
 * one at time, until all puzzles have a solution or no solution has been found. 
 *
 * @param[in] argc - number of command arguments
 * @param[in] argv - character array of command arguments
 * 
 * @returns 0 Program ran sucessfully
 ******************************************************************************/
int main( int argc, char** argv )
{
    //Initialize variables
    ifstream tourIn;
    ofstream tourOut;
    bool solutionFound = false;
    int boardSize = 8;
    int solutionSize = 8;
    int row = 7, col = 7;
    int option = 0;
    int temp1, temp2;
    int** board = nullptr;
    int** solution = nullptr;
    int squaresVisited = 1;
    int tourNumber = 0;

    if ( argc == 1 )
    {
        while ( option != 3 )
        {
            //Output menu to user
            cout << "1) Change Board Size from " << boardSize << "x" << boardSize << endl;
            cout << "2) Change starting location from [" << row << ", " << col << "]" << endl;
            cout << "3) Exit and Solve Tour" << endl;

            //Prompt user for option
            cout << "Enter Choice: ";
            cin >> option;

            if ( option == 1 )
            {
                //Prompt user for new board size
                cout << endl;
                cout << "Enter the size of the NxN Board (>3): ";
                cin >> temp1;
                cout << endl;
                if ( temp1 <= row || temp1 <= col )
                    cout << "Invalid board size provided" << endl << endl;
                else
                    boardSize = temp1;
            }
            else if ( option == 2 )
            {
                //Prompt user for new starting location
                cout << endl;
                cout << "Enter Starting Coordinates [ row , col ]: ";
                cin >> temp1 >> temp2;
                cout << endl;
                if ( temp1 >= boardSize || temp2 >= boardSize )
                    cout << "Invalid starting coordinates provided" << endl << endl;
                else
                    row = temp1, col = temp2;
            }
            else if ( option != 3 )
            {
                cout << endl;
                cout << "Invalid option" << endl;
                cout << endl;
            }
        }

        //Create board and solution arrays
        solutionSize = boardSize;
        boardSize += 4;
        board = create2DArray( board, boardSize );
        solution = create2DArray( solution, solutionSize );

        //Load board with padding 
        fillArray( board, boardSize );

        //Output tour information
        tourNumber = 1;
        cout << "Tour: # " << tourNumber << endl;
        cout << "\t" << solutionSize << "x" << solutionSize << " starting at (" <<
            row << ", " << col << ")" << endl << endl;

        //Solve for the tour
        knightsTour( squaresVisited, row + 2, col + 2, board, boardSize, solution, 
            solutionFound, cout );

        //Check if solution was found
        if ( solutionFound )
            return 0;
        else
            cout << "\tNo solutions for this case." << endl;

        //Delete dynamically allocated memory
        deleteArrays( board, boardSize, solution );

        return 0;
    }
    else if ( argc == 2 )
    {
        //Open input file and check for success
        tourIn.open( argv[1] );
        if ( !tourIn.is_open( ) )
        {
            tourIn.close( );
            cout << "Unable to open input file: " << argv[1] << endl;
            exit( 1 );
        }

        //Open output file and check for success
        tourOut.open( "Solutions.tours", ios::out || ios::app );
        if ( !tourOut.is_open( ) )
        {
            tourIn.close( );
            tourOut.close( );
            cout << "Unable to open output file: Solutions.tours" << endl;
            exit( 1 );
        }

        //Read in each tour from the file and solve them individually
        while ( tourIn >> boardSize && tourIn >> row && tourIn >> col )
        {
            //Create 2D arrays for board and solution
            solutionSize = boardSize;
            boardSize += 4;
            board = create2DArray( board, boardSize);
            solution = create2DArray( solution, solutionSize );
            tourNumber += 1;

            //Fill board array with padding
            fillArray( board, boardSize );

            //Output tour information
            tourOut.clear( );
            tourOut << "Tour: # " << tourNumber << endl;
            tourOut << "\t" << solutionSize << "x" << solutionSize << " starting at ("
                << row << ", " << col << ")" << endl << endl;
            knightsTour(squaresVisited, row + 2, col+2, board, boardSize,
                solution, solutionFound, tourOut);

            //Check for solution
            if ( !solutionFound )
                tourOut << "\tNo solutions for this case.\n" << endl << endl;

            //Delete the dynamic arrays
            deleteArrays( board, boardSize, solution );
            
            //Reset solution found
            solutionFound = false;
        }

        return 0;
    }
    else
    {
        //Usage for Program 3
        cout << " Usage: prog3.exe" << endl;
        cout << "\tprog3.exe tourfile" << endl;
    }

    return 0;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function is the main recursive, backtracking algorithm for the program. This 
 * function will keep track of the squares visited during the tour to test if the next move
 * for the knight is valid. If not, the function backs up to check other squares. The moves
 * will continue until the first solution is found or no solution is found for the tour. The
 * tour will then be outputted to the user depending on the ostream passed to the tour.
 *
 * @param[in] squaresVisited - total number of squares visited by the knight
 * @param[in] row - the current row (X coordinate) of the knight
 * @param[in] col - the current col (Y coordinate) of the knight 
 * @param[in] board - dynamic 2D array of the board with the squares visited by the
 * knight marked with a -1
 * @param[in] boardSize - NxN size of the board
 * @param[in] solution - dynamic 2D array that is the solution for the knights tour
 * @param[in,out] solutionFound - boolean variable to keep check if a solution was found
 * @param[in] out - output stream used to print the knights tour
 * 
 * @returns none
 ******************************************************************************/
void knightsTour( int squaresVisited, int row, int col, int** board,
    int boardSize, int** solution, bool& solutionFound, ostream& out)
{
    //Initialize variables
    int solutionSize = ( boardSize - 4 ) * ( boardSize - 4 );

    //Base case
    if ( board[row][col] != 0 || solutionFound )
        return;
    if ( squaresVisited == solutionSize )
    {
        //Set the last square as visited
        solution[row - 2][col - 2] = squaresVisited;

        //Print the tour
        printTour( solution, boardSize - 4, out );

        //If solution is found return
        solutionFound = true;
    }

    board[row][col] = -1;
    solution[row-2][col-2] = squaresVisited;

    knightsTour( squaresVisited + 1, row - 2, col + 1, board, boardSize, 
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row - 1, col + 2, board, boardSize,
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row +1, col + 2 , board, boardSize,
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row + 2, col + 1, board, boardSize,
        solution,  solutionFound,out );
    knightsTour( squaresVisited+1, row + 2, col - 1, board, boardSize,
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row + 1, col - 2, board, boardSize,
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row - 1, col -2, board, boardSize,
        solution, solutionFound, out );
    knightsTour( squaresVisited+1, row - 2, col - 1, board, boardSize,
        solution, solutionFound, out );

    board[row][col] = 0;
    solution[row-2][col-2] = 0;

    return;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function is responsible for creating a dynamic 2D array.
 *
 * @param[in] arr - dynamic 2D array to be created
 * @param[in] size - NxN size of 2D array to be created
 * 
 * @returns arr - dynamic 2D array that was created
 ******************************************************************************/
int** create2DArray( int** arr, int size )
{
    //Initialize variables
    int i;

    arr = new ( nothrow ) int* [size] {0};
    if ( arr == nullptr )
    {
        delete arr;
        exit( 1 );
    }
    for ( i = 0; i < size; i++ )
    {
        arr[i] = new ( nothrow ) int[size] { 0 };
        if ( arr[i] == nullptr )
        {
            delete[] arr;
            exit( 1 );
        }
    }

    return arr;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function is responsible for filling the board with padding of width 2 on each side
 * of the board.
 *
 * @param[in] board - board to receive padding
 * @param[in] boardSize - NxN size of board
 * 
 * @returns none
 ******************************************************************************/
void fillArray( int** board, int boardSize )
{
    //Initialize variables
    int i, j;

    //Fill padding of board with -1s
    for ( i = 0; i < 2; i++ )
        for ( j = 0; j < boardSize; j++ )
            board[i][j] = -1;
    for ( i = 0; i < boardSize; i++ )
        for ( j = 0; j < 2; j++ )
            board[i][j] = -1;
    for ( i = boardSize - 2; i < boardSize; i++ )
        for ( j = 0; j < boardSize; j++ )
            board[i][j] = -1;
    for ( i = 0; i < boardSize; i++ )
        for ( j = boardSize - 2; j < boardSize; j++ )
            board[i][j] = -1;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function is responsible for deleting all dynamic 2D arrays created.
 *
 * @param[in] board -  dynamic 2D array for the knight 
 * @param[in] boardSize - NxN size of the board
 * @param[in] solution - dynamic 2D array for the solution of the tour
 * 
 * @returns none
 ******************************************************************************/
void deleteArrays( int** board, int boardSize, int** solution )
{
    //Initialize variables
    int i;

    //Delete board
    for ( i = 0; i < boardSize; i++ )
        delete[] board[i];
    delete[] board;

    //Delete solution
    for ( i = 0; i < (boardSize - 4); i++ )
        delete[] solution[i];
    delete[] solution;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function  is responsible for printing the tour to the user via their choice of
 * output stream.
 *
 * @param[in] solution - the solution of the knights tour
 * @param[in] size - NxN size of the solution 
 * @param[in] out - output stream used to print the knights tour
 * 
 * @returns none
 ******************************************************************************/
void printTour( int** solution, int size, ostream& out )
{
    //Initialize variables
    int i, j;

    //Output the tour
    for ( i = 0; i < size; i++ )
    {
        out << "\t";
        for ( j = 0; j < size; j++ )
        {
            if ( j % size == 0 && i != 0 )
                out << "\n" << "\t";
            out << setw( 3 ) << solution[i][j];
        }
    }

    out << endl;
    out << endl;
    out << endl;
}
