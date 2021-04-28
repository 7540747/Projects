#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <sstream>
#include <iomanip>
#include <random>
#include "..\catch.hpp"

/** ****************************************************************************
 * @var RUNCATCH
 *
 * @brief This variable will be used to toggle catch test cases by setting the variable
 * to either true or false. esews
 ******************************************************************************/
const bool RUNCATCH = true;

using namespace std;


struct card
{
    int faceValue ;
    int suit ;

    friend ostream& operator<<( ostream& out, card& aCard );
};

#ifndef __FINAL__H__
#define __FINAL__H__
template <class TY> 
class myStack
{
    public:
    //Constructors and Destructor
    myStack( );
    myStack( myStack<TY>& s );
    ~myStack( );

    //Member functions
    bool push( TY val );
    bool pop( TY& val );
    bool front( TY& val );
    bool isEmpty( ) const;
    int size( ) const;
    void print( ostream& out );

    private:
    struct node
    {
        TY item;
        node* next;
    };
    node* headptr;
    int stackSize;
};


template <class TY>
myStack<TY>::myStack( )
{
    //Initalize stack
    headptr = nullptr;
    stackSize = 0;
}

template <class TY>
myStack<TY>::myStack( myStack<TY>& s )
{
    //Initialize variables
    node* src;
    node* dest;

    //Initialize stack
    headptr = nullptr;
    stackSize = 0;
    //Check for empty list
    if ( s.isEmpty() )
        return;

    //Check for allocation in new node
    headptr = new ( nothrow ) node;
    if ( headptr == nullptr )
        exit( 1 );
    headptr->item = s.headptr->item;
    headptr->next = nullptr;
    stackSize++;


    //Walk through list to copy each node
    src = s.headptr->next;
    dest = headptr;
    while ( src != nullptr )
    {
        dest->next = new ( nothrow ) node;
        if ( dest->next == nullptr )
            exit( 1 );

        dest = dest->next;
        dest->item = src->item;
        dest->next = nullptr;

        stackSize++;
        src = src->next;
    }
}

template <class TY>
myStack<TY>::~myStack( )
{
    //Initialize variables
    node* temp = nullptr;

    //Iterate through the stack to delete each item
    while ( headptr != nullptr )
    {
        temp = headptr;
        headptr = headptr->next;
        delete temp;
    }
}

template <class TY>
bool myStack<TY>::isEmpty( ) const
{
    //Check if stack is empty
    if ( headptr == nullptr )
        return true;
    else
        return false;
}

template<class TY>
bool myStack <TY>::push( TY val )
{
    //Initialize variables
    node* temp = nullptr;

    //Allocate new node and check for success
    temp = new ( nothrow ) node;
    if ( temp == nullptr )
        return false;
    temp->item = val;
    temp->next = nullptr;

    //Insert item at front of stack
    temp->next = headptr;
    headptr = temp;
    stackSize++;
    return true;
}

template <class TY> 
bool myStack<TY>::pop( TY& val )
{
    //Initalize varialbes
    node* temp = nullptr;

    //Check if empty stack
    if ( isEmpty() )
        return false;

    temp = headptr;
    val = headptr->item;
    headptr = headptr->next;
    delete temp;
    stackSize--;
    return true;
}

template <class TY>
bool myStack<TY>::front( TY& val )
{
    //Check if empty stack
    if ( isEmpty() )
        return false;

    //Check front item
    val = headptr->item;
    return true;
}

template <class TY>
int myStack<TY>::size( ) const
{
    return stackSize;
}

template <class TY>
void myStack<TY>::print( ostream& out )
{
    node* temp = headptr;

    while ( temp != nullptr )
    {
        out << temp->item;
        temp = temp->next;
    }
}
#endif
