/** ****************************************************************************
 * @file
 *
 * @brief This file contains all includes and function protoypes
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

 /******************************************************************************
  *                                             Function Prototypes
  *****************************************************************************/
void knightsTour( int squaresVisited, int row, int col, int** board,
    int boardSize, int** solution, bool& solutionFound, ostream& out );
int** create2DArray( int** arr, int size );
void fillArray( int** board, int boardSize );
void printTour( int** solution, int size, ostream& out );
void deleteArrays( int** board, int boardSize, int** solution );
