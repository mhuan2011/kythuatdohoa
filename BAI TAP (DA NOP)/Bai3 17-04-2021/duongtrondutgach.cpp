
#include <iostream>
#include <graphics.h>
//#include <winbgim.h> 
#define Round(a) (int)(a+0.5)
using namespace std;
void lineDDA(int x1, int y1, int x2, int y2, int l){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x, y, 15);
      
    int k=1;
    int m = 0;
    while(k <=step){
    	k++;
    	x += x_inc;
	    y += y_inc;
    	if(m>l && m <(l+5)){
    		m++;
    		continue;
		}
		else if(m==(l+5)){
			m=0;
    		continue;
		}
		else {		
	        m++;           
	        putpixel(Round(x),Round(y),15);
		}
        
         
    }
}
void trucToaDo(){
	for(int i=0;i<600;i++){
		
		putpixel(300,i,15);
		putpixel(i,300,15);
		if(i%5==0){
			putpixel(i,299,15);
			putpixel(i,301,15);
			putpixel(299,i,15);
			putpixel(301,i,15);
			
			setcolor(15);
			//mui ten x
			line(300,0,290,10);
			line(300,0,310,10);
			//mui ten y
			line(600,300,590,290);
			line(600,300,590,310);
			
			outtextxy(320,20,"y");
			outtextxy(580,320,"x");
			outtextxy(270,310,"O");
			
			
		}
	}
}
void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int f = 1 - r;
	int i = 0;
	
    put8pixel(xc, yc, x, y, color);
	bool first = true;
    while (x < y)
    {
    	
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        if(i<=5 && !first){
        	put8pixel(xc, yc, x, y, color);
        	
		}
		if(i>5){
			
		}
		first = false;
		if(i==6) i=0;
		i++;
        
    }
}


int main()
{
    int gd = DETECT, gm;
    int r, x, y;  
    cout <<"Ban kinh: ";
    cin >> r;
    cout <<"Toa do tam O(x,y): ";
    cin >>x >>y;
    x=x+300;
    y=300-y;
    
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    trucToaDo();
    drawCircleMidpoint(x, y, r, 12);

	getch();
//    Sleep(3000); 
    closegraph();
    return 0;
}
