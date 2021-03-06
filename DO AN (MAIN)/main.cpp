#include <graphics.h> 
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
//#define length 200;
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define bgColor 0
int color = 1;
int pixel = 3;//chi nhan so pixel le
//void v_nhapDuLieu();
// Huan------------------------------------------------------------------------------------------
void inToaDo(int xb, int yb, int color);
char* stringToChar(string s);
void veHCN(int x,int y, int cao,int color);
void put5x5pixel(int x,int y,int color);
void n_line(int x1, int y1, int x2, int y2);
void n_rectangle(int x1,int y1,int x2,int y2){
	n_line(x1,y1,x2,y1);
	n_line(x1,y1,x1,y2);
	n_line(x1,y2,x2,y2);
	n_line(x2,y1,x2,y2);
}
void n_drawcircle(int x0, int y0, int radius,int color)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	put5x5pixel((x0 + x)/pixel, (y0 + y)/pixel, color);
	put5x5pixel((x0 + y)/pixel, (y0 + x)/pixel, color);
	put5x5pixel((x0 - y)/pixel, (y0 + x)/pixel, color);
	put5x5pixel((x0 - x)/pixel, (y0 + y)/pixel, color);
	put5x5pixel((x0 - x)/pixel, (y0 - y)/pixel, color);
	put5x5pixel((x0 - y)/pixel, (y0 - x)/pixel, color);
	put5x5pixel((x0 + y)/pixel, (y0 - x)/pixel, color);
	put5x5pixel((x0 + x)/pixel, (y0 - y)/pixel, color);
 
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
void plot(int xc, int yc, int x, int y, int color)
{
    put5x5pixel(xc+x, yc+y, color);
    put5x5pixel(xc-x, yc+y, color);
    put5x5pixel(xc+x, yc-y, color);
    put5x5pixel(xc-x, yc-y, color);
}

void elipMidpointMay(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plot(xc, yc, x, y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
//        delay(50);
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plot(xc, yc, x, y, color);
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
//        delay(50);
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plot(xc, yc, x, y, color);
    }
}
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

void chonNguCanh(int x){
	int a=0;
	int b=0;

	if(x==1){
		a=15;
		b=0;
	}
	else {
		a=0;
		b=15;
	}
	
	setfillstyle(1, a);
	setbkcolor(a);	
	bar(265,7,365,34); //tiem kich
	setcolor(b);
	settextstyle(3, 0, 1);
	outtextxy(275, 8, "Tiem kich");

	
	
	setfillstyle(1, b);
	setbkcolor(b);	
	bar(380,7,515,34); //coi xoay gio
	setcolor(a);
	outtextxy(395, 8, "Coi xoay gio");

//reset font color
	settextstyle(8, 0, 1);
	setbkcolor(15);
	setcolor(0);
	
}
void MayBay(float x,float y,float a,float b){
	int color=getcolor();
	setcolor(15);
	//--------may bay
		n_line((x*80+a)/pixel,(y*300+b)/pixel,(x*250+a)/pixel,(y*300+b)/pixel);
		n_line((x*150+a)/pixel,(y*340+b)/pixel,(x*200+a)/pixel,(y*340+b)/pixel);
		n_line((x*150+a)/pixel,(y*340+b)/pixel,(x*100+a)/pixel,(y*400+b)/pixel);
		n_line((x*200+a)/pixel,(y*340+b)/pixel,(x*100+a)/pixel,(y*400+b)/pixel);
		n_line((x*80+a)/pixel,(y*380+b)/pixel,(x*115+a)/pixel,(y*380+b)/pixel);
		n_line((x*132+a)/pixel,(y*380+b)/pixel,(x*250+a)/pixel,(y*380+b)/pixel);
		//ellipse(x*250+a,y*340+b,270,90,x*80,y*40);
		elipMidpointMay((x*260+a)/pixel,(y*340+b)/pixel,x*80/pixel,y*40/pixel,15);
		//n_line((x*250+a)/5,(y*340+b-y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		//n_line((x*250+a)/5,(y*340+b+y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		
		n_line((x*100+a)/pixel,(y*270+b)/pixel,(x*150+a)/pixel,(y*300+b)/pixel);
		n_line((x*100+a)/pixel,(y*270+b)/pixel,(x*200+a)/pixel,(y*300+b)/pixel);
		n_line((x*80+a)/pixel,(y*300+b)/pixel,(x*65+a)/pixel,(y*260+b)/pixel);
		//arc(x*80+a,y*340+b,180,270,((x+y)/2)*40);
		n_line((x*40+a)/pixel,(y*340+b)/pixel,(x*80+a)/pixel,(y*380+b)/pixel);
		//n_drawcircle((x*80+a)/5,(y*340+b)/5,((x+y)/2)*40/5,1);
		n_line((x*40+a)/pixel,(y*340+b)/pixel,(x*40+a)/pixel,(y*260+b)/pixel);
		n_line((x*40+a)/pixel,(y*260+b)/pixel,(x*65+a)/pixel,(y*260+b)/pixel);
		n_line((x*261+a)/pixel,(y*333+b)/pixel,(x*320+a)/pixel,(y*333+b)/pixel);
		n_line((x*261+a)/pixel,(y*333+b)/pixel,(x*261+a)/pixel,(y*310+b)/pixel);
		n_rectangle((x*100+a)/pixel,(y*310+b)/pixel,(x*120+a)/pixel,(y*330+b)/pixel);
		n_rectangle((x*130+a)/pixel,(y*310+b)/pixel,(x*150+a)/pixel,(y*330+b)/pixel);
		n_rectangle((x*160+a)/pixel,(y*310+b)/pixel,(x*180+a)/pixel,(y*330+b)/pixel);
		n_rectangle((x*190+a)/pixel,(y*310+b)/pixel,(x*210+a)/pixel,(y*330+b)/pixel);
		n_rectangle((x*220+a)/pixel,(y*310+b)/pixel,(x*240+a)/pixel,(y*330+b)/pixel);
		
		int x1=x*40+a;
		int y1=y*340+b;
		inToaDo(x1,y1,15);
	setcolor(color);
}
//void MayBayNguoc(float x,float y,float a,float b){
//	int color=getcolor();
//	setcolor(15);
//	//--------may bay
//		n_line((x*80+a)/5,(y*300+b)/5,(x*250+a)/5,(y*300+b)/5);
//		n_line((x*150+a)/5,(y*340+b)/5,(x*200+a)/5,(y*340+b)/5);
//		n_line((x*150+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
//		n_line((x*200+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
//		n_line((x*80+a)/5,(y*380+b)/5,(x*115+a)/5,(y*380+b)/5);
//		n_line((x*132+a)/5,(y*380+b)/5,(x*250+a)/5,(y*380+b)/5);
//		//ellipse(x*250+a,y*340+b,90,270,x*80,y*40);
//		n_line((x*250+a)/5,(y*340+b-y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
//		n_line((x*250+a)/5,(y*340+b+y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
//		
//		n_line((x*100+a)/5,(y*270+b)/5,(x*150+a)/5,(y*300+b)/5);
//		n_line((x*100+a)/5,(y*270+b)/5,(x*200+a)/5,(y*300+b)/5);
//		n_line((x*80+a)/5,(y*300+b)/5,(x*65+a)/5,(y*260+b)/5);
//		//arc(x*80+a,y*340+b,270,360,y*40);
//		n_line((x*40+a)/5,(y*340+b)/5,(x*40+a)/5,(y*260+b)/5);
//		n_line((x*40+a)/5,(y*260+b)/5,(x*65+a)/5,(y*260+b)/5);
//		n_line((x*261+a)/5,(y*333+b)/5,(x*320+a)/5,(y*333+b)/5);
//		n_line((x*261+a)/5,(y*333+b)/5,(x*261+a)/5,(y*310+b)/5);
//		n_rectangle((x*100+a)/5,(y*310+b)/5,(x*120+a)/5,(y*330+b)/5);
//		n_rectangle((x*130+a)/5,(y*310+b)/5,(x*150+a)/5,(y*330+b)/5);
//		n_rectangle((x*160+a)/5,(y*310+b)/5,(x*180+a)/5,(y*330+b)/5);
//		n_rectangle((x*190+a)/5,(y*310+b)/5,(x*210+a)/5,(y*330+b)/5);
//		n_rectangle((x*220+a)/5,(y*310+b)/5,(x*240+a)/5,(y*330+b)/5);
//		
//		
//		int x1=x*100+a+20;
//		int y1=y*310+b;
//		inToaDo(x1,y1,15);
//	setcolor(color);
//}
void Nha(int i,int y){
	n_rectangle((520-i)/pixel,(459-y)/pixel,(560-i)/pixel,(430-y)/pixel);
	n_rectangle((560-i)/pixel,(459-y)/pixel,(620-i)/pixel,(430-y)/pixel);
	
	
	n_rectangle((440-i)/pixel,(430-y)/pixel,(500-i)/pixel,(459-y)/pixel);
	n_rectangle((400-i)/pixel,(430-y)/pixel,(440-i)/pixel,(459-y)/pixel);
	
}
void NocNha(int i,int y){
	int color=getcolor();
	setcolor(12);
	n_line((540-i)/pixel,(410-y)/pixel,(560-i)/pixel,(430-y)/pixel);
	n_line((540-i)/pixel,(410-y)/pixel,(520-i)/pixel,(430-y)/pixel);
	n_line((600-i)/pixel,(410-y)/pixel,(620-i)/pixel,(430-y)/pixel);
	n_line((600-i)/pixel,(410-y)/pixel,(540-i)/pixel,(410-y)/pixel);
	
	n_line((420-i)/pixel,(410-y)/pixel,(440-i)/pixel,(430-y)/pixel);
	n_line((420-i)/pixel,(410-y)/pixel,(400-i)/pixel,(430-y)/pixel);
	n_line((420-i)/pixel,(410-y)/pixel,(480-i)/pixel,(410-y)/pixel);
	n_line((480-i)/pixel,(410-y)/pixel,(500-i)/pixel,(430-y)/pixel);
	setcolor(color);
}
int veMayBay(){
	setcolor(15);
	float x=0.5,y=0.5,a=250,b=0,c=800;
	int x1,y1,xnha=0,ynha=0,xnocnha=0,ynocnha=0;
	int xbom=340;
	int ybom=200;
	int rbom=10;
	char stop=1;
	
	while(stop!='0')
	{
		
		int Mx, My;
		getmouseclick(WM_LBUTTONDOWN, Mx, My);
		if(Mx>70 && Mx<180 && My>520 && My<550){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			chonNguCanh(1);
			return 2;
		}
				
		if(Mx>380 && Mx<485 && My>7 && My<34){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			chonNguCanh(2);
			return 1;
		}
		if(Mx > 50 && Mx < 200 && My > 80 && My <120){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			cout <<"3D";
			return 3;
		}
		//----hien thi
		//cleardevice();	
//		veHCN(255,100,570,0);
		setfillstyle(1, 0);
		bar(250,50,890,590);
		setcolor(15);
		n_line(575/pixel,0/pixel,575/pixel,590/pixel);//oy  575
		setcolor(15);
		n_line(250/pixel,300/pixel,900/pixel,300/pixel);//ox 300
		MayBay(x,y,a,0);//xu?i
		MayBay(-x,y,c,80);//nguoc
		MayBay(-0.3,0.3,c+50,220);//thu nho
		setcolor(9); //huan
		Nha(xnha,ynha);
		setcolor(12);
		NocNha(xnocnha,ynocnha);
		setcolor(10); //huan
		//mat dat
		n_line(275/pixel,459/pixel,800/pixel,459/pixel);
		
		setcolor(15);
		n_drawcircle(xbom,ybom,rbom,12);
		if(ybom<460){
			put5x5pixel((xbom+rbom)/pixel,ybom/pixel,15);
			inToaDo(xbom+rbom,ybom,15);
			//put5x5pixel(xbom/5,ybom/5,15);
		}
		if(rbom>=70){
			break;
		}
		ybom+=pixel;
		if(ybom>=460){
			ybom-=pixel;
			rbom+=pixel;
			n_drawcircle(xbom,ybom,rbom,12);
			put5x5pixel((xbom+rbom)/pixel,ybom/pixel,15);
			inToaDo(xbom+rbom,ybom,15);
			//Loang(xbom/50,458/50,15,12);
			for(int i=0;i<rbom;i++){
				n_drawcircle(xbom,ybom,i,12);
			}
			ynha+=2;
			ynocnha+=4;
		}
		c-=pixel;;
		xnha++;
		xnocnha++;
		delay(30);
		if(kbhit()){
			stop = getch();	
		}
		//---------------
		
		
	}
	return 2;
}
void n_line(int x1, int y1, int x2, int y2){       // thuat toan DDA
    int color=getcolor();
	int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    put5x5pixel(x, y, color);
      
    int k=1;
    int m = 0;
    while(k <=step){
    	k++;
    	x += x_inc;
	    y += y_inc;		
	    m++;           
	    put5x5pixel(Round(x),Round(y),color);
    }
}
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
	rectangle(20,180,230,500);
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
void xoaKhungChiTiet(){
	setfillstyle(1, 15);
	bar(30,190,220,480); 
}
void chonHinh(int x){
	int a=0;
	int b=0;

	if(x==1){
		a=15;
		b=0;
	}
	else {
		a=0;
		b=15;
	}
	
	setfillstyle(1, a);
	setbkcolor(a);	
	bar(265,7,365,34); //hinh hop
	setcolor(b);
	settextstyle(3, 0, 1);
	outtextxy(275, 8, "Hinh hop");

	
	
	setfillstyle(1, b);
	setbkcolor(b);	
	bar(380,7,485,34); //hinh cau
	setcolor(a);
	outtextxy(395, 8, "Hinh cau");

//reset font color
	settextstyle(8, 0, 1);
	setbkcolor(15);
	setcolor(0);
	
}



//chuyen String sang char array
char* chuyenDoiStringSangChar(string a){
	int n = a.length();
	char m[n];
	for(int i=0; i<n ; i++){
		m[i] = a[i];
	}
	return m;
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
void v_lineDDAforOxyz(int x1, int y1, int x2, int y2, int color){ //duong thang ve oxyz  
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

//ve diem pixe = 5
void putpixel1(int x, int y, int color){
	int ve = 0;
	if (pixel == 1){
		putpixel(x, y, color);
	}
	else {
		if (pixel%2 != 0){
			ve = Round(pixel/2);
		}
		else if (pixel%2 == 0){
			ve = pixel/2;
		}
		v_lineDDAforOxyz(x-ve, y-ve, x+ve, y-ve, color);
		v_lineDDAforOxyz(x-ve, y-ve, x-ve, y+ve, color);
		v_lineDDAforOxyz(x-ve, y+ve, x+ve, y+ve, color);
		v_lineDDAforOxyz(x+ve, y-ve, x+ve, y+ve, color);
		for(int i = 0; i<pixel; i++){
			v_lineDDAforOxyz(x-ve, y-ve+i, x+ve, y-ve+i, color);
			v_lineDDAforOxyz(x-ve+i, y+ve, x+ve, y+ve, color);
		}
	}
	

}

//ve duong thang bth
void v_lineDDA(int x1, int y1, int x2, int y2, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel1(x, y, color);
      
    int k=1;
    int dem = 0;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        if (dem %pixel == 0){
        	putpixel1(Round(x),Round(y),color);
		}
		dem++;
        
         
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
        if(dem % pixel == 0){
        	putpixel(Round(x),Round(y),color);	
		}
		dem++;
    }
}

//putpixel Oz
void v_lineDDAOz(int x1, int y1, int x2, int y2, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel1(x, y, color);
    int dem = 0;
    int k=1;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        if (pixel == 1){
        	pixel += 1;
		}
        if(dem % Round(pixel/2) == 0){
        	putpixel(Round(x),Round(y),color);	
		}
		dem++;
    }
}

//1.3. Ve net dut cho canh bi khuat
void v_lineDDA3(int x1, int y1, int x2, int y2, int color){       
	int  Dx = x2 - x1, Dy = y2 - y1;  
	    float x_inc , y_inc;
	    float step=max(abs(Dx),abs(Dy));
	    x_inc=Dx/step;
	    y_inc=Dy/step;
	    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
	    putpixel1(x, y, color);
	    int dem = 0;
	    int k=1;
	    while(k <=step){
	        k++;
	        x += x_inc;
	        y += y_inc;
	        if(dem % 10 == 0){
	        	putpixel1(Round(x),Round(y),color);	
			}
			dem++;
	    }
}

//ve duong khuat tren truc oz
void v_lineDDAKhuat(int x1, int y1, int x2, int y2, int color){       
	int  Dx = x2 - x1, Dy = y2 - y1;  
	    float x_inc , y_inc;
	    float step=max(abs(Dx),abs(Dy));
	    x_inc=Dx/step;
	    y_inc=Dy/step;
	    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
	    putpixel1(x, y, color);
	    int dem = 0;
	    int k=1;
	    while(k <=step){
	        k++;
	        x += x_inc;
	        y += y_inc;
	        if (dem < 10){
	        	dem ++ ;
			}
	        if(dem == 10){
	        	putpixel1(Round(x),Round(y),color);	
	        	dem = 0;
			}
			dem++;
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
		if(count == chieuDai){
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
    v_lineDDAforOxyz(450, 400, 800, 400, color);//x
    v_lineDDAforOxyz(450, 400, 300, 550, color);//z
    v_lineDDAforOxyz(450, 400, 450, 100, color);//y
    
    //ve mui ten
    //truc Oz
    v_lineDDAforOxyz(300, 550, 300, 530, color);
    v_lineDDAforOxyz(300, 550, 320, 550, color);
    //truc Ox
    v_lineDDAforOxyz(800, 400, 785, 385, color);
    v_lineDDAforOxyz(800, 400, 785, 415, color);
    //truc Oy
    v_lineDDAforOxyz(450, 100, 440, 120, color);
    v_lineDDAforOxyz(450, 100, 460, 120, color);
    
    //hien x, y, z
    outtextxy(805, 405, "x");
	outtextxy(470, 100, "y");
	outtextxy(275, 535, "z");
	
	//cham diem pixel
	//truc Oy
	v_lineDDA1(450, 400, 450, 105, 15);
	//truc Ox
	v_lineDDA1(450, 400, 800, 400, 15);
	//truc Oz
	v_lineDDAOz(450, 400, 300, 550, 15);
}

//1.5. Ve hinh hop chu nhat
void v_hinhHopCN(int x, int y, int CD, int CR, int CC){
	int dai = Round(CD*(pixel/2)), rong = CR*pixel, cao = CC*pixel;
	
	//HCM mat sau
	v_lineDDA3(x, y, x, y - cao, 2);
	v_lineDDA3(x, y, x + rong, y, 2);
	v_lineDDA(x, y - cao, x + rong, y - cao, 2);
	v_lineDDA(x + rong, y, x + rong, y - cao, 2);

	//lay toa do diem tren truc Oz
	toaDoDiem a;
	int tmpX = 450;
	int tmpY = 400;
	a = v_lineDDA2(450, 400, 300, 550, dai, 2);
	if(x > tmpX || x < tmpX){
		tmpX = x - tmpX;
	}
	else if (x == tmpX){
		tmpX = 0;
	}
	
	if(y > tmpY || y< tmpY){
		tmpY = y - tmpY;
	}
	else if (y == tmpY){
		tmpY = 0;
	}
	a.x = a.x + tmpX;
	a.y = a.y + tmpY;
	
	//HCM mat truoc
	v_lineDDA(a.x, a.y, a.x + rong, a.y, 2);
	v_lineDDA(a.x, a.y, a.x, a.y - cao, 2);
	v_lineDDA(a.x, a.y-cao, a.x + rong, a.y - cao, 2);
	v_lineDDA(a.x + rong, a.y - cao, a.x + rong, a.y, 2);
	
	//Noi 2 mat HCM
	v_lineDDAKhuat(x, y, a.x, a.y,  2);
	v_lineDDA(x + rong, y, a.x + rong, a.y, 2);
	v_lineDDA(x, y - cao, a.x, a.y - cao, 2);
	v_lineDDA(x + rong, y - cao, a.x + rong, a.y - cao, 2);	
}

//xuat diem ra console
void xuatDiem(int x, int y, int z, int CD, int CR, int CC){
	cout << "-----------HINH HOP CHU NHAT BANG TOA DO NGUOI DUNG-----------\n";
	cout << "	Diem A(" << x << ", " << y << ", " << z << ") \n";
	cout << "	Diem B(" << x + CR << ", " << y << ", " << z << ") \n";
	cout << "	Diem C(" << x + CR << ", " << y << ", " << z + CD << ") \n";
	cout << "	Diem D(" << x << ", " << y << ", " << z + CD << ") \n\n";
	
	cout << "	Diem A'(" << x << ", " << y + CC << ", " << z << ") \n";
	cout << "	Diem B'(" << x + CR << ", " << y + CC << ", " << z << ") \n";
	cout << "	Diem C'(" << x + CR << ", " << y + CC << ", " << z + CD << ") \n";
	cout << "	Diem D'(" << x << ", " << y + CC << ", " << z + CD << ") \n";
	cout << "-------------------------------------------------------------\n\n";
}

//1.7. xu li nhap
int v_nhapDuLieu(){ //phan ve hinh hop
			v_veTrucOxyz();
			setfillstyle(1, 15);
			bar(30,190,220,480); 
			outtextxy(50, 200, "X: ");
			outtextxy(50, 250, "Y: ");
			outtextxy(50, 300, "Z: ");
			outtextxy(50, 350, "Dai: ");
			outtextxy(50, 400, "Rong: ");
			outtextxy(50, 450, "Cao: ");
			int x = 150;
			int y = 200;
			string so;
			string soHien = "";
			int kichThuoc[6];
			int dem = 0;//dem kich thuoc cua hinh hop
			int check = 0;//dem de thoat ra hoi nhap
			while(true){
				//nhap so vao man hinh graphic
				int Mx, My;
				getmouseclick(WM_LBUTTONDOWN, Mx, My);
				if(Mx>70 && Mx<180 && My>520 && My<550){
					setfillstyle(1, 0);
					bar(250,0,890,590);
					v_veTrucOxyz();
					chonHinh(1);
					return 2;
				}
				//nut hinh cau
				if(Mx>380 && Mx<485 && My>7 && My<34){
					chonHinh(2);
					return 1;
				}
				//nut 2d
				if(Mx > 50 && Mx < 200 && My > 20 && My <60){
		
					return 3;
				}
				if(kbhit()){
					char chr;
					chr = getch();
					if(int(chr) == 8){
						x -=15;
						outtextxy(x, y, " ");
					}
					else if (int(chr) >= 48 && int(chr) <= 57  || int(chr) == 13 || int(chr) == 45){
						if(int(chr) == 13){
							int tmp = atoi(so.c_str());
							so = "";
							kichThuoc[dem] = tmp;
							y += 50;
							x = 150;
							dem++;
							check++;
							soHien = "";
						}
						soHien = chr;
						char *cstr = new char[soHien.length()+1];
						strcpy(cstr, soHien.c_str());
						delete [] cstr;
						//-----------
						char a[10];
				
						a[0]= chr;

						so += a[0];

						outtextxy(x, y, cstr);
						x+=15;
						if(check > 5){
							v_hinhHopCN((kichThuoc[0] - kichThuoc[2]*(sqrt(2)/4))*pixel + 450, 400 - (kichThuoc[1] - kichThuoc[2]*(sqrt(2)/4))*pixel, kichThuoc[3], kichThuoc[4], kichThuoc[5]);
							xuatDiem(kichThuoc[0], kichThuoc[1], kichThuoc[2], kichThuoc[3], kichThuoc[4], kichThuoc[5]);
							return 2;
						}
					}
					
				}
			}
}
//Long-------------------------------------------------------------------------------------
//2.1. Ve elip nam ngang
void l_xuatDiem(int x, int y, int z){
	cout << "-----------HINH CAU BANG TOA DO NGUOI DUNG-----------\n";
	cout << "	Diem P(Center)(" << x << ", " << y << ", " << z << ") \n";
	cout << "-------------------------------------------------------------\n\n";	
	cout << "-----------HINH CAU BANG TOA DO MAY------------------\n";
	cout << "	Diem P(Center)(" << Round(x - z*(sqrt(2)/4)) * 5  +  450 << ", " << Round(y- z*(sqrt(2)/4))*5 + 400 << ")\n";	
	cout << "-------------------------------------------------------------\n";
}
void elipMidpoint(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    putpixel1(xc+x, yc-y, color);
    putpixel1(xc-x, yc-y, color);
    putpixel1(xc+x, yc+y, color);
    putpixel1(xc-x, yc+y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    int dem = 0;
    int draw = 0;
    while(fx<fy)
    {
		draw ++;
		x+=pixel;
        fx += pixel*(2*b2);
        delay(5);
        if(p<0)
        {
            p += b2*(2*x + pixel*3);//p=p + b2*(2x +3)
        }
        else
        {
            y-=pixel;
            p += b2*(2*x + pixel*3) + a2*(pixel*2 - 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= pixel*(2*a2);
        }
		if (draw == 1){
			draw = 0;
		if(dem == 1){
			dem = 0;
		}
		else{
		putpixel1(xc+x, yc-y, color);
    	putpixel1(xc-x, yc-y, color);
    	dem++;
		}
		putpixel1(xc+x, yc+y, color);
    	putpixel1(xc-x, yc+y, color);}		
    }
    p = Round(b2*(x + pixel*0.5)*(x + pixel*0.5) + a2*(y-pixel)*(y-pixel) - a2*b2);
    //
    while(y>0)
    {
    	draw ++;
        y-=pixel;
        fy -= pixel*(2*a2);
        delay(5);
        if(p >=0)
        {
            p += a2*(pixel*3-2*y); //p=p + a2(3-2y)
        }
        else
        {
            x+=pixel;
            fx += pixel*(2*b2);
            p += b2*(2*x + pixel*2) +a2*(pixel*3 - 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        if (draw == 1){
			draw = 0;
		if(dem == 1){
			dem = 0;
		}
		else{
		putpixel1(xc+x, yc-y, color);
    	putpixel1(xc-x, yc-y, color);
    	dem++;
		}
		putpixel1(xc+x, yc+y, color);
    	putpixel1(xc-x, yc+y, color);}
    }
}
//2.2. Ve elip nam doc
void elipMidpointDoc(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    putpixel1(xc+x, yc-y, color);
    putpixel1(xc-x, yc-y, color);
    putpixel1(xc+x, yc+y, color);
    putpixel1(xc-x, yc+y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    int draw = 0;
	int dem = 0;
    while(fx<fy)
    {
		draw ++ ;
		x++;
        fx += 2*b2;
        delay(5);
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
		if (draw == 5){
			draw = 0;
		if(dem == 3){
			dem = 0;
		}
		else if((dem == 2)){
			dem++;
		}
		else{
		putpixel1(xc+x, yc+y, color);
    	putpixel1(xc+x, yc-y, color);
    	dem++;
		}
		putpixel1(xc-x, yc+y, color);
    	putpixel1(xc-x, yc-y, color);}	
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        draw ++;
		y--;
        fy -= 2*a2;
        delay(5);
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        if (draw == 5){
			draw = 0;
		if(dem == 3){
			dem = 0;
		}
		else if((dem == 2)){
			dem++;
		}
		else{
		putpixel1(xc+x, yc+y, color);
    	putpixel1(xc+x, yc-y, color);
    	dem++;
		}
		putpixel1(xc-x, yc+y, color);
    	putpixel1(xc-x, yc-y, color);}
    }
}
//2.3. Ve hinh tron
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int f = 1 - r;
	int draw = 0;
    putpixel1(x + xc, y + yc, color);
    putpixel1(-x + xc, y + yc, color);
    putpixel1(x + xc, -y + yc, color);
    putpixel1(-x + xc, -y + yc, color);
    putpixel1( y + xc, x + yc, color);
    putpixel1(-y + xc, x + yc, color);
    putpixel1(y + xc, -x + yc, color);
    putpixel1(-y + xc, -x + yc, color);

    while (x < y)
    {
    	
    	draw ++;
        delay(5);
		if (f < 0) f += (x << pixel) + pixel*3; //(f < 0) f += (x << 1) + 3;
        else
        {
            y-=pixel;
            f += ((x - y) << pixel) + pixel*5; //f += ((x - y) << 1) + 5;
        }
        x+=pixel;
	    if (draw == 1){
			draw = 0;
		putpixel1(x + xc, y + yc, color);
	    putpixel1(-x + xc, y + yc, color);
	    putpixel1(x + xc, -y + yc, color);
	    putpixel1(-x + xc, -y + yc, color);
	    putpixel1( y + xc, x + yc, color);
	    putpixel1(-y + xc, x + yc, color);
	    putpixel1(y + xc, -x + yc, color);
	    putpixel1(-y + xc, -x + yc, color);}
	}
}
//2.4. Ve hinh cau
void drawSphere(int xc, int yc, int r, int color)
{
	putpixel(xc, yc, 2);
	drawCircleMidpoint(xc, yc, r, color);
	elipMidpoint(xc, yc, r, r*(sqrt(2)/4), color);
	//elipMidpointDoc(xc, yc, r/3, r, color);
}
//2.5. Nhap du lieu
int l_nhapDuLieu(){
			chonHinh(2);
			setfillstyle(1, 15);
			bar(30,190,220,480); 
			v_veTrucOxyz();
			outtextxy(50, 200, "X: ");
			outtextxy(50, 250, "Y: ");
			outtextxy(50, 300, "Z: ");
			outtextxy(50, 350, "R: ");
			int x = 150;
			int y = 200;
			string so;
			int kichThuoc[4];
			int dem = 0;//dem kich thuoc cua hinh hop
			int check = 0;//dem de thoat ra hoi nhap
			while(true){
				//nhap so vao man hinh graphic
				int Mx, My;
				getmouseclick(WM_LBUTTONDOWN, Mx, My);
				if(Mx>70 && Mx<180 && My>520 && My<550){
					setfillstyle(1, 0);
					bar(250,0,890,590);
					v_veTrucOxyz();
					return 2;
				}
				if(Mx>265 && Mx<365 && My>7 && My<34){
					chonHinh(1);
					return 1;		
				}
				if(Mx > 50 && Mx < 200 && My > 20 && My <60){
					return 3;
				}
				if(kbhit()){
					char chr;
					chr = getch();
					if(int(chr) == 8){
						x -=15;
						outtextxy(x, y, " ");
					}
					else if (int(chr) >= 48 && int(chr) <= 57  || int(chr) == 13 || int(chr)==45){
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
						if(check > 3){
							drawSphere((kichThuoc[0] - kichThuoc[2]*(sqrt(2)/4))*pixel + 450, 400 - (kichThuoc[1] - kichThuoc[2]*(sqrt(2)/4))*pixel , kichThuoc[3] * pixel, 2);
							l_xuatDiem(kichThuoc[0], kichThuoc[1], kichThuoc[2]);
							return 2;
							
						}
					}
					
				}
			}
}
// XU LI 2D
//tiem kich

int tiemKich(){
	xoaKhungChiTiet();
	int a = veMayBay();
	return a;
//	while(true){
//		//xu li chuyen ngu canh
//		int Mx, My;
//		getmouseclick(WM_LBUTTONDOWN, Mx, My);
//		if(Mx>70 && Mx<180 && My>520 && My<550){
//			setfillstyle(1, 0);
//			bar(250,0,890,590);
//			chonNguCanh(1);
//			return 2;
//		}		
//		if(Mx>380 && Mx<515 && My>7 && My<34){
//			chonNguCanh(2);
//			veHCN(255,100,570,0);
//			return 1;
//		}
//		if(kbhit()){
//			break;
//		}
//		if(Mx > 50 && Mx < 200 && My > 80 && My <120){
//			return 3;
//		}
//		
//		//end xu li chuyen ngu canh
//		int a = veMayBay();
//		return a;
//	}
}
// Hien ve coi xoay gio
// ve hinh tron tam cua canh quat
void put5x5pixel(int x,int y,int color){
	if(pixel==1){
		putpixel(x,y,color);
	}
	if(pixel%2==1){
		setcolor(color);
		x=x*pixel;
		y=y*pixel;
		int x1=x-(pixel-1)/2;
		int x2=x+(pixel-1)/2;
		int y1=y-(pixel-1)/2;
		int y2=y+(pixel-1)/2;
		for(int i=0;i<pixel;i++){
			line(x1,y1+i,x2,y1+i);
		}
	}
	
	
}
void h_drawcircle(int x0, int y0, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
	put5x5pixel(x0 + x, y0 + y, color);
	put5x5pixel(x0 + y, y0 + x, color);
	put5x5pixel(x0 - y, y0 + x, color);
	put5x5pixel(x0 - x, y0 + y, color);
	put5x5pixel(x0 - x, y0 - y, color);
	put5x5pixel(x0 - y, y0 - x, color);
	put5x5pixel(x0 + y, y0 - x, color);
	put5x5pixel(x0 + x, y0 - y, color);

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
void plotNuaPhai(int xc, int yc, int x, int y, int color)
{
//    put5x5pixel(xc+x, yc+y, color);
    put5x5pixel(xc-x, yc+y, color);
//    put5x5pixel(xc+x, yc-y, color);
    put5x5pixel(xc-x, yc-y, color);
}

void plotNuaTrai(int xc, int yc, int x, int y, int color)
{
    put5x5pixel(xc+x, yc+y, color);
//    put5x5pixel(xc-x, yc+y, color);
    put5x5pixel(xc+x, yc-y, color);
//    put5x5pixel(xc-x, yc-y, color);
}

void elipNuaTrai(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plotNuaPhai(xc, yc, x, y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plotNuaPhai(xc, yc, x, y, color);
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plotNuaPhai(xc, yc, x, y, color);
    }
}

void elipNuaPhai(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plotNuaTrai(xc, yc, x, y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plotNuaTrai(xc, yc, x, y, color);
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plotNuaTrai(xc, yc, x, y, color);
    }
}
void lineDDA(int x1, int y1, int x2, int y2, int color){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    put5x5pixel(x, y, color);
      
    int k=1;
    int m = 0;
    while(k <=step){
    	k++;
    	x += x_inc;
	    y += y_inc;		
	    m++;           
	    put5x5pixel(Round(x),Round(y),color);
}
}

void drawNuacircleDuoi(int x0, int y0, int radius,int color)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
		put5x5pixel(x0 + x, y0 + y, color);
		put5x5pixel(x0 + y, y0 + x, color);
		put5x5pixel(x0 - y, y0 + x, color);
		put5x5pixel(x0 - x, y0 + y, color);
//		put5x5pixel(x0 - x, y0 - y, color);
//		put5x5pixel(x0 - y, y0 - x, color);
//		put5x5pixel(x0 + y, y0 - x, color);
//		put5x5pixel(x0 + x, y0 - y, color);
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
void drawNuacircleTren(int x0, int y0, int radius,int color)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
//		put5x5pixel(x0 + x, y0 + y, color);
//		put5x5pixel(x0 + y, y0 + x, color);
//		put5x5pixel(x0 - y, y0 + x, color);
//		put5x5pixel(x0 - x, y0 + y, color);
		put5x5pixel(x0 - x, y0 - y, color);
		put5x5pixel(x0 - y, y0 - x, color);
		put5x5pixel(x0 + y, y0 - x, color);
		put5x5pixel(x0 + x, y0 - y, color);
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
// ham quay mot diem quanh 1 diem bat ki voi goc angle
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
// ve duong thang bang thuat toan dda
//void lineDDA(int x1, int y1, int x2, int y2, int color){       // thuat toan DDA
//    int  Dx = x2 - x1, Dy = y2 - y1;  
//    float x_inc , y_inc;
//    float step=max(abs(Dx),abs(Dy));
//    x_inc=Dx/step;
//    y_inc=Dy/step;
//    float x=x1, y=y1;
//    putpixel(x, y, color);
//      
//    int k=1;
//    while(k <=step){
//    	k++;
//    	x += x_inc;
//	    y += y_inc;           
//	        putpixel(Round(x),Round(y),color);
//		
//    }
//}
// ve tam giac can de ve canh quat
void veTamGiacCan(int xa, int ya, int xb, int yb, int xc, int yc, int color){
	lineDDA(xa, ya, xb, yb, color);
	lineDDA(xa, ya, xc, yc, color);
	lineDDA(xb, yb, xc, yc, color);
}
// xoay duong thang tu vi tri truyen vao den vi tri moi voi 1 goc = goc
// dong thoi xoa duong thang cu di
void xoayDuongThang(int &xa, int &ya, int &xb, int &yb, int xo, int yo, int goc, int color){
	lineDDA(xa, ya, xb, yb, bgColor);
	rotate_point(xa, ya, xo, yo, goc);
	rotate_point(xb, yb, xo, yo, goc);
		lineDDA(xa, ya, xb, yb, color);
	
	}

// xoay duong thang tu vi tri truyen vao den vi tri moi voi 1 goc = goc
// dong thoi xoa duong thang cu di
void xoayTamGiac(int &xa, int &ya, int &xb, int &yb, int &xc, int &yc, int xo, int yo, int goc, int color){
	veTamGiacCan(xa, ya, xb,  yb, xc, yc,bgColor);
	rotate_point(xa, ya, xo, yo, goc);
	rotate_point(xb, yb, xo, yo, goc);
	rotate_point(xc, yc, xo, yo, goc);
	veTamGiacCan(xa, ya, xb,  yb, xc, yc,color);
	
}
// than coi xoay gio
void veThanCoiXoayGio(int xo, int yo, int banKinh,int chieuCao, int color){
		lineDDA(xo+banKinh, yo, xo+banKinh*3, yo+chieuCao, color);
		lineDDA(xo-banKinh, yo, xo-banKinh*3, yo+chieuCao, color);
		lineDDA(xo-banKinh*5, yo+chieuCao, xo+banKinh*5, yo+chieuCao, color);
	
	}
// thuc hien phep quay nguyen canh quat

	
char * stringToChar(string s){
	char *text = new char[s.length() + 1];
	strcpy(text, s.c_str());
	return text;
}
void normal(){
	setbkcolor(bgColor);
	setcolor(15);
}
void inToaDo(int xb, int yb, int color){

	string s = "(" + to_string(xb/5-115) + "," + to_string(-(yb/5-60)) + ")";
	char * text = stringToChar(s);
	setbkcolor(0);
	setcolor(0);
	outtextxy(xb, yb, text);
	s = "(" + to_string(xb/5-115) + "," + to_string(-(yb/5-60)) + ")";
	text = stringToChar(s);
	normal();
	outtextxy(xb, yb, text);
	delete [] text;
}
void xoayToaDo(int xb, int yb, int xo, int yo, int goc, int color){
	
	string s = "(" + to_string(xb-575/pixel) + "," + to_string(-(yb-300/pixel)) + ")";
	char * text = stringToChar(s);
	setbkcolor(0);
	setcolor(0);
	outtextxy(xb*pixel, yb*pixel, text);
	rotate_point(xb, yb, xo, yo, goc);
	s = "(" + to_string(xb-575/pixel) + "," +  to_string(-(yb-300/pixel)) + ")";
	text = stringToChar(s);
	normal();
	outtextxy(xb*pixel, yb*pixel, text);
	delete [] text;
}
void h_inToaDo(int x, int y, string s, int color){
	setbkcolor(bgColor);
	setcolor(color);
	outtextxy(x*pixel, y*pixel, stringToChar(s));
}
void veHCN(int x, int y, int cao,int color){
	setbkcolor(0);
	setcolor(color);
	int y2 = y+cao;
	for(int i=y-1; i<=y2; i++){
		string s = "                              ";
		outtextxy(x-1,i,stringToChar(s));
	}
	normal();
}
void veMay(int x1, int y1, int r, int a, int b, int color){
	drawNuacircleTren(x1, y1-b, r, color);
	string toaDoCircle = "(" + to_string(x1-575/pixel) + "," + to_string(-(y1-b-r-300/pixel)) + ")";
	h_inToaDo(x1, y1-b-r-3,toaDoCircle, color);
	drawNuacircleDuoi(x1, y1+b, r, color);
	elipNuaTrai(x1-r, y1,a,b, color);
	elipNuaPhai(x1+r, y1,a,b, color);
	string toDoElip = "(" + to_string(x1+r+b-575/pixel) + "," + to_string(-(y1-300/pixel)) + ")";
	h_inToaDo(x1+r+b+5, y1,toDoElip, color);
}

void doiXungDiem(int &x1, int &y1, int xo, int yo){
	// tinh  tien ve goc toa do 1 doan sx = xo, sy = yo
	x1 = x1-xo;
	y1 = y1-yo;
	// doi xung tam O;
	x1 = -x1;
	y1 = -y1;
	// // tinh tien ve vi tri cu
	x1 = x1 + xo;
	y1 = y1 + yo;
}
void doiXungDuongThang(int &x1, int &y1, int &x2, int &y2, int xo, int yo, int color){
	doiXungDiem(x1, y1, xo, yo);
	doiXungDiem(x2, y2, xo, yo);
	lineDDA(x1,y1, x2, y2, color);
}
void doiXungTamGiac(int &xa, int &ya, int &xb, int &yb, int &xc, int &yc, int xDiem, int yDiem, int color){
	doiXungDiem(xa, ya, xDiem, yDiem);
	doiXungDiem(xb, yb, xDiem, yDiem);
	doiXungDiem(xc, yc, xDiem, yDiem);
	veTamGiacCan(xa, ya, xb, yb, xc, yc, color);
}
void doiXungCoiXoayGio(int xDiem, int yDiem, int xo,int yo, int r, int xadt1, int yadt1, int xbdt1, int ybdt1, int xadt2, int yadt2, int xbdt2, int ybdt2,
 int xa1, int ya1, int xb1, int yb1, int xc1, int yc1
, int xa2, int ya2, int xb2, int yb2, int xc2, int yc2, int xtraitren, int ytraitren, int xtraiduoi, int ytraiduoi,
int xphaitren, int yphaitren, int xphaiduoi, int yphaiduoi, int color){
	xoaKhungChiTiet();
	// doi xung tam duong tron
	doiXungDiem(xo, yo, xDiem, yDiem);
	// doi xung 2 duong thang
	doiXungDuongThang(xadt1, yadt1, xbdt1, ybdt1, xDiem, yDiem, color);
	doiXungDuongThang(xadt2, yadt2, xbdt2, ybdt2, xDiem, yDiem,  color);
	// doi xung 2 canh quat
	// doi xung 2 canh quat ben phai va canh quat o tren
	doiXungTamGiac(xa1, ya1, xb1, yb1, xc1, yc1, xDiem, yDiem, color);
	doiXungTamGiac(xa2, ya2, xb2, yb2, xc2, yc2, xDiem, yDiem, color);
	// voi moi canh quat da doi xung ta tim canh quat doi xung con lai qua tam duong tron
	doiXungTamGiac(xa1, ya1, xb1, yb1, xc1, yc1, xo, yo, color);
	doiXungTamGiac(xa2, ya2, xb2, yb2, xc2, yc2, xo, yo, color);
	// doi xung than
	doiXungDuongThang(xtraitren, ytraitren, xtraiduoi, ytraiduoi, xDiem, yDiem, color);
	doiXungDuongThang(xphaitren, yphaitren, xphaiduoi, yphaiduoi, xDiem, yDiem, color);
	// ve duong tron
	h_drawcircle(xo, yo, r, color);
	// ve tam giac
	// ve than
	lineDDA(xtraiduoi, ytraiduoi, xphaiduoi, yphaiduoi, color);
	
}
void veMatTroi(int xo, int yo, int r, int color){
	h_drawcircle(xo, yo, r, 4);
	string toDoElip = "(" + to_string(xo-575/pixel) + "," + to_string(-(yo-300/pixel)) + ")";
	h_inToaDo(xo, yo,toDoElip, color);
	int x1 = xo + r + 2;
	int y1 = yo;
	int x2 = x1 + r;
	int y2 = y1;
	int goc = 0;
	int soTia = 8;
	
	for(int i=1; i<=soTia/2; i++){
		lineDDA(x1, y1, x2, y2, 5);
		doiXungDuongThang(x1,y1, x2, y2, xo, yo, color);
		lineDDA(x1, y1, x2, y2, 5);
		
		if(i==1) goc = 360/soTia;
		rotate_point(x1, y1, xo, yo, goc);
		rotate_point(x2, y2, xo, yo, goc);
	}
	
	
}

int coiXoayGio(){
	xoaKhungChiTiet();
		int banKinh = 20/pixel;
	
	// xo, yo la tam cua canh quat
	int color = 15;
	int goc = 2*pixel;
	int xo=400/pixel, yo=375/pixel;
	int chieuDaiCanh = 30/pixel;
	int chieuCaoThan = 150/pixel;
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
	// than coi xoay gio
	int xtraitren = xo-banKinh;
	int ytraitren = yo;
	int xtraiduoi = xo - banKinh*3;
	int ytraiduoi = yo+chieuCaoThan;
	int xphaitren = xo+banKinh;
	int yphaitren = yo;
	int xphaiduoi = xo + banKinh*3;
	int yphaiduoi = yo+chieuCaoThan;
//-----------------

	int xDiem = 575/pixel;
	int yDiem = 300/pixel;
	doiXungCoiXoayGio(xDiem, yDiem, xo, yo, banKinh, xa1, ya1, xb1, yb1, xa2, ya2, xb2, yb2, xar, yar, xbr, ybr, xcr, ycr, 
	xat, yat, xbt, ybt, xct, yct, xtraitren, ytraitren, xtraiduoi, ytraiduoi, xphaitren, yphaitren, xphaiduoi, yphaiduoi, color);
	int xmay = 400/pixel, ymay = 175/pixel;
	int r = 40/pixel, a =65/pixel, b=25/pixel;
	// mat troi trong tim em
	int xmt = 750/pixel, ymt = 100/pixel;
	int rmt = 40/pixel;
	int count =0;
	
	while(true){
		int Mx, My;
		getmouseclick(WM_LBUTTONDOWN, Mx, My);
		if(Mx>70 && Mx<180 && My>520 && My<550){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			chonNguCanh(2);
//			v_veTrucOxyz();
			return 2;
		}
		if(Mx>265 && Mx<365 && My>7 && My<34){
			chonNguCanh(1);
//			veHCN(xo-chieuDaiCanh-chieuDaiTamGiac, yo-chieuDaiCanh-chieuDaiTamGiac, chieuDaiCanh+chieuDaiTamGiac+chieuCaoThan,0);	
//			
			veHCN(xmt*pixel - 2*r*pixel-100, ymt-2*r*pixel+4, 100, 0);
			return 1;		
		}
		if(Mx > 50 && Mx < 200 && My > 80 && My <120){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			return 3;
		}
		if(kbhit()){
			break;
		}
//		veMatTroi(xmt, ymt, rmt, color);
//		delay(100);
		veHCN(xmay*pixel-145, ymay*pixel-100, 160, 0);
		
			float tileTo = 1.1;
				float tileNho = 0.9;
		if(count%2==0){
			
			veMay(xmay, ymay, r*tileTo, a*tileTo, b*tileTo, 11);
		}else{
			veMay(xmay, ymay, r*tileNho, a*tileNho, b*tileNho, 11);
		}
			n_line(575/pixel,0/pixel,575/pixel,590/pixel);//oy  575
		setcolor(15);
		n_line(250/pixel,300/pixel,900/pixel,300/pixel);//ox 300
		h_drawcircle(xo, yo, banKinh, color);
		xoayDuongThang(xa1, ya1, xb1, yb1, xo, yo, goc, color);
		xoayDuongThang(xa2, ya2, xb2, yb2, xo, yo, goc, color);
		xoayToaDo(xbr, ybr, xo, yo, goc, color);
		xoayTamGiac(xar, yar, xbr, ybr, xcr, ycr, xo, yo, goc, 12);
		xoayTamGiac(xal, yal, xbl, ybl, xcl, ycl, xo, yo, goc, 11);
		xoayTamGiac(xat, yat, xbt, ybt, xct, yct, xo, yo, goc, 10);
		xoayTamGiac(xab, yab, xbb, ybb, xcb, ycb, xo, yo, goc, 9);
		veThanCoiXoayGio(xo, yo, banKinh, chieuCaoThan, 6);
		delay(100);
		count ++;
	}
}
void xuli2D(){
	int a = tiemKich();
	if(a==1){
//		setfillstyle(1, 0);
		setfillstyle(1, 15);
		bar(30,190,220,480); 
		while(true){
			int b= coiXoayGio();
			if(b==1){
				xuli2D();
			}
			if(b==2){
				continue;
			}
			if(b==3){
				return;
			}
		}
		
	}
	if(a==2){
		xuli2D();
	}
	if(a==3){
		return;
	}
}


void xuli3D(){
	int a = v_nhapDuLieu();
	if(a==1){
		setfillstyle(1, 0);
		v_veTrucOxyz();
		setfillstyle(1, 15);
		bar(30,190,220,480); 
		while(true){
			int b= l_nhapDuLieu();
			
			if(b==1){
				xuli3D();
			}
			if(b==2){
				continue;
			}
			if(b==3) return;
		}
		
	}
	else if(a==2){
		xuli3D();
	}
	else if(a==3) {
		return;
	}
}
void getMouseClick(){
	int x, y;        // Coordinates of the mouse click


    while (1)

    {
	    if(x > 50 && x < 200 && y > 20 && y <60){ //xua li 2d
	    	setcolor(1);
	    	setbkcolor(15);
			settextstyle(8, 0, 3);
			outtextxy(100, 28, "2D");
			setcolor(0);
			outtextxy(100, 88, "3D");
			
			setfillstyle(1, 0);
			bar(250,0,890,590);
			
			settextstyle(8, 0, 1);
			setcolor(0);
			
			chonNguCanh(1);
			xuli2D();
			x= 60; y = 100;
			//break;
			
		}
	    
	    if(x > 50 && x < 200 && y > 80 && y <120){ //xu li 3d
	    	setcolor(1);
	    	setbkcolor(15);
			settextstyle(8, 0, 3);
			outtextxy(100, 88, "3D");
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(100, 28, "2D");
			setfillstyle(1, 0);
			bar(250,0,890,590);
			chonHinh(1);
			
			//vinh:
			xuli3D();
			x= 60; y = 50;
			continue;
		}
		if(x>70 && x<180 && y>520 && y<550){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			v_veTrucOxyz();
			setfillstyle(1, 15);
			bar(30,190,220,480); 
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(kbhit()) break;
    }
	
    
    
    
}



int main()
{
	while(true){
	
	giaoDien();	
	getMouseClick();
	

    


    closegraph( );
	}
}
