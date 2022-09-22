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


int main()

{
    int x1, x2, y1, y2,dx,dy,p0;
    cout<<"1st Point"<<endl;
    cin>>x1>>y1;
    cout<<"2nd Point"<<endl;
    cin>>x2>>y2;


   // graph initialization
     int screenWidth=GetSystemMetrics(SM_CXSCREEN);
     int screenHeight=GetSystemMetrics(SM_CYSCREEN);
     draw_plot(screenWidth, screenHeight);
     
     int midx = screenWidth/2;
     int midy= screenHeight/2;
     x1= midx+x1;
     x2= midx+x2;
     y1= midy-y1;
     y2= midy-y2;

     setcolor(WHITE);
     outtextxy(midx+20,midy+20,"(0,0)");
     setcolor(WHITE);
     outtextxy(x1+5,y1+5,"Starting point");
     setcolor(WHITE);
     outtextxy(x2+5,y2+5,"Ending Point");

    dx= x2-x1;
    dy= y2-y1;
    p0= 2*dy- dx;
   if(x2<x1){
    swap(x1,x2);
    swap(y1,y2);
   }
   cout<<x1<<"  "<<y1<<endl;
   cout<<x2<<"  "<<y2<<endl;

    do
    {
        
        putpixel(x1,y1,RED);
        putpixel(x1-1,y1,RED);
        putpixel(x1,y1-1,RED);
        
        if(p0<0)
            {
                p0= p0+ 2*dy;
                 
            }
        else
            {
               y1++;
               p0= p0+ 2*dy-2*dx; 
            }
        x1++;
      
    }while(x1<=x2);
  
    getch();
    closegraph();
    return 0;
}