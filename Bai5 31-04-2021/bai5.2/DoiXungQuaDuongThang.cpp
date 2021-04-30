
#include <iostream>
#include <graphics.h>
#include <cmath>
//#include <winbgim.h> 
#define Round(a) (int)(a+0.5)
#define xo (int)300
#define yo (int)300
using namespace std;

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

int swap(int &xa, int &ya, int &xb, int &yb){
	int temp = xa;
	xa = xb;
	xb = temp;
	int temp2 = ya;
	ya = yb;
	yb = temp2;
}

void Mid_line(int x1, int y1, int x2, int y2, int c){ // su dung thuat toan mid point
		if(y1>y2){
			swap(x1, y1, x2, y2);	
		}
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
       for (x=x1; ;){ 
           putpixel(x, y, c); 
           if (d <= 0) 
                d = d + dy; 
          else { 
                	y ++;
               d = d + dy - dx; 
          }
		  if(x1<x2){
		  	x++;
		  	if(x>=x2) break;
		  }else {
		  	x--;
		  	if(x<=x2) break;
		  }
		  
		  } 
      }
}

void tinhTien(int &x, int &y,  int dx, int dy){
	x = x + dx;
	y = y + dy;
}

void phepQuay(int &x, int &y, float goc){
//	float radian = goc*3.1415/180;
float radian = goc;
	int x1 = x;
	int y1 = y;
	x = x1*cos(radian) - y1*sin(radian);
	y = x1*sin(radian) + y1*cos(radian);
	
}

void doiXungQuaOx(int &x, int &y){
	// vi goc toa do phu thuoc vao xo yo nen phai xet truong hop
	if(y<yo){
		y = y + 2*(yo - y) ;
	}else
	y = y - 2*(yo-y);
}

void doiXungQuaDuongThang(int &x, int &y, int xa, int ya, int xb, int yb){
	float goc = atan((float)(yb-ya)/(xa-xb)); // xac dinh goc quay de song song voi ox
	phepQuay(xa, ya, goc); // quay 1 diem cua duong thang de xac dinh sy can tinh tien
	phepQuay(x, y, goc);
	int dy;
	if(ya<yo) dy = abs(yo-ya);// xac dinh sy can dich chuyen
	else dy = -1*abs(yo-ya);
	tinhTien(x, y, 0, dy);
	doiXungQuaOx(x, y);
	tinhTien(x, y, 0 , -1*(dy));
	phepQuay(x, y, -1*(goc));
	
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    trucToaDo();
    // toa do diem
	int x = 3*5+xo,y = 3*5+yo; // vi moi don vi la 5 px nen * 5
	putpixel(x, y, 15);
	// toa do duong thang
	int x2 = -5*5+xo, y2=5*5+yo, x3 = 20*5+xo, y3=20*5+yo;
	Mid_line(x2, y2, x3, y3, 15);
	// tim diem doi xung qua duong thang
	doiXungQuaDuongThang(x, y, x2, y2, x3, y3);
	putpixel(x, y, 15);
	getch();
//    Sleep(3000); 
    closegraph();
    return 0;
}
