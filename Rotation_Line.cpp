 
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	

 
float x,y,x1,y1,x2,y2,step,xIncrement,yIncrement,dx,dy,angle,c,s,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
 

cout<<"Enter 1st point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter 2nd point (x2,y2): ";
cin>>x1>>y1;
cout<<"Enter Rotation Angle: ";
cin>>angle;

int gd=DETECT,gm;
initgraph(&gd,&gm,(char*)" ");
dx=x2-x1;
dy=y2-y1;

if(abs(dx)>abs(dy))
    step=abs(dx);
else
    step=abs(dy);

xIncrement=dx/step;
yIncrement=dy/step;

x=x1;
y=y1;

 
c=cos(angle*3.14/180.0);
s=sin(angle*3.14/180.0);

float xr, yr;
int i=1;
do
{
   
    
    putpixel(x,y,RED);

    xr= x*c+y*s;
    yr=(x)*s+y*c;

    putpixel(xr,yr,GREEN);  
   
    x=x+xIncrement;
    y=y+yIncrement;
}while(i++<=step);
 
getch();
closegraph();

}