#include "arduino.h"
#include "OneNoteHelper.h"
#include "MinPosPrinter.h"
#include <time.h>

const std::wstring oauth_token = L"<PASTE YOUR TOKEN HERE>";

const int buttonPin = 29;
int buttonState = 0;
OneNoteHelper *One;
std::list<std::wstring> skipIDs;
MinPosPrinter * mpp = nullptr;

const std::wstring trailer = L"\r\n\r\n\r\n----------\r\n\r\n\r\n";
BYTE byteBuf[2048];

void PostToDo( void )
{
    // get current time
    char buf[80];
    time_t     now = time( 0 );
    struct tm  tstruct;
    localtime_s( &tstruct, &now );
    strftime( buf, sizeof( buf ), "%Y-%m-%d.%X", &tstruct );

    // Write a page
    std::string message = "";
    message += "<!DOCTYPE html><html><head><title>TODO</title><meta name = \"created\" content = \"2014-10-13T07:00:00.000-7:00\" /></head>";
    message += "<body>";
    message += "<p>";
    message += buf;
    message += "</p>";
    message += "<p>Buy: milk, bread<br/>Pick up: laundry, dog<br/>Clean: floors, car<br />Fix: sink, door<br/>Appt: 6pm football</p>";
    message += "</body>";
    message += "</html>";
    std::wstring wmessage = std::wstring( message.begin(), message.end() );
    One->PageWrite( wmessage );
}


bool PrintToDo( bool force )
{
    std::wstring respStr;

    // Read a page
    One->PageRead( respStr, skipIDs );

    if( force || respStr.length() )
    {
        // Print it
        One->StripMarkup( respStr );
        mpp->PrintReceipt( ref new Platform::String( respStr.c_str() ) );
    }

    return ( respStr.length() != 0 );
}

void setup()
{
    pinMode( buttonPin, INPUT );

    One = new OneNoteHelper();
    One->_showLog = true;
    One->OpenNotebook( NULL, NULL, L"TODO", oauth_token );
    One->GetPageIDs( skipIDs );

    mpp = new MinPosPrinter();

    PostToDo();
}

// the loop routine runs over and over again forever:
void loop()
{
    delay( 100 );

    // read the state of the pushbutton value:
    buttonState = digitalRead( buttonPin );
    if( buttonState == LOW ) {
        Log( L"Pushbutton pressed .. \n" );
        PrintToDo( true );
        delay( 500 );
    }
}