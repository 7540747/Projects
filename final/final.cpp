#define CATCH_CONFIG_RUNNER
#include "final.h"

void makeCATCH( int& myargc, char**& myargv );
void shuffleTheDeck( queue<card>& deck, unsigned int seed );
void printQueue( ostream& out, queue<card> q );

int main( int argc, char** argv )
{
    //Catch Runner
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

    //Initalize variables
    char seedOption[3] = {'-', 's', '\0' };
    char fileOption[3] = {'-', 'f', '\0' };
    int count = 0;
    unsigned int seedP1, seedP2;
    queue<card> p1, p2;
    myStack<card> p1Discard, p2Discard;

    //Check command arguments
    if ( argc != 4 )
    {
        //Output usage statement
        cout << "Usage: final.exe -f file1.txt file2.txt\n"
            << "                 -s integerSeed1 integerSeed2" << endl;
        return 1;
    }
    else if ( strcmp(seedOption, argv[1] ) == 0)
    {
        //Translate the seed from the argument
        seedP1 = ( unsigned int )(atoi( argv[2] ));
        seedP2 = ( unsigned int )(atoi( argv[3] ));
        
        //Generate card for each player
        shuffleTheDeck( p1, seedP1 );
        shuffleTheDeck( p2, seedP2 );

        //Print decks to check for success
        cout << "Player 1's Hand: " << endl;
        printQueue( cout, p1 );
        cout << endl << endl;
        cout << "Player 2's Hand: " << endl;
        printQueue( cout, p2 );

        //Begin playing the game

        return 0;
    }
    else if ( strcmp( fileOption, argv[1] ) == 0 )
    {
        //Read in cards from file
    }
    else
    {
        //Output usage statement
        cout << "Usage: final.exe -f file1.txt file2.txt\n"
            << "                 -s integerSeed1 integerSeed2" << endl;
        return 1;
    }

    return 0;
}

void shuffleTheDeck( queue<card>& deck, unsigned int seed )
{
    //Create random number generator
    default_random_engine generator(  seed ); // Use a different seed for each player
    uniform_int_distribution<int> distribution( 0, 51 );

    //Initialize variables
    card aCard;
    int cardValue;
    bool usedCards[52] = { false };

    //Fill deck with cards
    while ( deck.size( ) != 52 )
    {
        cardValue = distribution( generator );
        if ( !usedCards[cardValue] )
        {
            //Check for face value and suit
            aCard.faceValue = cardValue % 13;
            aCard.suit = cardValue / 13;
            deck.push( aCard );
            usedCards[cardValue] = true;
        }
    }
}

void printQueue( ostream& out, queue<card> q)
{
    while ( !q.empty( ) )
    {
        out << setw( 5 ) << q.front( );
        q.pop( );
    }
}

ostream& operator<<( ostream& out, card& aCard )
{
    out << setw( 5 ) << aCard.faceValue;
    if ( aCard.suit == 0 )
        out << "H";
    else if ( aCard.suit == 1 )
        out << "D";
    else if ( aCard.suit == 2 )
        out << "C";
    else if ( aCard.suit == 3 )
        out << "S";
    return out;
}