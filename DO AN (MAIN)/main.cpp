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
	put5x5pixel((x0 + x)/5, (y0 + y)/5, color);
	put5x5pixel((x0 + y)/5, (y0 + x)/5, color);
	put5x5pixel((x0 - y)/5, (y0 + x)/5, color);
	put5x5pixel((x0 - x)/5, (y0 + y)/5, color);
	put5x5pixel((x0 - x)/5, (y0 - y)/5, color);
	put5x5pixel((x0 - y)/5, (y0 - x)/5, color);
	put5x5pixel((x0 + y)/5, (y0 - x)/5, color);
	put5x5pixel((x0 + x)/5, (y0 - y)/5, color);
 
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
		n_line((x*80+a)/5,(y*300+b)/5,(x*250+a)/5,(y*300+b)/5);
		n_line((x*150+a)/5,(y*340+b)/5,(x*200+a)/5,(y*340+b)/5);
		n_line((x*150+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
		n_line((x*200+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
		n_line((x*80+a)/5,(y*380+b)/5,(x*115+a)/5,(y*380+b)/5);
		n_line((x*132+a)/5,(y*380+b)/5,(x*250+a)/5,(y*380+b)/5);
		//ellipse(x*250+a,y*340+b,270,90,x*80,y*40);
		n_line((x*250+a)/5,(y*340+b-y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		n_line((x*250+a)/5,(y*340+b+y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		
		n_line((x*100+a)/5,(y*270+b)/5,(x*150+a)/5,(y*300+b)/5);
		n_line((x*100+a)/5,(y*270+b)/5,(x*200+a)/5,(y*300+b)/5);
		n_line((x*80+a)/5,(y*300+b)/5,(x*65+a)/5,(y*260+b)/5);
		//arc(x*80+a,y*340+b,180,270,((x+y)/2)*40);
		//n_drawcircle((x*80+a)/5,(y*340+b)/5,((x+y)/2)*40/5,1);
		n_line((x*40+a)/5,(y*340+b)/5,(x*40+a)/5,(y*260+b)/5);
		n_line((x*40+a)/5,(y*260+b)/5,(x*65+a)/5,(y*260+b)/5);
		n_line((x*261+a)/5,(y*333+b)/5,(x*320+a)/5,(y*333+b)/5);
		n_line((x*261+a)/5,(y*333+b)/5,(x*261+a)/5,(y*310+b)/5);
		n_rectangle((x*100+a)/5,(y*310+b)/5,(x*120+a)/5,(y*330+b)/5);
		n_rectangle((x*130+a)/5,(y*310+b)/5,(x*150+a)/5,(y*330+b)/5);
		n_rectangle((x*160+a)/5,(y*310+b)/5,(x*180+a)/5,(y*330+b)/5);
		n_rectangle((x*190+a)/5,(y*310+b)/5,(x*210+a)/5,(y*330+b)/5);
		n_rectangle((x*220+a)/5,(y*310+b)/5,(x*240+a)/5,(y*330+b)/5);
	setcolor(color);
}
void MayBayNguoc(float x,float y,float a,float b){
	int color=getcolor();
	setcolor(15);
	//--------may bay
		n_line((x*80+a)/5,(y*300+b)/5,(x*250+a)/5,(y*300+b)/5);
		n_line((x*150+a)/5,(y*340+b)/5,(x*200+a)/5,(y*340+b)/5);
		n_line((x*150+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
		n_line((x*200+a)/5,(y*340+b)/5,(x*100+a)/5,(y*400+b)/5);
		n_line((x*80+a)/5,(y*380+b)/5,(x*115+a)/5,(y*380+b)/5);
		n_line((x*132+a)/5,(y*380+b)/5,(x*250+a)/5,(y*380+b)/5);
		//ellipse(x*250+a,y*340+b,90,270,x*80,y*40);
		n_line((x*250+a)/5,(y*340+b-y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		n_line((x*250+a)/5,(y*340+b+y*40)/5,(x*250+a+x*80)/5,(y*340+b)/5);
		
		n_line((x*100+a)/5,(y*270+b)/5,(x*150+a)/5,(y*300+b)/5);
		n_line((x*100+a)/5,(y*270+b)/5,(x*200+a)/5,(y*300+b)/5);
		n_line((x*80+a)/5,(y*300+b)/5,(x*65+a)/5,(y*260+b)/5);
		//arc(x*80+a,y*340+b,270,360,y*40);
		n_line((x*40+a)/5,(y*340+b)/5,(x*40+a)/5,(y*260+b)/5);
		n_line((x*40+a)/5,(y*260+b)/5,(x*65+a)/5,(y*260+b)/5);
		n_line((x*261+a)/5,(y*333+b)/5,(x*320+a)/5,(y*333+b)/5);
		n_line((x*261+a)/5,(y*333+b)/5,(x*261+a)/5,(y*310+b)/5);
		n_rectangle((x*100+a)/5,(y*310+b)/5,(x*120+a)/5,(y*330+b)/5);
		n_rectangle((x*130+a)/5,(y*310+b)/5,(x*150+a)/5,(y*330+b)/5);
		n_rectangle((x*160+a)/5,(y*310+b)/5,(x*180+a)/5,(y*330+b)/5);
		n_rectangle((x*190+a)/5,(y*310+b)/5,(x*210+a)/5,(y*330+b)/5);
		n_rectangle((x*220+a)/5,(y*310+b)/5,(x*240+a)/5,(y*330+b)/5);
		
		
		int x1=x*100+a+20;
		int y1=y*310+b;
		inToaDo(x1,y1,15);
	setcolor(color);
}
void Nha(int i,int y){
	n_rectangle((520-i)/5,(459-y)/5,(560-i)/5,(430-y)/5);
	n_rectangle((560-i)/5,(459-y)/5,(620-i)/5,(430-y)/5);
	
	
	n_rectangle((440-i)/5,(430-y)/5,(500-i)/5,(459-y)/5);
	n_rectangle((400-i)/5,(430-y)/5,(440-i)/5,(459-y)/5);
	
}
void NocNha(int i,int y){
	int color=getcolor();
	setcolor(12);
	n_line((540-i)/5,(410-y)/5,(560-i)/5,(430-y)/5);
	n_line((540-i)/5,(410-y)/5,(520-i)/5,(430-y)/5);
	n_line((600-i)/5,(410-y)/5,(620-i)/5,(430-y)/5);
	n_line((600-i)/5,(410-y)/5,(540-i)/5,(410-y)/5);
	
	n_line((420-i)/5,(410-y)/5,(440-i)/5,(430-y)/5);
	n_line((420-i)/5,(410-y)/5,(400-i)/5,(430-y)/5);
	n_line((420-i)/5,(410-y)/5,(480-i)/5,(410-y)/5);
	n_line((480-i)/5,(410-y)/5,(500-i)/5,(430-y)/5);
	setcolor(color);
}
int veMayBay(){
	setcolor(15);
	float x=0.5,y=0.5,a=250,b=0,c=600;
	int x1,y1,xnha=0,ynha=0,xnocnha=0,ynocnha=0;
	int xbom=350;
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
		
		MayBay(x,y,a,0);
		MayBayNguoc(-x,y,c,80);
		setcolor(9); //huan
		Nha(xnha,ynha);
		setcolor(12);
		NocNha(xnocnha,ynocnha);
		setcolor(10); //huan
		//mat dat
		n_line(250/5+5,459/5,800/5,459/5);
		
		setcolor(15);
		n_drawcircle(xbom,ybom,rbom,12);
		if(ybom<460){
			inToaDo(xbom+10,ybom,15);
		}
		if(rbom==70){
			break;
		}
		ybom+=2;
		if(ybom==460){
			ybom-=2;
			rbom+=5;
			n_drawcircle(xbom,ybom,rbom,12);
			//Loang(xbom/50,458/50,15,12);
			for(int i=0;i<rbom;i++){
				n_drawcircle(xbom,ybom,i,12);
			}
			ynha+=2;
			ynocnha+=4;
		}
		c--;
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
	v_lineDDAforOxyz(x-2, y-2, x+2, y-2, color);
	v_lineDDAforOxyz(x-2, y-2, x-2, y+2, color);
	v_lineDDAforOxyz(x-2, y+2, x+2, y+2, color);
	v_lineDDAforOxyz(x+2, y-2, x+2, y+2, color);
	for(int i = 0; i<5; i++){
		v_lineDDAforOxyz(x-2, y-2+i, x+2, y-2+i, color);
		v_lineDDAforOxyz(x-2+i, y+2, x+2, y+2, color);
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
        if (dem %5 == 0){
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
        if(dem % 5 == 0){
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
        if(dem % 2 == 0){
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
	int dai = Round(CD*(5/2)), rong = CR*5, cao = CC*5;
	
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
							v_hinhHopCN((kichThuoc[0] - kichThuoc[2]*(sqrt(2)/2))*5 + 450, 400 - (kichThuoc[1] - kichThuoc[2]*(sqrt(2)/2))*5, kichThuoc[3], kichThuoc[4], kichThuoc[5]);
							return 2;
						}
					}
					
				}
			}
}
//Long-------------------------------------------------------------------------------------
//2.1. Ve elip nam ngang
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
		putpixel1(xc+x, yc-y, color);
    	putpixel1(xc-x, yc-y, color);
    	dem++;
		}
		putpixel1(xc+x, yc+y, color);
    	putpixel1(xc-x, yc+y, color);}		
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
		if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
	    if (draw == 5){
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
	putpixel1(xc, yc, 2);
	drawCircleMidpoint(xc, yc, r, color);
	elipMidpoint(xc, yc, r, r/3, color);
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
							drawSphere((kichThuoc[0] - kichThuoc[2]*(sqrt(2)/2))*5 + 450, 400 - (kichThuoc[1] - kichThuoc[2]*(sqrt(2)/2))*5 , kichThuoc[3] * 5, 2);
							//v_hinhChopVuong(kichThuoc[0]*5 + 450, kichThuoc[1]*5 + 400, kichThuoc[2], kichThuoc[3], kichThuoc[4]);
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
	setcolor(color);
	x=x*5;
	y=y*5;
	int x1=x-2;
	int x2=x+2;
	int y1=y-2;
	int y2=y+2;
	for(int i=0;i<5;i++){
		line(x1,y1+i,x2,y1+i);
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
void drawcircle(int x0, int y0, int radius,int color)
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
void quayCanhQuat(int xo, int yo, int color){
	
	int banKinh = 15;
	
	// xo, yo la tam cua canh quat
	int goc = 5;

	int chieuDaiCanh = 25;
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
		drawcircle(xo, yo, banKinh, color);
		xoayDuongThang(xa1, ya1, xb1, yb1, xo, yo, goc, color);
		xoayDuongThang(xa2, ya2, xb2, yb2, xo, yo, goc, color);
		xoayTamGiac(xar, yar, xbr, ybr, xcr, ycr, xo, yo, goc, color);
		xoayTamGiac(xal, yal, xbl, ybl, xcl, ycl, xo, yo, goc, color);
		xoayTamGiac(xat, yat, xbt, ybt, xct, yct, xo, yo, goc, color);
		xoayTamGiac(xab, yab, xbb, ybb, xcb, ycb, xo, yo, goc, color);
		veThanCoiXoayGio(xo, yo, banKinh, 150, color);
	}
	}
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

	string s = "(" + to_string(xb/5) + "," + to_string(yb/5) + ")Thuc hien tot 5k de phong chong dich";
	char * text = stringToChar(s);
	setbkcolor(0);
	setcolor(0);
	outtextxy(xb, yb, text);
	s = "(" + to_string(xb/5) + "," + to_string(yb/5) + ")Thuc hien tot 5k de phong chong dich";
	text = stringToChar(s);
	normal();
	outtextxy(xb, yb, text);
	delete [] text;
}
void xoayToaDo(int xb, int yb, int xo, int yo, int goc, int color){
	
	string s = "(" + to_string(xb) + "," + to_string(yb) + ")";
	char * text = stringToChar(s);
	setbkcolor(0);
	setcolor(0);
	outtextxy(xb*5, yb*5, text);
	rotate_point(xb, yb, xo, yo, goc);
	s = "(" + to_string(xb) + "," + to_string(yb) + ")";
	text = stringToChar(s);
	normal();
	outtextxy(xb*5, yb*5, text);
	delete [] text;
}
void veHCN(int x, int y, int cao,int color){
	setbkcolor(0);
	setcolor(color);
	int y2 = y+cao;
	for(int i=y-1; i<=y2; i++){
		string s = "                                   ";
		outtextxy(x-1,i,stringToChar(s));
	}
	normal();
}

int coiXoayGio(){
	xoaKhungChiTiet();
		int banKinh = 4;
	
	// xo, yo la tam cua canh quat
	int color = 15;
	int goc = 10;
	int xo=100, yo=70;
	int chieuDaiCanh = 6;
	int chieuCaoThan = 30;
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
			//veHCN(xo-chieuDaiCanh-chieuDaiTamGiac, yo-chieuDaiCanh-chieuDaiTamGiac, chieuDaiCanh+chieuDaiTamGiac+chieuCaoThan,0);	
			veHCN(255,100,570,0);
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
		drawcircle(xo, yo, banKinh, color);
		xoayDuongThang(xa1, ya1, xb1, yb1, xo, yo, goc, color);
		xoayDuongThang(xa2, ya2, xb2, yb2, xo, yo, goc, color);
		xoayToaDo(xbr, ybr, xo, yo, goc, color);
		xoayTamGiac(xar, yar, xbr, ybr, xcr, ycr, xo, yo, goc, color);
		xoayTamGiac(xal, yal, xbl, ybl, xcl, ycl, xo, yo, goc, color);
		xoayTamGiac(xat, yat, xbt, ybt, xct, yct, xo, yo, goc, color);
		xoayTamGiac(xab, yab, xbb, ybb, xcb, ycb, xo, yo, goc, color);
		veThanCoiXoayGio(xo, yo, banKinh, chieuCaoThan, color);
		delay(100);
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
