#include<bits/stdc++.h>
#include<graphics.h>

int main()
{
	int gd=DETECT,gm;
	
	initgraph(&gd,&gm,(char*)" ");
	 
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(100,100,50);
	floodfill(100,100,RED);
	

	getch();
	closegraph();
}