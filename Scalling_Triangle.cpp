//Scaling of triangle using  starting and ending points

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

int main(){
	
	
	float x,y,x0,y0,x1,y1,x2,y2,sx,sy;
	int i;

	cout<<"Enter the value of first point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the value of second point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of third point (x2,y2): ";
	cin>>x2>>y2;
	cout<<"Enter the value of scaling factor (sx,sy): ";
	cin>>sx>>sy;
    int gd=DETECT,gm;
	initgraph(&gd,&gm,(char *)" ");

	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	//triangle before scaling
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x0,(screenHeight/2)-y0);
	
    outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before scaling");
	//calculating the scaled coordinates
	x0=x0*sx;
	y0=y0*sy;
	x1=x1*sx;
	y1=y1*sy;
	x2=x2*sx;
	y2=y2*sy;

	setcolor(GREEN);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x0,(screenHeight/2)-y0);
	
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After scaling");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
}