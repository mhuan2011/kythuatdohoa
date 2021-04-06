#include <iostream>
#include <graphics.h>
#include <math.h>
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define DELAY 10
#include <conio.h>
using namespace std ;
int color = WHITE;
   
void lineDDA(int x1, int y1, int x2, int y2, int l){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x, y, color);
      
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
	        
	 
	        putpixel(Round(x),Round(y),color);
		}
        
         
    }
}

// hien
void Mid_line(int x1, int y1, int x2, int y2, int c){ 
        int x, y, dx, dy,d; 
        y = y1; 
       dx = x2 - x1; 
       dy = y2 - y1; 
       d= dy - dx/2; 
       if(x1==x2){
       	while(y1<=y2){
       		putpixel(x1, y1++, c);
		   }
	   }else{
       for (x=x1; x<=x2; x++){ 
           putpixel(x, y, c); 
           if (d <= 0) 
                d = d + dy; 
          else { 
                y ++; 
               d = d + dy - dx; 
          }} 
      }
}

void veHCN(int xa, int ya, int xc, int yc, int color){
	int xb = xc;
	int yb = ya;
	while(ya <= yc){
		Mid_line(xa, ya, xb, yb, color);
		ya++;
		yb++;
		}
	}
	
int main(){
	int Ax, Ay, Bx, By;
    int length;
    cout << "---Toa do diem dau--- \n";
    cout <<"Ax = ";
    cin >> Ax;
    cout <<"Ay = ";
    cin >> Ay;
    cout << "---Toa do diem cuoi--- \n";
    cout <<"Bx = ";
    cin >> Bx;
    cout <<"By = ";
    cin >> By;
    cout << "Do dai dut gach:"; cin >> length;
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);        
    setcolor(255);
    settextstyle(10,0,2);
    outtextxy(100,10,"duong thang dut gach");
    
    lineDDA(Ax,Ay,Bx,By, length);      

    getch();
    return 0;
}
