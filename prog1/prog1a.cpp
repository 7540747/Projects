/** ***************************************************************************
 * @file
 *
 * @brief Contains all functions written for part a of Program 1
 *****************************************************************************/
#include "prog1.h"

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take an unsigned integer and extract the 5 digit zipcode from the bits.
 * The 5 digit zipcode is compressed in bits 14-31.
 *
 * @param[in] zip - unsigned integer with 5 digit zip and 4 digit zip compressed inside 
 * 
 * @returns extracted5Zip - extracted 5 digit zipcode
 ******************************************************************************/
// write functions for prog1 a here
int get5DigitZip( ZIPCODE zip )
{
    //Initialize varaibles
    ZIPCODE zip5Mask = 0xFFFFC000;
    ZIPCODE extracted5Zip;


    //Extract upper zipcode
    extracted5Zip = zip & zip5Mask;
    extracted5Zip = extracted5Zip >> 14;
    

    //Return 5 digit zip from extracted bits
    return extracted5Zip;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take an unsigned integer and extract the 4 digit zipcode from the bits.
 * The 4 digit zipcode is compressed in bits 0-13.
 *
 * @param[in] zip - unsigned integer with 5 digit zip and 4 digit zip compressed inside 
 * 
 * @returns extracted4Zip - extracted 4 digit zipcode
 ******************************************************************************/
int get4DigitZip( ZIPCODE zip )
{
    //Initialize varaibles
    ZIPCODE zip4Mask = 0x3FFF;
    ZIPCODE extracted4Zip;


    //Extract upper zipcode
    extracted4Zip = zip & zip4Mask;


    //Return 4 digit zip from extracted bits
    return extracted4Zip;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take an unsigned integer and extract the day from the bits.
 * The day is compressed in bits 0-5
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns extractedDay - extracted day
 ******************************************************************************/
int getDay( DATE date )
{
    //Initalize variables
    DATE dayMask = 0x3F;
    DATE extractedDay;


   //Extract day
    extractedDay = date & dayMask;


    //Return day from extracted bits
    return extractedDay;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take an unsigned integer and extract the 4 digit zipcode from the bits.
 * The 4 digit zipcode is compressed in bits 0-13.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns extractedMonth - extracted month
 ******************************************************************************/
int getMonth( DATE date )
{
    //Initalize variables
    DATE monthMask = 0x3C0;
    DATE extractedMonth;


    //Extract month
    extractedMonth = date & monthMask;
    extractedMonth = extractedMonth >> 6;


    //Return month from extracted bits
    return extractedMonth;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take an unsigned integer and extract the 4 digit zipcode from the bits.
 * The 4 digit zipcode is compressed in bits 0-13.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns extractedYear - extracted year
 ******************************************************************************/
int getYear( DATE date )
{
    //Initalize variables
    DATE yearMask = 0xFFF000;
    DATE extractedYear;


    //Extract year
    extractedYear = date & yearMask ;
    extractedYear = extractedYear >> 12;


    //Return  year from extracted bits
    return extractedYear;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take a character array and check each character to validate the array
 * as a valid address. An address is valid only if it contains the characters
 * A-Z, a-z, 0-9, ' ', '.', or '#'
 *
 * @param[in] str - character array holding the last known address of the operator
 * 
 * @returns true - valid address
 * @returns false - invalid address
 ******************************************************************************/
// write functions for prog1 a here
bool validAddress( char* str )
{
    //Initialize variables
    char* chptr = nullptr;
    size_t count = 0;


    //Set ptr to first character in string
    chptr = &str[count];
    while ( count < strlen(str) && true )
    {
        //Check for invalid characters in cstring
        if ( !isalnum( *chptr ) && !isspace( *chptr ) && *chptr != '.' && *chptr != '#' )
            return !true;
        else
            count++;


        //Update pointer position in cstring
        chptr = &str[count];
    }

    
    //Return if string is valid
    return true;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the first character of the radio operator's call sign to check if
 * it is valid. The character is valid only if it is 'K', 'W', or 'N', case insensitive.
 *
 * @param[in] ch - first character of radio operator callsign 
 * 
 * @returns true - valid character
 * @returns false - invalid character
 ******************************************************************************/
bool validCallSign1( char ch )
{
    //Check for valid character is 'K', 'k', 'W', 'w', 'N', or 'n'
    if ( ( toupper(ch) == 'K' ) || ( toupper(ch) == 'W' ) || ( toupper(ch) == 'N' ) )
        return true;
    else
        return !true;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function checks that the 2nd, 4th, and 5th characters of the callsign are 
 * A-Z or a-z.
 *
 * @param[in] arr - a character array containing radio operator callsign
 * 
 * @returns true - valid characters
 * @returns false - invalid characters
 ******************************************************************************/
//Fixing valid call sign 2
//Did not account for characters being valid and others invalid
bool validCallSign2( char* arr )
{
    //Initialize variables
    char* ptrTo1 = nullptr;
    char* ptrTo3 = nullptr;
    char* ptrTo4 = nullptr;


    //Set pointers to 1st, 3rd, and 4th array index
    ptrTo1 = &arr[1];
    ptrTo3 = &arr[3];
    ptrTo4 = &arr[4];
    

    //Check each index for valid character 'A'-'Z' or 'a'-'z'
    if ( isalpha( *ptrTo1 ) && isalpha( *ptrTo3 ) && isalpha( *ptrTo4 ) )
        return true;
    else
        return !true;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will check that the 3rd character in the operator's callsign is a digit 0-9
 *
 * @param[in] arr - a character array containing radio operator callsign
 * 
 * @returns true - valid character
 * @returns false - invalid character
 ******************************************************************************/
bool validCallSign3( char* arr )
{
    //Initialize variables
    char* ptrTo2 = nullptr;


    //Set pointer to 2nd array index
    ptrTo2 = &arr[2];


    //Check if it is a valid digt 0 - 9
    if ( isdigit( *ptrTo2 ) )
        return true;
    else
        return !true;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will check that the 1st, 2nd, 4th, and 5th characters of the operator's
 * callsign is uppercase.
 *
 * @param[in] arr - a character array containing radio operator callsign
 * 
 * @returns true - uppercase character
 * @returns false - non-uppercase character
 ******************************************************************************/
bool validCallSign4( char* arr )
{
    //Initialize variables
    char* ptrTo0 = nullptr;
    char* ptrTo1 = nullptr;
    char* ptrTo3 = nullptr;
    char* ptrTo4 = nullptr;


    //Set pointers to 0, 1, 3, and 4 indices
    ptrTo0 = &arr[0];
    ptrTo1 = &arr[1];
    ptrTo3 = &arr[3];
    ptrTo4 = &arr[4];


    //Check if it is a valid character between A-Z (65-90) 
    if ( isupper( *ptrTo0 ) && isupper( *ptrTo1 )
        && isupper( *ptrTo3 ) && isupper( *ptrTo4 ) )
        return true;
    else
        return !true;
}


/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will extract the day and month to check if the day is valid. The day
 * is valid if it is the range 1-31 or if the month is February, 1-28, inclusive and not 
 * accounting for leap years.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns true - valid day 
 * @returns false - invalid day 
 ******************************************************************************/
bool validDay( DATE date )
{
    //Initialize variables
    int day;
    int month;


    //Get day and month from date
    day = getDay( date );
    month = getMonth( date );


    //Test if month is february with 28 days
    //Other months have 31 days
    if ( month == 2 )
    {
        if ( day >= 1 && day <= 28 )
            return true;
        else
            return !true;
    }
    else if ( day >= 1 && day <= 31 )
        return true;
    else
        return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will extract the month from the date and check if it is a valid month.
 * A month is valid only if it is in the range 1-12 inclusive.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns true - valid month 
 * @returns false - invalid month 
 ******************************************************************************/
bool validMonth( DATE date )
{
    //Initialize variables
    int month;


    //Get month
    month = getMonth( date );


    //Check if month is valid or not
    if ( month >= 1 && month <= 12 )
        return true;
    else
        return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will extract the year from the date and check that it is a valid year.
 * A year is only valid if it is in the range 1900-2021 inclusive.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside
 * 
 * @returns true - valid year 
 * @returns false - invalid year 
 ******************************************************************************/
bool validYear( DATE date )
{
    //Initialize variables
    int year;


    //Get year from date
    year = getYear( date );


    //Check if year is valid between 1900 - 2021
    if ( year >= 1900 && year <= 2021 )
        return true;
    else
        return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This functions will take two dates as arguments. Then the function extracts the day,
 * month, and year of each side. Then it compares the left hand side (lhs)
 * date to the right hand side (rhs) date.
 *
 * @param[in] lhsDate - the date on the left
 * @param[in] rhsDate - the date on the right
 * 
 * @returns true - the left side date is earlier than the right date 
 * @returns false - the right date is earlier than the left date 
 ******************************************************************************/
bool beforeDate( DATE lhsDate, DATE rhsDate )
{
    //Initialize variables
    int lhsDay;
    int lhsMonth;
    int lhsYear;
    int rhsDay;
    int rhsMonth;
    int rhsYear;


    //Get day, month, and year from each date
    lhsDay = getDay( lhsDate );
    lhsMonth = getMonth( lhsDate );
    lhsYear = getYear( lhsDate );
    rhsDay = getDay( rhsDate );
    rhsMonth = getMonth( rhsDate );
    rhsYear = getYear( rhsDate );


    //Check if lhs Date is less than, greater than, or equal to rhs Date
    if ( lhsYear < rhsYear )
        return true;
    else if ( lhsYear > rhsYear )
        return !true;
    else
    {
        if ( lhsMonth < rhsMonth )
            return true;
        else if ( lhsMonth > rhsMonth )
            return !true;
        else
        {
            if ( lhsDay < rhsDay )
                return true;
            else if ( lhsDay > rhsDay )
                return !true;
            else
                return true;
        }
    }
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take a c-string and check each character is valid. A character is valid
 * only if it is A-Z, a-z, '.', or ' '
 *
 * @param[in] str - c-string containing the radio operator's name
 * 
 * @returns true - valid name
 * @returns false - invalid name 
 ******************************************************************************/
bool validName( char* str )
{
    //Check if valid char A-Z, a-z, '.', or ' '
    while ( *str != '\0' )
    {
        if ( isalpha( *str ) || *str == '.' || *str == ' ' )
            str++;
        else
            return !true;
    }


    return true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the radio class of the operator and check that is a valid
 * character. The radio class is valid only if it is 'A', 'G', 'N', 'P', 'T', or 'X'.
 *
 * @param[in] ch - the radio class of the operator
 * 
 * @returns true - valid radio class
 * @returns false - invalid radio class 
 ******************************************************************************/
//Fixing valid radio class
//Did not account for lowercase radio class letters
bool validRadioClass( char ch )
{
    //Is valid if 'A', 'G', 'N', 'P', 'T', or 'X'
    if ( toupper(ch) == 'A' || toupper(ch) == 'G' || toupper(ch) == 'N' ||
        toupper(ch) == 'P' || toupper(ch) == 'T' || toupper(ch) == 'X' )
        return true;
    else
        return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will check that the character array passed in a valid
 * abbreviation of one of the 50 states. 
 *
 * @param[in] arr - character array holding the state abbreviation of the radio operator
 * 
 * @returns true - valid state abbreviation 
 * @returns false - invalid state abbreviation
 ******************************************************************************/
//Fixing valid state function
//Was not accounting for one valid letter and an invalid letter
bool validState( char* arr )
{
    //Initialize variables
    char states[50][2] = { {'A', 'L'},{'A','K'},{'A','Z'},{'A','R'},{'C','A'},
        {'C','O'},{'C','T'}, {'D','E'},{'F','L'},{'G','A'},{'H','I'},{'I','D'},
        {'I','L'},{'I','N'},{ 'I','A'},{'K','S'}, {'K','Y'},{'L','A'},{'M','E'},
        {'M','D'},{'M','A'},{'M','I'},{'M','N'},{'M','S'},{'M','O'},
        {'M','T'},{'N','E'},{'N','V'},{'N','M'},{'N','Y'},{'N','C'},{'N','D'},
        {'N','H'}, {'N','J'}, {'O','H'},{'O','K'},{'O','R'},{'P','A'},{'R','I'},
        {'S','C'},{'S','D'},{'T','N'},{'T','X'}, {'U','T'},{'V','T'}, {'V', 'A'},
        {'W', 'A'}, {'W', 'V'},  {'W', 'I'}, {'W', 'Y'} };
    int i;
    int difference1 = 0;
    int difference2 = 0;


    //Compare all states to state provided
    for ( i = 0; i < 50; i++ )
    {
        difference1 = states[i][0] - toupper( arr[0] );
        difference2 = states[i][1] - toupper( arr[1] );
        if ( difference1 == 0 && difference2 == 0 )
            return true;
    }


    return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will extract the 4 digit zipcode and check that it is a valid zipcode.
 * The zipcode is valid only if it 0 or in the range 1000-9999 inclusive
 *
 * @param[in] zipcode - unsigned integer containing the 5 digit zip and the 4 digit zip
 * 
 * @returns true - valid zipcode 
 * @returns false - invalid zipcode 
 ******************************************************************************/
//Fixing validate 4 digit zip
//Did not account for zip being 0
bool validZip4( ZIPCODE zipcode )
{
    //Initialize variables
    ZIPCODE zip4;

    
    //Get zipcode
    zip4 = get4DigitZip( zipcode );


    //Test if valid zip between 1000 - 9999 or 0
    if ( (zip4 >= 1000 && zip4 <= 9999) || zip4 == 0)
        return true;
    else
        return !true;
}

/**************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will extract the 5 digit zipcode and check that it is a valid zipcode.
 * The 5 digit zipcode is valid only if it is in the range 10000-99999
 *
 * @param[in] zipcode - unsigned integer containing the 5 digit zip and the 4 digit zip
 * 
 * @returns true - valid zipcode
 * @returns false - invalid zipcode 
 ******************************************************************************/
bool validZip5( ZIPCODE zipcode )
{
    //Initialize variables
    ZIPCODE zip5;


    //Get zipcode
    zip5 = get5DigitZip( zipcode );


    //Test if valid zip between 10000 - 99999
    if ( zip5 >= 10000 && zip5 <= 99999 )
        return true;
    else
        return !true;
}
