#include "graphics.h"
#include <iostream>
using namespace std;
int lamTron(float x){
	return x+0.5;
}
void dline(int x1,int y1, int x2,int y2, int color) { 
   float y; 
   int x; 
   for (x=x1; x<=x2; x++) { 
         y = y1 + (x-x1)*(y2-y1)/(x2-x1) ; 
         putpixel(x, lamTron(y), color );
   } 
} 
int main(){
	
	int x1,y1,x2,y2;
	cout<<"Nhap diem dau:"<<endl;
	cout<<"Nhap x1: ";cin>>x1;
	cout<<"Nhap y1: ";cin>>y1;
	cout<<"Nhap diem cuoi:"<<endl;
	cout<<"Nhap x2: ";cin>>x2;
	cout<<"Nhap y2: ";cin>>y2;
	initwindow(500,500);
	dline(x1,y1,x2,y2,15);
	getch();
	return 0;
}
