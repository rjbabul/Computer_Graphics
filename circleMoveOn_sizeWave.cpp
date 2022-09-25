#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

void call(int midx, int midy){
    
     line(0, midy, midx*2, midy);
    line(midx, 0, midx, midy*2);
float x, y;
float pi = 3.14;
    for(int i = -360; i < 360 ; i++)
        {
            x = (int) midx+i;
            y = (int) midy - sin(i*pi/100)*25;
            putpixel(x,y,WHITE);
        }

}
int main()
{

    float x1,y1, x2,y2,x0,y0;
    float dx, dy;
    int steps, x, y;

    
    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
     
    int midx= width/2;
    int midy = height/2;

    x1= midx+x1;
    x2= midx+x2;
    y1= midy-y1;
    y2= midy-y2;
    
    int gd ,gm;
    initgraph(&gd, &gm, (char *)" ");
     
    float pi = 3.14;
    line(0, midy, width, midy);
    line(midx, 0, midx, height);
    delay(2000);

for(int i = -360; i < 360 ; i++)

{

      x = (int) midx+i;

      y = (int) midy - sin(i*pi/100)*25;

      putpixel(x,y,WHITE);

      setcolor(GREEN);
      circle(x, y, 20);
      
      delay(20);
      cleardevice();
      call(midx, midy);

}
   
    getchar();
    closegraph();
    return 0;
}