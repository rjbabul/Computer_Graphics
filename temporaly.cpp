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
    int cnt =0;
     for(int i= x/2+20; i<=x;i+=20){
        for(int j=y/2+20;j<=y;j+=20){
            setcolor(DARKGRAY);
            if(cnt%5==0)
                  setcolor(BROWN);
			line(0,j,x,j);
			line(i,0,i,y);
            cnt++;
        }
     } 
    cnt=0;
     for(int i= x/2-20; i>=0;i-=20){
        for(int j=y/2-20;j>=0;j-=20){
            setcolor(DARKGRAY);
            if(cnt%5==0)
                  setcolor(BROWN);
			line(0,j,x,j);
			line(i,0,i,y);
            cnt++;
        }
     } 

}


int main(){
	
	
	float r,xc,yc,tx,ty;
	int i;

	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the value of translation factor (tx,ty): ";
	cin>>tx>>ty;


	//window size measurement and initialization
    
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	 
 
	draw_plot(screenWidth,screenHeight);

    //Circle before translation

	setcolor(BLUE);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
	
    outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before translation");

	//Translation factor 
	xc=xc+tx;
	yc=yc+ty;

	setcolor(GREEN);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
    outtextxy((screenWidth/2)+xc+60,(screenHeight/2)-yc-10, "After translation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
}