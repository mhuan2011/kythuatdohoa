#include <graphics.h> 
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
#define Round(a) (int)(a+0.5)
#define max(a,b) (a>b)?a:b
int color = 1;
struct toaDo{
	int x;
	int y;
};
typedef struct toaDo toaDoDiem;
void v_lineDDA(int x1, int y1, int x2, int y2, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel(x, y, color);
      
    int k=1;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        putpixel(Round(x),Round(y),color);
         
    }
}
void v_lineDDA1(int x1, int y1, int x2, int y2, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel(x, y, color);
    int dem = 0;
    int k=1;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        if(dem % 5 == 0){
        	putpixel(Round(x),Round(y),color);	
		}
		dem++;
    }
}
void v_veTrucOxyz(){
	
	//Tam cua truc toa do o vi tri x = 450,  y = 400
	//Moi khoang cach la 5 pixel
	
	//ve truc toa do
    v_lineDDA(450, 400, 800, 400, color);//x
    v_lineDDA(450, 400, 270, 530, color);//z
    v_lineDDA(450, 400, 450, 100, color);//y
    
    //ve mui ten
    //truc Oz
    v_lineDDA(270, 530, 280, 510, color);
    v_lineDDA(270, 530, 290, 530, color);
    //truc Ox
    v_lineDDA(800, 400, 785, 385, color);
    v_lineDDA(800, 400, 785, 415, color);
    //truc Oy
    v_lineDDA(450, 100, 440, 120, color);
    v_lineDDA(450, 100, 460, 120, color);
    
    //hien x, y, z
    outtextxy(805, 405, "x");
	outtextxy(470, 100, "y");
	outtextxy(275, 535, "z");
	
	//cham diem pixel
	//truc Oy
	for (int i = 105; i<400; i++){
		if(i%5 == 0){
			putpixel(450, i, 15);
		}
	}
	//truc Ox
	v_lineDDA1(450, 400, 800, 400, 15);
	//truc Oz
	v_lineDDA1(450, 400, 270, 530, 15);
}
void layDoiXung(int x, int y, int z, int xTamDoiXung, int yTamDoiXung, int zTamDoiXung){
	if ((xTamDoiXung == 0)&&(xTamDoiXung == 0)&&(xTamDoiXung == 0)){
	x = -x;
	y = -y;
	z = -z;	
	}
	else{
	x += -xTamDoiXung;
	y += -yTamDoiXung;
	z += -zTamDoiXung;
	x = -x;
	y = -y;
	z = -z;
	x += xTamDoiXung;
	y += yTamDoiXung;
	z += zTamDoiXung;
	}
	cout << "Toa do diem doi xung cua Q: P(" << x <<","<< y <<","<< z <<")";
	outtextxy(450 + x*5 - z*3,400 - y*5 - z*3, "P"); 
}
int main(){
	initwindow(900, 600);	
	v_veTrucOxyz();
	int x, y, z;
	cout << "Nhap toa do diem Q(x,y,z):\n";
	cout <<"Nhap x: ";
	cin >> x;
	cout <<"Nhap y: ";
	cin >> y;
	cout <<"Nhap z: ";
	cin >> z;
	outtextxy(450 + x*5 - z*3,400 - y*5 - z*3, "Q");
	int x1, y1, z1;
	cout << "Nhap toa do tam doi xung A(x1,y1,z1):\n";
	cout <<"Nhap x1: ";
	cin >> x1;
	cout <<"Nhap y1: ";
	cin >> y1;
	cout <<"Nhap z1: ";
	cin >> z1;
	outtextxy(450 + x1*5 - z1*3,400 - y1*5 - z1*3, "A");
	layDoiXung(x, y, z, x1, y1, z1);
	getch();
}

