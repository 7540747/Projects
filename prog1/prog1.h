/***************************************************************************//**
 * @file 
 *
 * @brief Contains all typedefines, structures, and function prototypes used
 * in Program 1. 
 ******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

#ifndef __PROG1__H__
#define __PROG1__H__

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
/**
 * @var DATE
 * @brief Unsigned integer containing a date. The year is packed into bits 12-23,
 * the month is packed in bits 6-9, and the day is packed in bits 0-5
 * 
 * @var ZIPCODE
 * @brief Unsigned integer containing the 5 digit zipcode and 4 digit zipcode.
 * The 5 digit zipcode is packed in bits 14-31 and the 4 digit zipcode is packed in bits 0-13
 */
// put typedef statements here
typedef unsigned int DATE; 
typedef unsigned int ZIPCODE;

/***************************************************************************//**
 * @struct Record 
 *
 * @details This is the structure of the records in the binary files of each licensed
 * radio operator. The name contains the name of the operator. The address will hold the
 * last known address of the operator. The city and state also being the last known
 * address of the operator. The zipcode will contain the 5 digit zip and 4 digit zip of the
 * address. The Record will also contain the birth date, license date, and expiration date
 * of the license of the operator. The operators radio class will be included along with
 * the call sign. 
 * 
 * @var char Record::name
 * @var char Record::address
 * @var char Record::city
 * @var char Record::state
 * @var ZIPCODE Record::zipCode
 * @var DATE Record::birthDate
 * @var DATE Record::licenseDate
 * @var DATE Record::expirationDate
 * @var char Record::radioClass
 * @var char Record::callSign
 ******************************************************************************/
// put structure here for part b of program 1
#pragma pack(push) 
#pragma pack(1)
struct Record
{
    char name[30];   /**< Name of the radio operator. 
                                      A name is valid only if it is A-Z, a-z, '.', or ' ' */
    char address[30];    /**< Last known address of radio operator. Address is valid
                         only if it contains the characters A-Z, a-z, 0-9, ' ', '.', or '#'*/
    char city[28];    /**< Last known city of radio operator. City is valid only if
                                     it contains the characters A-Z, a-z, '.', or ' '*/
    char state[2];    /**< Last known state of radio operator. State is valid only if it
                                      is one of the 50 state abbreviations in use and the first letter
                                      must be capitalized.*/
    ZIPCODE zipCode;   /**< Last known zipcode of radio operator. 5 digit zip
                                            is packed in bits 14-31. 4 digit zip is packed in bits 0-13*/
    DATE birthDate;    /**< Birth date of radio operator. Year is packed in bits 12-23.
                                           Day is packedin bits 0-5. Month is packed in bits 6-9*/
    DATE licenseDate;    /**< License date of radio operator. Year is packed in bits 12-23.
                                           Day is packedin bits 0-5. Month is packed in bits 6-9*/
    DATE expirationDate;     /**< Expiration date of licensed radio operator. 
                                                   Year is packed in bits 12-23. Day is packedin bits 0-5. 
                                                   Month is packed in bits 6-9*/
    char radioClass;    /**< Radio class of the radio operator. Radio class is valid only if 
                                        it is 'A', 'G', 'N', 'P', 'T', or 'X', case sensitive. */
    char callSign[5];   /**< Call sign of radio operator. In order for the callsign to be valid,
                                        the first character must be 'K', 'W', or 'N', case sensitive.
                                        The 2nd, 4th, and 5th characters must be 'A'-'Z', case sensitive.
                                        Lastly, the 3rd character must be a digit 0-9. */
};
#pragma pack (pop)

 /*******************************************************************************
  *                         Function Prototypes
  ******************************************************************************/
// Required Functions for part a of program 1
int get5DigitZip( ZIPCODE zip );
int get4DigitZip( ZIPCODE zip );
int getDay( DATE date );
int getMonth( DATE date );
int getYear( DATE date );
bool validAddress( char* str );
bool validCallSign1( char ch );
bool validCallSign2( char* arr );
bool validCallSign3( char* arr ); 
bool validCallSign4( char* arr ); 
bool validDay( DATE date ); 
bool validMonth( DATE date ); 
bool validYear( DATE date ); 
bool beforeDate( DATE lhsDate, DATE rhsDate ); 
bool validName( char* str );
bool validRadioClass( char ch );   
bool validState( char* arr ); 
bool validZip4( ZIPCODE zipcode ); 
bool validZip5( ZIPCODE zipcode );



// prototypes for part b of program 1
bool validAprJunSepNovDay( DATE date );
void validAddressInfo( Record radioRecord, vector<string>& errors );
void validBirthInfo( Record radioRecord, vector<string>& errors );
void validLicenseInfo( Record radioRecord, vector<string>& errors );
void validExpirationInfo( Record radioRecord, vector<string>& errors );
void validRadioOperatorInfo( Record radioRecord, vector<string>& errors );
void validDateInfo( Record radioRecord, vector<string>& errors );
void printTextRecords( Record radioRecord, vector<string> error, ofstream& textOut );
void printBinaryRecords( Record radioRecord, ofstream& binOut );
void processRecords( ifstream& binIn, ofstream& binOut, ofstream& textOut );
void closeFiles(ifstream& binIn, ofstream& binOut, ofstream& textOut);


#endif
