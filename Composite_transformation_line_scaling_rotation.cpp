#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){

float x,y,x1,y1,x2,y2,sx,sy,angle,s,c,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
int i;

cout<<"Enter 1st point (x1,y1): ";

cin>>x1>>y1;
cout<<"Enter 2nd point (x2,y2): ";
cin>>x1>>y1;
cout<<"Enter scaling factor (sx,sy): ";
cin>>sx>>sy;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;

int gd=DETECT,gm;
initgraph(&gd,&gm,(char*)" ");
 
//line before scaling
setcolor(RED);
line(x1,y1,x2,y2);

//calculating the  coordinates
x1=x1*sx;
y1=y1*sy;
x2=x2*sx;
y2=y2*sy;
 

c=cos(angle*3.14/180);
s=sin(angle*3.14/180);

firstpoint_x=abs(floor(x1*c+y1*s));  
firstpoint_y=abs(floor(-x1*s+y1*c));
lastpoint_x=abs(floor(x2*c+y2*s));
lastpoint_y=abs(floor(-x2*s+y2*c));

//after rotation

setcolor(GREEN);
line(firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y);


getch();
closegraph();

}