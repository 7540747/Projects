/** ***************************************************************************
 * @file
 *
 * @brief Contains all functions written for part b of Program 1
 *****************************************************************************/
#include "prog1.h"

 /***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will get the date of the month if it is either April, June, September, or
 * November. The function will then validate that the day is in the range 1-30.
 *
 * @param[in] date - unsigned integer with the day, month, and year compressed inside 
 * 
 * @returns true - the day is a valid day in April, June, September, or November
 * @returns false - the day is an invalid day in April, June, September, or November
 ******************************************************************************/
bool validAprJunSepNovDay( DATE date )
{
    int day = getDay( date );

    if ( day >= 1 && day <= 30 )
        return true;
    else
        return false;
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the address information of the radio operators record. The
 * function will then check each part of the address using the functions written in part
 * a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validAddressInfo( Record radioRecord, vector<string>& errors )
{
    //Check for valid address
    if ( !validAddress( radioRecord.address ) )
    {
        errors.push_back( "Invalid character in address field" );
    }
    //Check for valid city
    if ( !validName( radioRecord.city ) )
    {
        //Write error
        errors.push_back( "Invalid character in city field" );
    }
    //Check for valid state
    if ( !validState( radioRecord.state )  )
    {
        //Write error
        errors.push_back( "Invalid State Code" );
    }
    if ( !isupper( radioRecord.state[0] ))
    {
        //Write error
        errors.push_back( "First character of state is not capitalized" );
    }
    //Check for valid 4 digit zipcode
    if ( !validZip4( radioRecord.zipCode ) )
    {
        //Write error
        errors.push_back( "Invalid 4 digit zip" );
    }
    //Check for valid 5 digit zipcode
    if ( !validZip5( radioRecord.zipCode ) )
    {
        //Write error
        errors.push_back( "Invalid 5 digit zip" );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the birth information of the radio operators record. The
 * function will then check each part of the birth information using the functions written in 
 * part a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validBirthInfo( Record radioRecord, vector<string>& errors )
{
    int month = getMonth( radioRecord.birthDate );

    //Check for valid name
    if ( !validName( radioRecord.name ) )
    {
        //Write error
        errors.push_back( "Invalid character in name field" );
    }
    //Check if valid day
    if ( validDay( radioRecord.birthDate ) )
    {
        //Check if valid day in the month of April, June, September, or November
        if ((month == 4 || month == 6 || month == 9 || month == 11)
            && !validAprJunSepNovDay(radioRecord.birthDate) )
            errors.push_back( "Inavlid day in birth date");
    }
    else
        errors.push_back( "Inavlid day in birth date");
    //Check if valid month
    if ( !validMonth( radioRecord.birthDate ) )
    {
        //Write error
        errors.push_back( "Invalid month in birth date" );
    }
    //Check if valid year
    if ( !validYear( radioRecord.birthDate ) )
    {
        //Write error
        errors.push_back( "Invalid year in birth date" );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the licensing information of the radio operators record. The
 * function will then check each part of the license information using the functions written in 
 * part a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validLicenseInfo(Record radioRecord, vector<string>& errors )
{
    int month = getMonth( radioRecord.licenseDate );

    //Check if valid day
    if ( validDay( radioRecord.licenseDate ) )
    {
        //Check if valid day in the month of April, June, September, or November
        if ((month == 4 || month == 6 || month == 9 || month == 11) 
            && !validAprJunSepNovDay(radioRecord.licenseDate) )
            errors.push_back( "Inavlid day in license date");
    }
    else
        errors.push_back( "Inavlid day in license date");
    //Check if valid month
    if ( !validMonth( radioRecord.licenseDate ) )
    {
        //Write error
        errors.push_back( "Invalid month in license date" );
    }
    //Check if valid year
    if ( !validYear( radioRecord.licenseDate ) )
    {
        //Write error
        errors.push_back( "Invalid year in license date" );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the expiration information of the license of the radio operator. The
 * function will then check each part of the expiration information using the functions written in 
 * part a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validExpirationInfo(Record radioRecord, vector<string>& errors )
{
    int month = getMonth( radioRecord.expirationDate );

    //Check if valid day
    if ( validDay( radioRecord.expirationDate ) )
    {
        //Check if valid day in the month of April, June, September, or November
        if ((month == 4 || month == 6 || month == 9 || month == 11) 
            && !validAprJunSepNovDay(radioRecord.expirationDate) )
            errors.push_back( "Inavlid day in expiration date");
    }
    else
        errors.push_back( "Inavlid day in expiration date");
    //Check if valid month
    if ( !validMonth( radioRecord.expirationDate ) )
    {
        //Write error
        errors.push_back( "Invalid month in expiration date" );
    }
    //Check if valid year
    if ( !validYear( radioRecord.expirationDate ) )
    {
        //Write error
        errors.push_back( "Invalid year in expiration date" );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take the Radio Operator's callsign and class information. The
 * function will then check each part of the callsign and class using the functions written in 
 * part a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validRadioOperatorInfo(Record radioRecord, vector<string>& errors )
{
    //Check if valid radio class
    if ( !validRadioClass( radioRecord.radioClass ) )
    {
        //Write error
        errors.push_back( "Invalid radio class" );
    }
    if ( !validCallSign1( radioRecord.callSign[0] ) )
    {
        //Write error
        errors.push_back( "Invalid first character in call sign" );
    }
    if ( !validCallSign2( radioRecord.callSign ) )
    {
        //Write error
        errors.push_back( "Invalid 2nd, 4th, or 5th character in call sign" );
    }
    if ( !validCallSign3( radioRecord.callSign ) )
    {
        //Write error
        errors.push_back( "Invalid digit in call sign" );
    }
    if ( !validCallSign4( radioRecord.callSign ) )
    {
        //Write error
        errors.push_back( "The alphabetic characters are not uppercase" );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take all date information in the operator's record. The function
 * will then verify the dates are of the correct timeline using the functions written in 
 * part a to validate the info. If any information is invalid, the function will write the erorr
 * to the error vector for output in the text file. 
 *
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * 
 * @returns none
 ******************************************************************************/
void validDateInfo( Record radioRecord, vector<string>& errors )
{
    if ( !beforeDate( radioRecord.birthDate, radioRecord.licenseDate ) )
    {
        //Write error
        errors.push_back( "Birth date is not before license date" );
    }
    if ( !beforeDate( radioRecord.licenseDate, radioRecord.expirationDate ) )
    {
        //Write error
        errors.push_back( "License date is not before expiration date");
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will print all records with errors to the correct text file along with
 * any corresponding errors in the record.
 * 
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] errors - a vector of strings holding all errors found in the record
 * @param[in] textOut - Output stream to write to text file
 * 
 * @returns none
 ******************************************************************************/
void printTextRecords( Record radioRecord, vector<string> errors, ofstream& textOut )
{
    //Initialize variables
    int i = 0;
    int j = 0;
    int zip4Code = get4DigitZip(radioRecord.zipCode);
    int zip5Code = get5DigitZip(radioRecord.zipCode);
    int birthDay = getDay(radioRecord.birthDate);
    int birthMonth = getMonth(radioRecord.birthDate);
    int birthYear = getYear(radioRecord.birthDate);
    int expDay = getDay(radioRecord.expirationDate);
    int expMonth = getMonth(radioRecord.expirationDate);
    int expYear = getYear(radioRecord.expirationDate);
    int liceDay = getDay(radioRecord.licenseDate);
    int liceMonth = getMonth(radioRecord.licenseDate);
    int liceYear = getYear(radioRecord.licenseDate);


    //Write record to file with errors indented below
    textOut << "Name: " << radioRecord.name << endl
        << "Address: " << radioRecord.address << endl
        << "City: " << radioRecord.city << endl
        << "State: " << radioRecord.state[0] << radioRecord.state[1] << endl
        << "Zipcode: " << setw(5) << setfill('0') 
            << zip5Code << "-" << setw(4) << setfill('0') << zip4Code << endl
        << "Birthdate: " << birthMonth << "/" << birthDay << "/" << birthYear << endl
        << "Expiration date: " << expMonth << "/" << expDay << "/" << expYear << endl
        << "License date: " << liceMonth << "/" << liceDay << "/" << liceYear << endl
        << "Radio class: " << radioRecord.radioClass << endl;
    textOut << "Call sign: ";
    while ( j < 5 )
    {
        textOut << radioRecord.callSign[j];
        j++;
    }
    textOut << endl << endl;
    while ( i < errors.size( ) ) 
    { 
        textOut << '\t' << right << errors.at( i ) << endl; 
        i++; 
    } 
    textOut << endl;
} 

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will take a record with no errors and write it to the new binary file.
 * 
 * @param[in] radioRecord - a single record of a Radio Operator 
 * @param[in] binOut - Output stream to write to binary file
 * 
 * @returns none
 ******************************************************************************/
void printBinaryRecords( Record radioRecord, ofstream& binOut )
{
    //Clear warnings and print to binary file 
    binOut.clear( );
    binOut.write( ( char* )&radioRecord, sizeof( Record ) );
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function is responsible for reading and processing each record one at a time. 
 * Each record is then checked for any errors.  If an error is found in the record, the
 * file will then be written to the text file. If there are no errors, the record will 
 * be written to the binary file. 
 * 
 * @param[in] binIn - Input stream to read from old binary file
 * @param[in] binOut - Output stream to write to new binary file
 * @param[in] textOut - Output stream to write to text file
 * 
 * @returns none
 ******************************************************************************/
void processRecords( ifstream& binIn, ofstream& binOut, ofstream& textOut )
{
    //Initialize variables
    Record radioRecord;
    vector<string> errors;


    //Clear file stream and read each record
    binIn.clear( );
    while ( binIn.read( ( char* )&radioRecord, sizeof( Record )  ) )
    {
        //Validate records
        validAddressInfo( radioRecord, errors );
        validBirthInfo( radioRecord, errors );
        validLicenseInfo( radioRecord, errors );
        validExpirationInfo( radioRecord, errors );
        validRadioOperatorInfo( radioRecord, errors );
        validDateInfo( radioRecord, errors );

        
        //Print the records to the correct files
        //if error vector's size is zero print binary else print text with error
        if ( errors.size( ) > 0 )
        {
            printTextRecords( radioRecord, errors, textOut );
        }
        else
        {
            printBinaryRecords( radioRecord, binOut );
        }
        

        //Clear errors vector to check next record
        errors.clear( );
    }
}

/***************************************************************************//**
 * @author Ricky E. Clark III
 *
 * @par Description:
 * This function will close all files opened in main
 * 
 * @param[in] binIn - Input stream to read from old binary file
 * @param[in] binOut - Output stream to write to new binary file
 * @param[in] textOut - Output stream to write to text file
 * 
 * @returns none
 ******************************************************************************/
void closeFiles( ifstream& binIn, ofstream& binOut, ofstream& textOut)
{
    binIn.close( );
    binOut.close( );
    textOut.close( );
}
