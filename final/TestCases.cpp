#include "final.h"
TEST_CASE( "myStack - isEmpty" )
{
    card aCard;
    myStack<card> testStack;
    int cards[4] = { 4, 8, 2, 7 };
    int i;

    SECTION( "Empty stack" )
    {
        REQUIRE( testStack.isEmpty( ) == true );
    }
    SECTION( "Stack with items" )
    {
        for ( i = 0; i < 4; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 2; //Suit of Spades
            testStack.push( aCard );
        }
        REQUIRE( testStack.isEmpty( ) == false );
    }
}

TEST_CASE( "myStack - push" )
{
    card aCard;
    myStack<card> testStack;
    ostringstream sout;
    int cards[4] = { 4, 8, 2, 7 };
    int i;

    SECTION( "push - one item, empty stack" )
    {
        aCard.faceValue = cards[0];
        aCard.suit = 0; //Suit of Hearts
        testStack.push( aCard );
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    4H" );
        REQUIRE( testStack.size( ) == 1 );
    }
    SECTION( "push - multiple items, empty stack" )
    {
        for ( i = 0; i < 3; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 1; //Suit of Diamonds
            testStack.push( aCard );
        }
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    2D    8D    4D" );
        REQUIRE( testStack.size( ) == 3 );
    }
}

TEST_CASE( "myStack - pop" )
{
    card aCard;
    myStack<card> testStack;
    ostringstream sout;
    int cards[4] = { 4, 8, 2, 7 };
    int i;

    SECTION( "pop - one item, empty stack" )
    {
        REQUIRE(testStack.pop( aCard ) == false);
        testStack.print( sout );
        REQUIRE( sout.str( ) == "" );
        REQUIRE( testStack.size( ) == 0 );
    }
    SECTION( "pop - one item, stack with items" )
    {
        for ( i = 0; i < 3; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 1; //Suit of Diamonds
            testStack.push( aCard );
        }
        testStack.pop( aCard );
        REQUIRE( aCard.faceValue == 2 );
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    8D    4D" );
        REQUIRE( testStack.size( ) == 2 );
    }
    SECTION( "pop - multiple items, stack with items" )
    {
        for ( i = 0; i < 3; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 1; //Suit of Diamonds
            testStack.push( aCard );
        }
        testStack.pop( aCard );
        testStack.pop( aCard );
        REQUIRE( aCard.faceValue == 8 );
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    4D" );
        REQUIRE( testStack.size( ) == 1 );
    }
}

TEST_CASE( "myStack - front" )
{
    card aCard;
    myStack<card> testStack;
    ostringstream sout;
    int cards[4] = { 4, 8, 2, 7 };
    int i;

    SECTION( "front - empty stack" )
    {
        REQUIRE( testStack.front( aCard ) == false );
        testStack.print( sout );
        REQUIRE( sout.str( ) == "" );
    }
    SECTION( "front - stack with items" )
    {
        for ( i = 0; i < 3; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 1; //Suit of Diamonds
            testStack.push( aCard );
        }
        testStack.front( aCard );
        REQUIRE( aCard.faceValue == 2 );
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    2D    8D    4D" );
        REQUIRE( testStack.size( ) == 3 );
    }
}

TEST_CASE( "myStack - print" )
{
    card aCard;
    myStack<card> testStack;
    ostringstream sout;
    int cards[4] = { 4, 8, 2, 7 };
    int i;

    SECTION( "empty stack" )
    {
        testStack.print( sout );
        REQUIRE( sout.str( ) == "" );
    }
    SECTION( "stack of items" )
    {
        for ( i = 0; i < 3; i++ )
        {
            aCard.faceValue = cards[i];
            aCard.suit = 3; //Suit of Clubs
            testStack.push( aCard );
        }
        testStack.print( sout );
        REQUIRE( sout.str( ) == "    2S    8S    4S" );
    }
}
//TEST_CASE( "playRound -  single card wins" )
//{
//    card aCard;
//    int i;
//    ostringstream sout1, sout2;
//    Queue<card> p1, p2;
//    int p1cards[2] = { 4, 8 };
//    int p2cards[2] = { 2, 7 };
//    for ( i = 0; i < 2; i++ )
//    {
//        aCard.faceValue = p1Cards[i];
//        aCard.suit = 0; // gave it a suit of hearts 
//        p1.enqueue( aCard );
//    }
//    for ( i = 0; i < 2; i++ )
//    {
//        aCard.faceValue = p2Cards[i];
//        aCard.suit = 0;  // gave it a suit of hearts 
//        p2.enqueue( aCard );
//    }
//    SECTION( "Single Card win" )
//    {
//        playRound( p1, p2 );
//        sout1 << p1; // I overloaded the << operator to make this work 
//        sout2 << p2;
//        REQUIRE( sout1.str( ) == "  9H 3H   5H" ); 
//        REQUIRE( sout2.str( ) == "  8H" ); 
//    }
//}