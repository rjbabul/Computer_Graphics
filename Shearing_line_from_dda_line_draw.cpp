//DDA Line draw
//shearing
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
	
	float x,y,x0,y0,x1,y1,dx,dy,XIncrement,YIncrement,step,shx,shy;
	
	//graphics driver

	
	//dda algorithm
	
	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of shearing parameter (shx,shy): ";
	cin>>shx>>shy;
		int gd=DETECT,gm;
	initgraph(&gd,&gm,(char *)" ");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	 
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	
	if(dx>dy)
	{
		step=dx;
	}
	else
	{
		step=dy;
	}
	
	XIncrement = (x1-x0)/step;
	YIncrement = (y1-y0)/step;
	
	x=x0;
	y=y0;
	
//	cout<<"x\ty"<<endl;	
    
    for(int i=0;i<=step;i++)
    {

        setcolor(GREEN);
        putpixel((screenWidth/2)+((int) (x+0.5)),(screenHeight/2)-((int)(y+0.5)),GREEN);
        
        outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "before shearing");
        
        //shearing x-axis
        setcolor(BLUE);
        putpixel((screenWidth/2)+((int) (x+shx*y)),(screenHeight/2)-((int)(y)),BLUE);
        outtextxy((screenWidth/2)+x1+shx*y1+10,(screenHeight/2)-y1-10, "after shearing(x-axis)");
        outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

    	x=x+XIncrement;
    	y=y+YIncrement;
	}
    
	getch();
	closegraph();
	

}