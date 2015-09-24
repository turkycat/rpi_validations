---
layout: default
title: OneNote cloud services
permalink: /en-US/win8/samples/TODO_Sample.htm
lang: en-US
---

# OneNote cloud services
Learn how to use http messages to Get and Post OneNote pages

# Create a new project

1. Create a new project from the template.
2. Replace the existing code in main.cpp with the following code. Make modifications for multiple action buttons as needed.
3. Add the following files to the project, MinHttpGP.cpp/.h, MinPosPrinter.cpp/.h, and OneNoteHelper.cpp/.h,
   found in [LINK TO REPO](https://github.com/ms-iot/sample-todo) <!-- TODO UPDATE LINK -->

# Code

### .ino sketch file
{% highlight C++ %}
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
  
{% endhighlight %}

   
# Generate tokens

Your Windows Live account is secure and protected. In order to access the OneNote capabilities of the Windows Live API, we need to generate an access token that will give your app permissions.

There are a few ways to do this, and the Windows Live APIs can give you more information on generating tokens within the app. For now though, we're going to generate and insert a token into our program manually.

1. Paste this web address into your favorite web browser: https://login.live.com/oauth20_authorize.srf?client_id=000000004812E454&scope=office.onenote%20wl.signin%20wl.basic%20office.onenote_create&response_type=token&redirect_uri=https:%2F%2Flogin.live.com%2Foauth20_desktop.srf
2. You may be prompted to log in to your Microsoft account if you are not already logged in.
3. Select "Yes" to generate the needed token.
4. The browser will navigate to a seemingly blank page. This is OK.
5. Examine the web address in the address bar of your browser, it may be easier to copy the entire address to a text file or other document before completing step 6.
6. The token is included in the web address. You will see `#access_token=` near the beginning of the address. Copy everything beginning after the `=` up to but not including `&token_type=`. This token will be quite long.
7. Paste the token value into the `const std::wstring oauth_token` string at the top of the .ino sketch (copied from above).


#Result

After deploying, you will be able to log in to OneNote live at [http://onenote.com/hrd](http://onenote.com/hrd) or open OneNote from your Windows Desktop and view a newly added "ToDo" page in your workbook!

If you also hook up a button to pin 29 (GPIO pin 5) and a simple POS printer, you can press the button to print your TODOs from your printer!

---

[&laquo; Return to Samples](SampleApps.htm){:role="button"}{:class="btn btn-default"}
