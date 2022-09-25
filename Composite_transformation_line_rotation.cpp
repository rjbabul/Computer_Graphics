#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void draw_plot(int x,int y){
    int screenWidth=x;
    int screenHeight=y;
    
      int gd=DETECT, gm;
     initgraph(&gd, &gm, (char*)" ");
     
     
     setcolor(YELLOW);
     line(0,screenHeight/2, screenWidth,screenHeight/2 );
     setcolor(YELLOW);
     line(screenWidth/2,0, screenWidth/2,screenHeight );
  
     for(int i= x/2+20; i<=x;i+=20){
        for(int j=y/2+20;j<=y;j+=20){
            setcolor(DARKGRAY);
			line(0,j,x,j);
			line(i,0,i,y);
        }
     } 

     for(int i= x/2-20; i>=0;i-=20){
        for(int j=y/2-20;j>=0;j-=20){
            setcolor(DARKGRAY);
			line(0,j,x,j);
			line(i,0,i,y);
        }
     } 

}


int main(){

float x,y,x1,y1,x2,y2,sx,sy,angle,s,c,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
int i;

cout<<"Enter 1st point (x1,y1): ";

cin>>x1>>y1;
cout<<"Enter 2nd point (x2,y2): ";
cin>>x2>>y2;

cout<<"Enter Rotation Angle(a): ";
cin>>angle;

 // graph initialization
     int screenWidth=GetSystemMetrics(SM_CXSCREEN);
     int screenHeight=GetSystemMetrics(SM_CYSCREEN);
     draw_plot(screenWidth, screenHeight);
     
     float midx = screenWidth/2;
     float midy= screenHeight/2;
    
     setcolor(WHITE);
     outtextxy(midx+20,midy+20,"(0,0)");
     
// brefore ratation 

setcolor(RED);
line(midx+x1,midy-y1,midx+x2,midy-y2);
outtextxy(midx+x2+10,midy-y2-10,"Before Rotarion");
 
 

c=cos(angle*(3.14/180));
s=sin(angle*(3.14/180));

firstpoint_x=x1;  
firstpoint_y=y1;
lastpoint_x=abs(floor(x2*c-y2*s));
lastpoint_y=abs(floor(x2*s+y2*c));

//after rotation

setcolor(GREEN);
line(midx+firstpoint_x,midy-firstpoint_y,midx+lastpoint_x,midy-lastpoint_y);
outtextxy( midx+lastpoint_x+10,midy-lastpoint_y-10,"After Rotation");



getch();
closegraph();

}