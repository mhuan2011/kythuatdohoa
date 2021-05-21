
#include<conio.h>
#include<dos.h>
#include <unistd.h>
#define backgroundColor 0
//#include <thread>
#include <cmath>
#include <graphics.h> 
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
//#define length 200;
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
int color = 1;
void Loang(int x,int y, int mauto,int maubien){
	int mauHienTai=getpixel(x,y);
	if(mauHienTai!=mauto && mauHienTai!=maubien){
		putpixel(x,y,mauto);
		Loang(x-1,y,mauto,maubien);
		Loang(x+1,y,mauto,maubien);
		Loang(x,y-1,mauto,maubien);
		Loang(x,y+1,mauto,maubien);
	}
}
void MayBay(float x,float y,float a,float b){
	//--------may bay
		line(x*80+a,y*300+b,x*250+a,y*300+b);
		line(x*150+a,y*340+b,x*200+a,y*340+b);
		line(x*150+a,y*340+b,x*100+a,y*400+b);
		line(x*200+a,y*340+b,x*100+a,y*400+b);
		line(x*80+a,y*380+b,x*115+a,y*380+b);
		line(x*132+a,y*380+b,x*250+a,y*380+b);
		ellipse(x*250+a,y*340+b,270,90,x*80,y*40);
		line(x*100+a,y*270+b,x*150+a,y*300+b);
		line(x*100+a,y*270+b,x*200+a,y*300+b);
		line(x*80+a,y*300+b,x*65+a,y*260+b);
		arc(x*80+a,y*340+b,180,270,((x+y)/2)*40);
		line(x*40+a,y*340+b,x*40+a,y*260+b);
		line(x*40+a,y*260+b,x*65+a,y*260+b);
		line(x*261+a,y*333+b,x*320+a,y*333+b);
		line(x*261+a,y*333+b,x*261+a,y*310+b);
		rectangle(x*100+a,y*310+b,x*120+a,y*330+b);
		rectangle(x*130+a,y*310+b,x*150+a,y*330+b);
		rectangle(x*160+a,y*310+b,x*180+a,y*330+b);
		rectangle(x*190+a,y*310+b,x*210+a,y*330+b);
		rectangle(x*220+a,y*310+b,x*240+a,y*330+b);
}
void MayBayNguoc(float x,float y,float a,float b){
	//--------may bay
		line(x*80+a,y*300+b,x*250+a,y*300+b);
		line(x*150+a,y*340+b,x*200+a,y*340+b);
		line(x*150+a,y*340+b,x*100+a,y*400+b);
		line(x*200+a,y*340+b,x*100+a,y*400+b);
		line(x*80+a,y*380+b,x*115+a,y*380+b);
		line(x*132+a,y*380+b,x*250+a,y*380+b);
		ellipse(x*250+a,y*340+b,90,270,x*80,y*40);
		line(x*100+a,y*270+b,x*150+a,y*300+b);
		line(x*100+a,y*270+b,x*200+a,y*300+b);
		line(x*80+a,y*300+b,x*65+a,y*260+b);
		arc(x*80+a,y*340+b,270,360,y*40);
		line(x*40+a,y*340+b,x*40+a,y*260+b);
		line(x*40+a,y*260+b,x*65+a,y*260+b);
		line(x*261+a,y*333+b,x*320+a,y*333+b);
		line(x*261+a,y*333+b,x*261+a,y*310+b);
		rectangle(x*100+a,y*310+b,x*120+a,y*330+b);
		rectangle(x*130+a,y*310+b,x*150+a,y*330+b);
		rectangle(x*160+a,y*310+b,x*180+a,y*330+b);
		rectangle(x*190+a,y*310+b,x*210+a,y*330+b);
		rectangle(x*220+a,y*310+b,x*240+a,y*330+b);
}
void Nha(int i){
	rectangle(510-i,459,550-i,430) ;
		rectangle(550-i,459,610-i,430);
		line(530-i,410,550-i,430);
		line(530-i,410,510-i,430);
		line(590-i,410,610-i,430);
		line(590-i,410,530-i,410);
		
		rectangle(430-i,430,490-i,459);
		rectangle(390-i,430,430-i,459);
		line(410-i,410,430-i,430);
		line(410-i,410,390-i,430);
		line(410-i,410,470-i,410);
		line(470-i,410,490-i,430);
}
//int DieuKhien(int b){
//	if (kbhit())
//	{
//		int key = getch();
//
//		if ((key == 'W' || key == 'w')){
//			if(b==0){
//				b=b+80;
//			}
//		}
//			
//		else if ((key == 'S' || key == 's')){
//			if(b==80){
//				b=0;
//			}
//		}
//	}
//	return b;
//}
void ThaBom(int y){
	
}
// coi xoay gio
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);
 
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}
 
	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}
void rotate_point(int &x1,int &y1,int cx,int cy,float angle)
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
	xnew = xnew + cx;
	ynew = ynew + cy;
  
	x1=Round(xnew);
	y1=Round(ynew);
}
void lineDDA(int x1, int y1, int x2, int y2, int color){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x, y, color);
      
    int k=1;
    while(k <=step){
    	k++;
    	x += x_inc;
	    y += y_inc;           
	        putpixel(Round(x),Round(y),color);
		
    }
}

void veTamGiacCan(int xa, int ya, int xb, int yb, int xc, int yc, int color){
	lineDDA(xa, ya, xb, yb, color);
	lineDDA(xa, ya, xc, yc, color);
	lineDDA(xb, yb, xc, yc, color);
}
void xoayDuongThang(int &xa, int &ya, int &xb, int &yb, int xo, int yo, int goc, int color){
	lineDDA(xa, ya, xb, yb, 0);
	rotate_point(xa, ya, xo, yo, goc);
	rotate_point(xb, yb, xo, yo, goc);
		lineDDA(xa, ya, xb, yb, color);
	
	}
void xoayTamGiac(int &xa, int &ya, int &xb, int &yb, int &xc, int &yc, int xo, int yo, int goc, int color){
	veTamGiacCan(xa, ya, xb,  yb, xc, yc,0);
	rotate_point(xa, ya, xo, yo, goc);
	rotate_point(xb, yb, xo, yo, goc);
	rotate_point(xc, yc, xo, yo, goc);
	veTamGiacCan(xa, ya, xb,  yb, xc, yc,color);
	
}
void veThanCoiXoayGio(int xo, int yo, int banKinh,int chieuCao, int color){
		lineDDA(xo+banKinh, yo, xo+banKinh*3, yo+chieuCao, color);
			lineDDA(xo-banKinh, yo, xo-banKinh*3, yo+chieuCao, color);
			lineDDA(xo-banKinh*5, yo+chieuCao, xo+banKinh*5, yo+chieuCao, color);
	
	}
void quayCanhQuat(int xo, int yo, int color){
	
	int banKinh = 20;
	
	// xo, yo la tam cua canh quat
	int goc = 5;

	int chieuDaiCanh = 30;
	//duong thang ngang
	int xa1 = xo;
	int ya1 = yo-chieuDaiCanh;
	int xb1 = xo;
	int yb1 = yo+chieuDaiCanh;
	
	//duong thang doc
	int xa2 = xo-chieuDaiCanh;
	int ya2 = yo;
	int xb2 = xo+chieuDaiCanh;
	int yb2 = yo;
	//xoay canh quat
	int chieuDaiTamGiac = chieuDaiCanh*3;
	int chieuDaiDay = chieuDaiTamGiac/2;
	// canh quat phai
	int xar = xo+chieuDaiCanh;
	int yar	=yo;
	int xbr =xar+chieuDaiTamGiac;
	int ybr = yar-chieuDaiDay/2;
	int xcr = xar+chieuDaiTamGiac;
	int ycr = yar+chieuDaiDay/2;
	//canh quat trai
	int xal = xo-chieuDaiCanh;
	int yal = yo;
	int xbl = xal-chieuDaiTamGiac;
	int ybl = yal+chieuDaiDay/2;
	int xcl = xal-chieuDaiTamGiac;
	int ycl = yal-chieuDaiDay/2;
	// canh quat tren 
	int xct = xo;
	int yct = yo+chieuDaiCanh;
	int xat = xct-chieuDaiDay/2;
	int yat = yct+chieuDaiTamGiac;
	int xbt = xct + chieuDaiDay/2;
	int ybt = yct+chieuDaiTamGiac;
	// canh quat duoi
	int xcb = xo;
	int ycb = yo-chieuDaiCanh;
	int xab = xcb-chieuDaiDay/2;
	int yab = ycb-chieuDaiTamGiac;
	int xbb = xcb + chieuDaiDay/2;
	int ybb =  ycb-chieuDaiTamGiac;
	while(1){
		drawcircle(xo, yo, banKinh);
		xoayDuongThang(xa1, ya1, xb1, yb1, xo, yo, goc, color);
		xoayDuongThang(xa2, ya2, xb2, yb2, xo, yo, goc, color);
		xoayTamGiac(xar, yar, xbr, ybr, xcr, ycr, xo, yo, goc, color);
		xoayTamGiac(xal, yal, xbl, ybl, xcl, ycl, xo, yo, goc, color);
		xoayTamGiac(xat, yat, xbt, ybt, xct, yct, xo, yo, goc, color);
		xoayTamGiac(xab, yab, xbb, ybb, xcb, ycb, xo, yo, goc, color);
		veThanCoiXoayGio(xo, yo, banKinh, 150, color);
	}
	}
	
	
	
void veMayBay(){
	float x=0.5,y=0.5,a=0,b=0,c=600;
	int x1,y1, i=0;
	int ybom=200;
	int rbom=10;
	char stop=1;
	// coi xoay gio
	
	int banKinh = 10;
	int xo=100, yo=350;
	int color = 0;
	// xo, yo la tam cua canh quat
	int goc = 5;
	int chieuDaiCanh = 20;
	//duong thang ngang
	int xa1 = xo;
	int ya1 = yo-chieuDaiCanh;
	int xb1 = xo;
	int yb1 = yo+chieuDaiCanh;
	
	//duong thang doc
	int xa2 = xo-chieuDaiCanh;
	int ya2 = yo;
	int xb2 = xo+chieuDaiCanh;
	int yb2 = yo;
	//xoay canh quat
	int chieuDaiTamGiac = chieuDaiCanh*3;
	int chieuDaiDay = chieuDaiTamGiac/2;
	// canh quat phai
	int xar = xo+chieuDaiCanh;
	int yar	=yo;
	int xbr =xar+chieuDaiTamGiac;
	int ybr = yar-chieuDaiDay/2;
	int xcr = xar+chieuDaiTamGiac;
	int ycr = yar+chieuDaiDay/2;
	//canh quat trai
	int xal = xo-chieuDaiCanh;
	int yal = yo;
	int xbl = xal-chieuDaiTamGiac;
	int ybl = yal+chieuDaiDay/2;
	int xcl = xal-chieuDaiTamGiac;
	int ycl = yal-chieuDaiDay/2;
	// canh quat tren 
	int xct = xo;
	int yct = yo+chieuDaiCanh;
	int xat = xct-chieuDaiDay/2;
	int yat = yct+chieuDaiTamGiac;
	int xbt = xct + chieuDaiDay/2;
	int ybt = yct+chieuDaiTamGiac;
	// canh quat duoi
	int xcb = xo;
	int ycb = yo-chieuDaiCanh;
	int xab = xcb-chieuDaiDay/2;
	int yab = ycb-chieuDaiTamGiac;
	int xbb = xcb + chieuDaiDay/2;
	int ybb =  ycb-chieuDaiTamGiac;
	while(stop!='0')
	{
		//----hien thi
		cleardevice();
		MayBay(x,y,a,0);
		MayBayNguoc(-x,y,c,80);
		Nha(i);
		line(0,459,679,459);
		
		
		circle(100,ybom,rbom);
		if(rbom==70){
			return ;
		}
		ybom+=2;
		if(ybom==460){
			ybom-=2;
			rbom+=5;
			circle(100,ybom,rbom);
			Loang(100,458,12,0);
		}
		
		
//		if(c-165==164&&b==0){
//			break;
//		}
		//a++;
		
		c--;
		i++;
		drawcircle(xo, yo, banKinh);
		xoayDuongThang(xa1, ya1, xb1, yb1, xo, yo, goc, color);
		xoayDuongThang(xa2, ya2, xb2, yb2, xo, yo, goc, color);
		xoayTamGiac(xar, yar, xbr, ybr, xcr, ycr, xo, yo, goc, color);
		xoayTamGiac(xal, yal, xbl, ybl, xcl, ycl, xo, yo, goc, color);
		xoayTamGiac(xat, yat, xbt, ybt, xct, yct, xo, yo, goc, color);
		xoayTamGiac(xab, yab, xbb, ybb, xcb, ycb, xo, yo, goc, color);
		veThanCoiXoayGio(xo, yo, banKinh, 100, color);
		delay(30);
		if(kbhit()){
			stop = getch();	
		}
		
	}
		}
// Huan------------------------------------------------------------------------------------------
void giaoDien(){

	initwindow(900, 600);			
	setbkcolor(15);					
   	cleardevice();
	setcolor(0);					

	rectangle(0,0,250,590); //khung button left - top - right - bottom
		
	rectangle(50,20,200,60); //2d
	rectangle(50,80,200,120);  //3d
	setcolor(0);
	settextstyle(8, 0, 3);
	outtextxy(100, 28, "2D");
	outtextxy(100, 88, "3D");


	rectangle(0,0,250,150); // khung nhap lieu
	rectangle(20,180,230,450);
	settextstyle(8, 0, 1);
	outtextxy(35, 170, "Parameters");
	
	rectangle(250,0,890,590); //khung thao tac
	
	
	setfillstyle(1, 4);
	setbkcolor(4);	
	bar(70,520,180,550); //clear button
	setcolor(15);
	
	outtextxy(95, 525, "Clear");
	setbkcolor(15);
}


// Vinh------------------------------------------------------------------------------------------
//1. Ve do thi
struct toaDo{
	int x;
	int y;
};
typedef struct toaDo toaDoDiem;
//1.1. Ve duong thang bang DDA
//ve net lien
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

//1.2. Ve cac pixel
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

//1.3. Ve net dut cho canh bi khuat
void v_lineDDA3(int x1, int y1, int x2, int y2, int l, int color){       
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

//
toaDoDiem v_lineDDA2(int x1, int y1, int x2, int y2, int chieuDai, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel(x, y, color);
    int count = 0;
    int k=1;
    toaDoDiem a;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        if(count <= chieuDai){
		}	
		else if(count >= chieuDai){
			a.x = Round(x);
			a.y = Round(y);
			return a;
		}
		count++;
    }
}

//1.4. Ve truc
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

//1.5. Ve hinh hop chu nhat
void v_hinhHopCN(int x, int y, int CD, int CR, int CC){
	int dai = Round(CD*5/2), rong = CR*5, cao = CC*5;
	
	//HCM mat sau
	v_lineDDA3(x, y, x, y - cao, 2, 2); 
	v_lineDDA3(x, y, x + rong, y, 2, 2);
	v_lineDDA(x, y - cao, x + rong, y - cao, 2);
	v_lineDDA(x + rong, y, x + rong, y - cao, 2);

	//lay toa do diem tren truc Oz
	toaDoDiem a;
	int tmpX = 450;
	int tmpY = 400;
	a = v_lineDDA2(450, 400, 270, 530, dai, 2);
	if(x > tmpX || x < tmpX){
		tmpX = x - tmpX;
	}
	else{
		tmpX = 0;
	}
	
	if(y > tmpY || y< tmpY){
		tmpY = y - tmpY;
	}
	else{
		tmpY = 0;
	}
	a.x = a.x + tmpX;
	a.y = a.y + tmpY;
	cout << a.x << ", " << a.y;
	
	//HCM mat truoc
	v_lineDDA(a.x, a.y, a.x + rong, a.y, 2);
	v_lineDDA(a.x, a.y, a.x, a.y - cao, 2);
	v_lineDDA(a.x, a.y-cao, a.x + rong, a.y - cao, 2);
	v_lineDDA(a.x + rong, a.y - cao, a.x + rong, a.y, 2);
	
	//Noi 2 mat HCM
	v_lineDDA3(x, y, a.x, a.y, 2, 2);
	v_lineDDA(x + rong, y, a.x + rong, a.y, 2);
	v_lineDDA(x, y - cao, a.x, a.y - cao, 2);
	v_lineDDA(x + rong, y - cao, a.x + rong, a.y - cao, 2);	
	
}


void getMouseClick(){
	int x, y;        // Coordinates of the mouse click


    while (1)

    {

        getmouseclick(WM_LBUTTONDOWN, x, y);

	    if(x > 50 && x < 200 && y > 20 && y <60){ //xua li 2d
	    	setcolor(BLACK);
			settextstyle(8, 0, 3);
			outtextxy(100, 28, "2D");
			setcolor(0);
			outtextxy(100, 88, "3D");
			
			setfillstyle(1, 0);
			bar(250,0,890,590);
			
			settextstyle(8, 0, 1);
			setcolor(0);
//			outtextxy(50, 200, "Height: ");
			veMayBay();
			
			//
			
//			gotoXY(45, 170);
//			int x; cin >>x;
		}
	    
	    if(x > 50 && x < 200 && y > 80 && y <120){ //xu li 3d
	    	setcolor(BLACK);
			settextstyle(8, 0, 3);
			outtextxy(100, 88, "3D");
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(100, 28, "2D");
			setfillstyle(1, 0);
			bar(250,0,890,590);
			//vinh: Ve truc toa do va hinh hop chu nhat
			v_veTrucOxyz();
			outtextxy(50, 200, "X: ");
			outtextxy(50, 250, "Y: ");
			outtextxy(50, 300, "Dai: ");
			outtextxy(50, 350, "Rong: ");
			outtextxy(50, 400, "Cao: ");
			int x = 150;
			int y = 200;
			string so;
			int kichThuoc[6];
			int dem = 0;//dem kich thuoc cua hinh hop
			int check = 0;//dem de thoat ra hoi nhap
			while(true){
				//nhap so vao man hinh graphic
				if(kbhit()){
					char chr;
					chr = getch();
					if(int(chr) == 8){
						x -=15;
						outtextxy(x, y, " ");
					}
					else if (int(chr) >= 48 && int(chr) <= 57  || int(chr) == 13){
						if(int(chr) == 13){
							int tmp = atoi(so.c_str());
							so = "";
							kichThuoc[dem] = tmp;
							y += 50;
							x = 150;
							dem++;
							check++;
						}
						char a[10];
						a[0]= chr;
						so += a[0];
						outtextxy(x, y, a);
						x+=15;
						if(check > 4){
							v_hinhHopCN(kichThuoc[0]*5 + 450, kichThuoc[1]*5 + 400, kichThuoc[2], kichThuoc[3], kichThuoc[4]);
						}
					}
					
				}
			}

		}
		
		if(kbhit()) break;
    }
	
    
    
    
}



int main()
{
	
	giaoDien();	
	setbkcolor(15);
	getMouseClick();
	

    


    closegraph( );
}
