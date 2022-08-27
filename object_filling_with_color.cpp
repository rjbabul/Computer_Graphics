#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm,(char*)" ");

   setcolor(RED);
   setfillstyle(HATCH_FILL, BLUE);
   circle(100,100,50);
   floodfill(100,100,RED);
   
   getch();
   closegraph();
   return 0;
}