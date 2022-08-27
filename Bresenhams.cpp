#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()

{
    int x1, x2, y1, y2,dx,dy,p0;
    cout<<"1st Point"<<endl;
    cin>>x1>>y1;
    cout<<"2nd Point"<<endl;
    cin>>x2>>y2;
    dx= x2-x1;
    dy= y2-y1;
    p0= 2*dy- dx;
    int gd= DETECT, gm;
    initgraph(&gd, &gm, (char*)" ");
    do
    {
        putpixel(x1,y1,GREEN);
        
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
      // cout<<x1<<" "<<y1<<endl;
    }while(x1<=x2);
  
    getch();
    closegraph();
    return 0;
}