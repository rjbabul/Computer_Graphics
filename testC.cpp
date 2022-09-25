 
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawing_line(float x1, float y1, float x2, float y2, int color)
{
    float dx, dy, steps,x_inc, y_inc;

    dx= x2-x1;
    dy= y2-y1;
    if(abs(dx)>abs(dy)) steps = abs(dx);
    else steps= abs(dy);
    x_inc= dx/steps;
    y_inc= dy/steps;
    int i=1;
    
    do
    {
        putpixel(x1,y1,color);
       // cout<<x1<<"  "<<y1<<endl;
        x1+= x_inc;
        y1+= y_inc;
    } while (i++<=steps);
    
}

int main()
{
	
int gd=DETECT,gm;


float x,y,x1,y1,x2,y2,sh;
int i;

cout<<"Enter 1st point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter 2nd point (x2,y2): ";
cin>>x2>>y2;
initgraph(&gd,&gm,(char*)" ");

 float x0, y0, xmax=1360.0, ymax=700.0;

    x0= xmax/2 ;
    y0= ymax/2;
    

   x1+=x0;
   x2+=x0;
   y1=y0-y1;
   y2= y0-y2;
outtextxy(x1+10,y1-10, "start point");
outtextxy(x2+10,y2-10, "endi point");

drawing_line(0,y0, x0*2,y0, WHITE);
drawing_line(x0,0, x0,y0*2, WHITE);
 
drawing_line(x1,y1,x2,y2,GREEN);


getch();
closegraph();

}