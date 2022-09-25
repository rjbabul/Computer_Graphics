//Digital clock
#include <bits/stdc++.h>
#include <time.h>
#include <graphics.h>
using namespace std;
int main()
{
	int gd = DETECT, gm;
	long current_time;
    // char timeStr[256];
     string timeStr;
     string tstatus="AM";
     string digit="DIGITAL WATCH";
     string datestr;
    int midx, midy;
	// Initialize of gdriver
	initgraph(&gd, &gm, (char*)" ");
	
    /* mid pixel in horizontal and vertical axis */
    int screenWidth=GetSystemMetrics(SM_CXSCREEN);
     int screenHeight=GetSystemMetrics(SM_CYSCREEN);
    midx = screenWidth / 2;
    midy = screenHeight / 2;
    
    /* Get Current epoch time in seconds */
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // stores the local time of the computer.

    int seconds = (timePtr->tm_sec);
    int minutes = (timePtr->tm_min);
    int hrs = (timePtr->tm_hour);
    int month= (timePtr->tm_mon);
    int date= (timePtr->tm_mday);
    int year= (timePtr->tm_year)%100+2000;

    while (!kbhit()) {
    	
        cleardevice();
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
	    rectangle(midx - 255, midy - 105, midx + 255, midy + 105);
        floodfill(midx,midy,BLACK);
        
        
        setfillstyle(LTSLASH_FILL, BLACK);
        // Clock inner Outline
	     rectangle((midx - 250) , (midy - 100)+5,(midx + 250) , (midy + 100)-5);
        //floodfill(midx, midy, BLACK);
      
       // Name of watch 

        setcolor(GREEN);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR,6);
        moveto(midx, midy-200);
        outtext((char*)digit.c_str());
        
       // Set Time 
        setcolor(RED);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 10);
        moveto(midx, midy+10);
        timeStr=to_string(hrs)+":"+to_string(minutes)+":"+to_string(seconds)+" "+tstatus;
        outtext((char*)timeStr.c_str());

        //Set Date
        setcolor(BLUE);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 8);
        moveto(midx, midy+200);
        datestr=to_string(date)+":"+to_string(month)+":"+to_string(year);
        outtext((char*)datestr.c_str());
        cout<<date<<"  "<<month<<"   "<<year<<endl;
        //increment sec min and hours
        seconds++;
        if (seconds >= 60)
        {
            seconds = 1;
            minutes++;
        }
        // This increases the minutes
        if (minutes >= 60)
        {
            minutes = 0;
            hrs++;
        }
        // This increases the hours
        if (hrs > 24)
        {
            hrs = 00;
        }
        if(hrs>12)
        {
        	hrs=hrs-12;
        	tstatus="PM";
		}

       //Add delay of 1000 milliseconds(1 second)
        delay(1000);
    }

	// Hold the screen for a while
	getch();

	// Close the initialized gdriver
	closegraph();
}
