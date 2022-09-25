#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

static int top= 8, LEFT = 1, r =2, bottom =4, xl, yl, xh, yh;

int getcode(int x, int y){
    int code=0;

    if(x<xl) code = code |  LEFT;

    if(x>xh) code = code |  r;
    if(y<yl) code|= bottom;
    if(y>yh)  code |= top;

    return code;
}
int main()
{
   
    int x1, x2, y1, y2;

    cout<<"Enter Bottom left point && top right point : ";cin>>xl>>yl>>xh>>yh;
    cout<<"Enter two ending point of line: "; cin>>x1>>y1>>x2>>y2;

    int gd=DETECT, gm;
    int width = GetSystemMetrics(SM_CXSCREEN); 
    int height = GetSystemMetrics(SM_CXSCREEN);
    int midx = width/2;
    int midy = height/2;
    


    initgraph(&gd, &gm, (char*)" ");
    setcolor(GREEN);
    line(0, midy, midx*2 , midy);
    line(midx, 0, midx, midy*2);
    rectangle (midx+x1, midy-y1,midx+x2, midy-y2 );
    

 

    
    int code1= getcode(x1, y1);
     int code2= getcode(x2, y2);


    

    getchar();
    closegraph();

    return 0;
}