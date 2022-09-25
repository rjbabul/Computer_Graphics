#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void dda(float x1, float y1, float x2, float y2, int color){
     float dx, dy,x_inc, y_inc;
     float steps;
     dx = (x2-x1);
     dy =(y2-y1);
         
     steps= max(abs(dy),abs(dx));

     x_inc = dx/steps;
     y_inc = dy/steps;
     int i=1;
     do{
        putpixel(x1,y1,color);
        putpixel(x1,y1+1,color);
        putpixel(x1-1,y1,color);
        x1+=x_inc;
        y1+= y_inc;
        i++;

     }while(i<=steps);
}

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

int main()
{
    float x1, y1, x2, y2;
    
    
    cout<<"Enter start Point (x1, y1) :";
    cin>>x1>>y1;

    cout<<"Enter End Point (x2, y2) :";
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
     outtextxy(x1+5,y1+10,"Starting point");
     setcolor(WHITE);
     outtextxy(x2+5,y2+10,"Ending Point");

    ///  dda function call
    dda(x1, y1, x2, y2, RED);



    // cloase graph 
    getch();
    closegraph();


    return 0;
}