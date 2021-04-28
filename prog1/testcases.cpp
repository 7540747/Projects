#include "prog1.h"
#include "..\catch.hpp"


TEST_CASE( "get5DigitZip - testing zipcode 57701" )
{
    ZIPCODE zip = 945373184;
    int actualZip = 57701;
    int unpackedZip;
    unpackedZip = get5DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
}


TEST_CASE( "get5DigitZip - testing zipcode 32119" )
{
    ZIPCODE zip = 526237696;
    int actualZip = 32119;
    int unpackedZip;
    unpackedZip = get5DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
}


TEST_CASE( "get5DigitZip - testing zipcode 94107" )
{
    ZIPCODE zip = 1541849088;
    int actualZip = 94107;
    int unpackedZip;
    unpackedZip = get5DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
} 


TEST_CASE( "get4DigitZip - testing zipcode 4313" )
{
    ZIPCODE zip = 552161497;
    int actualZip = 4313;
    int unpackedZip;
    unpackedZip = get4DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
}


TEST_CASE( "get4DigitZip - testing zipcode 0001" )
{
    ZIPCODE zip = 993755137;
    int actualZip = 0001;
    int unpackedZip;
    unpackedZip = get4DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
}


TEST_CASE( "get4DigitZip - testing zipcode 2716" )
{
    ZIPCODE zip = 361613980;
    int actualZip = 2716;
    int unpackedZip;
    unpackedZip = get4DigitZip( zip );

    REQUIRE( unpackedZip == actualZip );
}


TEST_CASE( "getDay - testing date 12/20/2001" )
{
    DATE date = 8196884;
    int actualDay = 20;
    int unpackedDay;
    unpackedDay = getDay( date );

    REQUIRE( unpackedDay == actualDay );
}


TEST_CASE( "getDay - testing date 4/30/1945" )
{
    DATE date = 7967006;
    int actualDay = 30;
    int unpackedDay;
    unpackedDay = getDay( date );

    REQUIRE( unpackedDay == actualDay );
}


TEST_CASE( "getDay - testing date 7/29/1890" )
{
    DATE date = 7741917;
    int actualDay = 29;
    int unpackedDay;
    unpackedDay = getDay( date );

    REQUIRE( unpackedDay == actualDay );
}


TEST_CASE( "getMonth - testing date 12/20/2001" )
{
    DATE date = 8196884;
    int actualMonth = 12;
    int unpackedMonth;
    unpackedMonth = getMonth( date );

    REQUIRE( unpackedMonth == actualMonth );
}


TEST_CASE( "getMonth - testing date 4/30/1945" )
{
    DATE date = 7967006;
    int actualMonth = 4;
    int unpackedMonth;
    unpackedMonth = getMonth( date );

    REQUIRE( unpackedMonth == actualMonth );
}


TEST_CASE( "getYear - testing date 4/30/1945" )
{
    DATE date = 7967006;
    int actualYear = 1945;
    int unpackedYear;
    unpackedYear = getYear( date );

    REQUIRE( unpackedYear == actualYear );
}


TEST_CASE( "getYear - testing date 12/20/2001" )
{
    DATE date = 8196884;
    int actualYear = 2001;
    int unpackedYear;
    unpackedYear = getYear( date );

    REQUIRE( unpackedYear == unpackedYear );
}


TEST_CASE( "getYear - testing date 7/29/1890" )
{
    DATE date = 7741917;
    int actualYear = 1890;
    int unpackedYear;
    unpackedYear = getYear( date );

    REQUIRE( unpackedYear == actualYear  );
}


TEST_CASE( "validAddress - passing valid address with no punctuation" )
{
    char str[50] = "603 12th ST Lot 1 Sturgis SD 57785";
    char origStr[50] = "603 12th ST Lot 1 Sturgis SD 57785";
    bool isValid = true;
    bool testedValid;

    testedValid = validAddress( str );
    CHECK( testedValid == isValid );
    CHECK( strcmp( str, origStr ) == 0 );
}


TEST_CASE( "validAddress - passing valid address with '.' punctuation" )
{
    char str[50] = "1974 25th Blvd. Lot 17 Tampa Bay Florida.";
    char origStr[50] = "1974 25th Blvd. Lot 17 Tampa Bay Florida.";
    bool isValid = true;
    bool testedValid;

    testedValid = validAddress( str );
    CHECK( testedValid == isValid );
    CHECK( strcmp( str, origStr ) == 0 );
}


TEST_CASE( "validAddress - passing invalid address with ',' punctuation" )
{
    char str[50] = "3425 Stone Street, Apt. 2A, Jacksonville";
    char origStr[50] = "3425 Stone Street, Apt. 2A, Jacksonville";
    bool isValid = false;
    bool testedValid;
    

    testedValid = validAddress( str );
    CHECK( testedValid == isValid );
    CHECK( strcmp( str, origStr ) == 0 );
}


TEST_CASE( "validAddress - passing valid address with '#' punctuation" )
{
    char str[50] = "70 Griffin Street Beltsville Lot# 16 MD 20705";
    char origStr[50] = "70 Griffin Street Beltsville Lot# 16 MD 20705";
    bool isValid = true;
    bool testedValid;
    

    testedValid = validAddress( str );
    CHECK( testedValid == isValid );
    CHECK( strcmp( str, origStr ) == 0 );
}


TEST_CASE( "validCallSign1 - passing both valid versions of character 'n' and 'N'")
{
    char ch1 = 'n';
    char ch2 = 'N';
    

    CHECK( validCallSign1( ch1 ) );
    CHECK(  validCallSign1( ch2 ) );
}


TEST_CASE( "validCallSign1 - passing both valid versions of character 'k' and 'K'")
{
    char ch1 = 'k';
    char ch2 = 'K';
    

    CHECK( validCallSign1( ch1 ) );
    CHECK(  validCallSign1( ch2 ) );
}


TEST_CASE( "validCallSign1 - passing both valid versions of character 'w' and 'W'")
{
    char ch1 = 'w';
    char ch2 = 'W';
    

    CHECK( validCallSign1( ch1 ) );
    CHECK(  validCallSign1( ch2 ) );
}


TEST_CASE( "validCallSign1 - passing invalid versions of characters 'p' and 'Z'")
{
    char ch1 = 'p';
    char ch2 = 'Z';
    

    CHECK( !validCallSign1( ch1 ) );
    CHECK(  !validCallSign1( ch2 ) );
}


TEST_CASE( "validCallSign1 - passing invalid versions of characters '&' and '!'")
{
    char ch1 = '&';
    char ch2 = '!';
    

    CHECK( !validCallSign1( ch1 ) );
    CHECK(  !validCallSign1( ch2 ) );
}


TEST_CASE( "validCallSign2 - passing valid versions of characters 'a', 'Y', and 'f'")
{
    int i;
    char arr[8] = {'$', 'a', '!', 'Y', 'f', '^', '=', '$'};
    char origArr[8] = {'$', 'a', '!', 'Y', 'f', '^', '=', '$'};
    

    CHECK( validCallSign2( arr ) );
    for ( i = 0; i < 8; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign2 - passing invalid versions of characters '%', '(', and '8'")
{
    int i;
    char arr[8] = {'$', '%', '!', '(', '8', '^', '=', '$'};
    char origArr[8] = {'$', '%', '!', '(', '8', '^', '=', '$'};
    

    CHECK( !validCallSign2( arr ) );
    for ( i = 0; i < 8; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign2 - passing valid versions of characters 'Z', 'U', and 'P'")
{
    int i;
    char arr[10] = {'$', 'Z', '!', 'U', 'P', '^', '=', '$'};
    char origArr[10] = {'$', 'Z', '!', 'U', 'P', '^', '=', '$'};
    

    CHECK( validCallSign2( arr ) );
    for ( i = 0; i < 10; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign3 - passing valid digit '9'")
{
    int i;
    char arr[16] = { 'g','y','9','6','x','A','a','W','k','6','i','t','G','Z','8','d' };
    char origArr[16] = { 'g','y','9','6','x','A','a','W','k','6','i','t','G','Z','8','d' };


    CHECK( validCallSign3( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign3 - passing invalid digit 'x'")
{
    int i;
    char arr[16] = { 'g','y','x','u','x','u','a','W','k','6','i','t','G','u','8','d' };
    char origArr[16] = { 'g','y','x','u','x','u','a','W','k','6','i','t','G','u','8','d' };


    CHECK( !validCallSign3( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign3 - passing valid digit '3'")
{
    int i;
    char arr[16] = { 'g','y','3','u','x','u','a','4','k','6','i','t','G','4','8','4' };
    char origArr[16] = { 'g','y', '3','u','x','u','a','4','k','6','i','t','G','4','8','4' };


    CHECK( validCallSign3( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign4 - passing valid characters 'A', 'B', 'C', 'D'")
{
    int i;
    char arr[16] = { 'A','B','3','C','D','u','a','4','k','6','i','t','G','4','8','4' };
    char origArr[16] = { 'A','B', '3','C','D','u','a','4','k','6','i','t','G','4','8','4' };


    CHECK( validCallSign4( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign4 - passing invalid characters 's', 'p', 'C', 'X'")
{
    int i;
    char arr[16] = { 's','p','3','C','X','u','a','4','k','6','i','t','G','4','8','4' };
    char origArr[16] = { 's','p', '3','C','X','u','a','4','k','6','i','t','G','4','8','4' };


    CHECK( !validCallSign4( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign4 - passing invalid characters '6', '8', '7', '7'")
{
    int i;
    char arr[16] = { '6','8','3','7','7','u','a','4','k','6','i','t','G','4','8','4' };
    char origArr[16] = { '6','8', '3','7','7','u','a','4','k','6','i','t','G','4','8','4' };


    CHECK( !validCallSign4( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validCallSign4 - passing 3 valid characters and one invalid 'T', 'E', 'o', 'Z'")
{
    int i;
    char arr[16] = { 'T','E','3','o','Z','u','a','4','k','6','i','t','G','4','8','4' };
    char origArr[16] = { 'T','E', '3','o','Z','u','a','4','k','6','i','t','G','4','8','4' };


    CHECK( !validCallSign4( arr ) );
    for ( i = 0; i < 16; i++ )
    {
        CHECK( arr[i] == origArr[i] );
    }
}


TEST_CASE( "validMonth - testing month 4/30/1945" )
{
    DATE date = 7967006;


    REQUIRE( validMonth( date ) );
}


TEST_CASE( "validMonth - testing month 12/20/2001")
{
    DATE date = 8196884;


    REQUIRE( validMonth( date ) );
}


TEST_CASE( "validMonth - testing invalid month 15/28/1979")
{
    DATE date = 8106972;


    REQUIRE( !validMonth( date ) );
}


TEST_CASE( "validDay - testing invalid day in month Feb. 2/31/2014")
{
    DATE date = 8249503;


    REQUIRE( !validDay( date ) );
}


TEST_CASE( "validDay - testing valid day 7/14/1903")
{
    DATE date = 7795150;


    REQUIRE( validDay( date ) );
}


TEST_CASE( "validDay - testing invalid day of July 7/14/1903")
{
    DATE date = 7795150;


    REQUIRE( validDay( date ) );
}


TEST_CASE( "validYear - testing valid year 7/14/1903")
{
    DATE date = 7795150;


    REQUIRE( validYear( date ) );
}


TEST_CASE( "validYear - testing invalid year 7/29/1890" )
{
    DATE date = 7741917;


    REQUIRE( !validYear( date ) );
}


TEST_CASE( "validYear - testing valid year 10/8/2021" )
{
    DATE date = 8278664;


    REQUIRE( validYear( date ) );
}


TEST_CASE( "beforeDate - testing valid years 10/8/2021 and  7/29/1890")
{
    DATE lhsDate = 8278664;
    DATE rhsDate = 7741917;


    REQUIRE( !beforeDate( lhsDate, rhsDate ) );
}


TEST_CASE( "beforeDate - testing valid years 12/20/2001 and 4/30/1945") 
{
    DATE lhsDate = 8196884;
    DATE rhsDate = 7967006;


    REQUIRE( !beforeDate( lhsDate, rhsDate ) );
}


TEST_CASE("validState - all 4 versions for sd")
{    
    int i;     
    char s[4][2] = { { 'S','D' }, { 's','D' }, { 's','d' }, { 'S', 'd' } };    
    char orig[4][2] = { { 'S','D' }, { 's','D' }, { 's','d' }, { 'S', 'd' } };    


    for (i = 0; i < 4; i++)    
    {       
        CHECK( validState(s[i]) == true);         
        CHECK( (s[i][0] == orig[i][0] && s[i][1] == orig[i][1] ));   
    }
}


TEST_CASE("validState - 4 versions of invalid states")
{    
    int i;     
    char s[4][2] = { { 'P','P' }, { 's','U' }, { 'x','y' }, { 'Q', 't' } };    
    char orig[4][2] = { { 'P','P' }, { 's','U' }, { 'x','y' }, { 'Q', 't' } };     


    for (i = 0; i < 4; i++)    
    {       
        CHECK( validState(s[i]) == false);         
        CHECK( (s[i][0] == orig[i][0] && s[i][1] == orig[i][1] ));   
    }
}


TEST_CASE("validName - 4 versions of valid names")
{    
    int i;
    int j;
    char names[4][10] = { {'R', 'i', 'c', 'k', 'y'},  {'J', 'o', 's', 'h'}, {'S', ' ', 'e', 'v', ' '}, {'H', 'a', '.', 'K'} };
    char origNames[4][10] = { {'R', 'i', 'c', 'k', 'y'},  {'J', 'o', 's', 'h'}, {'S', ' ', 'e', 'v', ' '}, {'H', 'a', '.', 'K'} };


    for ( i = 0; i < 4; i++ )
    {
        CHECK( validName( names[i] ) );
        for ( j = 0; j < 10; j++ )
        {
        CHECK( names[i][j] == origNames[i][j] );
        }
    }
}


TEST_CASE("validName - 4 versions of invalid names")
{    
    int i;
    int j;
    char names[4][10] = { {'*', 'i', 'c', 'k', 'y'},  {'J', '^', '%', 'h'}, {'S', '7', 'e', '8', 'e'}, {'H', 'a', 'n', '&'} };
    char origNames[4][10] = { {'*', 'i', 'c', 'k', 'y'},  {'J', '^', '%', 'h'}, {'S', '7', 'e', '8', 'e'}, {'H', 'a', 'n', '&'} };


    for ( i = 0; i < 4; i++ )
    {
        CHECK( !validName( names[i] ) );
        for ( j = 0; j < 10; j++ )
        {
        CHECK( names[i][j] == origNames[i][j] );
        }
    }
}


TEST_CASE("validRadioClass - 6 versions of valid characters")
{    
    int i;
    char ch[6] = { 'A', 'G', 'N', 'P', 'T', 'X' };


    for ( i = 0; i < 6; i++ )
    {
        CHECK( validRadioClass( ch[i]) );
    }
}


TEST_CASE("validRadioClass - 6 versions of invalid characters")
{    
    int i;
    char ch[6] = { 'b', '%', 'y', '2', '(', '!' };


    for ( i = 0; i < 6; i++ )
    {
        CHECK( !validRadioClass( ch[i]) );
    }
}


TEST_CASE("validZip4")
{    
    int i;
    ZIPCODE validZipcodes[5] = { 552161497,  361613980, 930437095, 1638385663, 253101056 };
    ZIPCODE invalidZipcodes[5] = {1072350179, 762085379, 1292895078, 898023804, 1362788609 };


    SECTION( "testing valid 4 digit zipcodes" )
    {
        for ( i = 0; i < 5; i++ )
        {
            CHECK( validZip4( validZipcodes[i] ) ); 
        }
    }
    SECTION( "testing invalid 4 digit zipcodes" )
    {
        for ( i = 0; i < 5; i++ )
        {
            CHECK( !validZip4( invalidZipcodes[i] ) );
        }
    }
} 


TEST_CASE("validZip5")
{    
    int i;
    ZIPCODE validZipcodes[5] = { 552161497,  361613980, 930437095, 1638385663, 253101056 };
    ZIPCODE invalidZipcodes[5] = {163827425, 88671759, 145033215, 18225, 69026913 };


    SECTION( "valid 5 digit zipcodes" )
    {
        for ( i = 0; i < 5; i++ )
        {
            CHECK( validZip5( validZipcodes[i] ) ); 
        }
    }
    SECTION( "invalid 5 digit zipcodes" )
    {
        for ( i = 0; i < 5; i++ )
        {
            CHECK( !validZip5( invalidZipcodes[i] ) );
        }
    }
} 


TEST_CASE( "validAprJunSepNov" )
{
    DATE date1 = 8253726; // 4/30/2015
    DATE date2 = 8254170; // 11/26/2015
    DATE date3 = 8085919; // 6/31/1974
    DATE date4 =8086143;  // 9/63/1974

    SECTION( "Valid days" )
    {
        REQUIRE( validAprJunSepNovDay( date1 ) == true );
        REQUIRE( validAprJunSepNovDay( date2 ) == true );
    }
    SECTION( "Invalid days" )
    {
        REQUIRE( validAprJunSepNovDay( date3 ) == false );
        REQUIRE( validAprJunSepNovDay( date4 ) == false );
    }
}
 