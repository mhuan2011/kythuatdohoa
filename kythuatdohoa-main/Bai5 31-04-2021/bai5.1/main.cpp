#include<iostream>
#include<math.h>
#include <graphics.h>
#include<string.h>
#define Round(a) (int)(a+0.5)   // lam tron so
using namespace std;

int chuyenDoiX(int x1){
	return x1*5+300;
}
int chuyenDoiY(int y1){
	return -y1*5+300;
}
void rotate_point(float x1,float y1,float cx,float cy,float angle)
{
	angle=(angle*3.14)/180;
	float s = sin(angle);
	float c = cos(angle);
	
	// tinh tien ve goc toa do
	x1 -= cx;
	y1 -= cy;
	
	// quay
	float xnew = x1 * c - y1 * s;
	float ynew = x1 * s + y1 * c;
	
	// tinh tien ve vi tri cu
	x1 = xnew + cx;
	y1 = ynew + cy;
  
	int ac=round(x1);
	int bc=round(y1);
	cout<<"x2="<<ac<<" "<<"y2="<<bc<<endl;
	float x2=chuyenDoiX(ac);
	float y2=chuyenDoiY(bc);
	
	circle(x2,y2,2);
}
int main(){
	int x,y,xq,yq;
	int x1,y1,goc;
	cout<<"Toa do 60*60"<<endl;
	cout<<"Nhap toa do diem dau:"<<endl;
	cout<<"Nhap x:";cin>>x1;
	cout<<"Nhap y:";cin>>y1;
	cout<<"Nhap toa do diem quay:"<<endl;
	cout<<"Nhap x:";cin>>xq;
	cout<<"Nhap y:";cin>>yq;
	cout<<"Nhap goc:";cin>>goc;
	initwindow(600,600);
	//----ve toa do
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
			
		}
	}
    //quay
    for(int i=0;i<goc;i++){
    	rotate_point(x1,y1,xq,yq,i);
	}
    getch();
	return 0;
}
