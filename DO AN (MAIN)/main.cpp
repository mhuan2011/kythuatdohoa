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
void veMayBay(){
	float x=0.5,y=0.5,a=0,b=0,c=600;
	int x1,y1,i=0;
	int ybom=200;
	int rbom=10;
	char stop=1;
	
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
			break;
		}
		ybom+=2;
		if(ybom==460){
			ybom-=2;
			rbom+=5;
			circle(100,ybom,rbom);
			Loang(100,458,12,0);
		}
		c--;
		i++;
		delay(30);
		if(kbhit()){
			stop = getch();	
		}
		
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

//putpixel Oz
void v_lineDDAOz(int x1, int y1, int x2, int y2, int color){       
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
        if(dem % 3 == 0){
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
	v_lineDDAOz(450, 400, 270, 530, 15);
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

//1.6. Ve hinh chop vuong
void v_hinhChopVuong(int x, int y, int CD, int CR, int CC){
	int dai = Round(CD*5/2), rong = CR*5, cao = CC*5;
	
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
	
	//ve canh day cua hinh chop
	v_lineDDA3(x, y, a.x, a.y, 2, 2);
	v_lineDDA3(x, y, x+rong, y, 2, 2);
	v_lineDDA(a.x, a.y, a.x+rong, a.y, 2);
	v_lineDDA(a.x+rong, a.y, x+rong, y, 2);
	
	//ve duong cao
	v_lineDDA3(x, y, x, y-cao, 2, 2);
	v_lineDDA(a.x, a.y, x, y-cao, 2);
	v_lineDDA(a.x+rong, a.y, x, y-cao, 2);
	v_lineDDA(x+rong, y, x, y-cao, 2);
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
					break;
				}
				
				if(Mx>380 && Mx<485 && My>7 && My<34){
					chonHinh(2);
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
					else if (int(chr) >= 48 && int(chr) <= 57  || int(chr) == 13){
						if(int(chr) == 13){
							int tmp = atoi(so.c_str());
							so = "";
							kichThuoc[dem] = tmp;
							y += 50;
							x = 150;
							dem++;
							check++;
							soHien = "";
							
//							cout<<"kichThuoc[0] = "<<kichThuoc[0];
						}
						soHien = chr;
						char *cstr = new char[soHien.length()+1];
						strcpy(cstr, soHien.c_str());
						delete [] cstr;
						//-----------
						char a[10];
				
						a[0]= chr;

						so += a[0];

						cout <<a;
						outtextxy(x, y, cstr);
						x+=15;
						if(check > 5){
							v_hinhHopCN((kichThuoc[0] - kichThuoc[2])*5 + 450, 400 - (kichThuoc[1] - kichThuoc[2])*5, kichThuoc[3], kichThuoc[4], kichThuoc[5]);
							//v_hinhChopVuong(kichThuoc[0]*5 + 450, kichThuoc[1]*5 + 400, kichThuoc[2], kichThuoc[3], kichThuoc[4]);
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
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
    putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    int dem = 0;
    while(fx<fy)
    {
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
		if(dem == 5){
			dem = 0;
		}
		else if((dem == 3) || (dem == 4)){
			dem++;
		}
		else{
		putpixel(xc+x, yc-y, color);
    	putpixel(xc-x, yc-y, color);
    	dem++;
		}
		putpixel(xc+x, yc+y, color);
    	putpixel(xc-x, yc+y, color);		
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
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
        if(dem == 5){
			dem = 0;
		}
		else if((dem == 3) || (dem == 4)){
			dem++;
		}
		else{
		putpixel(xc+x, yc-y, color);
    	putpixel(xc-x, yc-y, color);
    	dem++;
		}
		putpixel(xc+x, yc+y, color);
    	putpixel(xc-x, yc+y, color);
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
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
    putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    p = Round(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    int dem = 0;
    while(fx<fy)
    {
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
		if(dem == 5){
			dem = 0;
		}
		else if((dem == 3) || (dem == 4)){
			dem++;
		}
		else{
		putpixel(xc+x, yc+y, color);
    	putpixel(xc+x, yc-y, color);
    	dem++;
		}
		putpixel(xc-x, yc+y, color);
    	putpixel(xc-x, yc-y, color);	
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
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
        if(dem == 5){
			dem = 0;
		}
		else if((dem == 3) || (dem == 4)){
			dem++;
		}
		else{
		putpixel(xc+x, yc+y, color);
    	putpixel(xc+x, yc-y, color);
    	dem++;
		}
		putpixel(xc-x, yc+y, color);
    	putpixel(xc-x, yc-y, color);
    }
}
//2.3. Ve hinh tron
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int f = 1 - r;

    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);

    while (x < y)
    {
    	
    	
        delay(5);
		if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
	    putpixel(x + xc, y + yc, color);
	    putpixel(-x + xc, y + yc, color);
	    putpixel(x + xc, -y + yc, color);
	    putpixel(-x + xc, -y + yc, color);
	    putpixel( y + xc, x + yc, color);
	    putpixel(-y + xc, x + yc, color);
	    putpixel(y + xc, -x + yc, color);
	    putpixel(-y + xc, -x + yc, color);
	}
}
//2.4. Ve hinh cau
void drawSphere(int xc, int yc, int r, int color)
{
	putpixel(xc, yc, 2);
	drawCircleMidpoint(xc, yc, r, color);
	elipMidpoint(xc, yc, r, r/3, color);
	elipMidpointDoc(xc, yc, r/3, r, color);
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
					break;
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
						if(check > 3){
							drawSphere((kichThuoc[0] - kichThuoc[2])*5 + 450, 400 - (kichThuoc[1] - kichThuoc[2])*5, kichThuoc[3] * 5, 2);
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
	while(true){
		//xu li chuyen ngu canh
		int Mx, My;
		getmouseclick(WM_LBUTTONDOWN, Mx, My);
		if(Mx>70 && Mx<180 && My>520 && My<550){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			v_veTrucOxyz();
			break;
		}
		if(Mx>265 && Mx<365 && My>7 && My<34){
			chonNguCanh(1);
			veMayBay();
			return 3;		
		}		
		if(Mx>380 && Mx<515 && My>7 && My<34){
			chonNguCanh(2);
			
			return 1;
		}
		if(kbhit()){
			break;
		}
		if(Mx > 50 && Mx < 200 && My > 80 && My <120){
			return 3;
		}
		
		//end xu li chuyen ngu canh
	}
}
// Hien ve coi xoay gio
// ve hinh tron tam cua canh quat
void drawcircle(int x0, int y0, int radius,int color)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, color);
	putpixel(x0 + y, y0 + x, color);
	putpixel(x0 - y, y0 + x, color);
	putpixel(x0 - x, y0 + y, color);
	putpixel(x0 - x, y0 - y, color);
	putpixel(x0 - y, y0 - x, color);
	putpixel(x0 + y, y0 - x, color);
	putpixel(x0 + x, y0 - y, color);
 
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
	setcolor(color);
}
void xoayToaDo(int xb, int yb, int xo, int yo, int goc, int color){

	string s = "(" + to_string(xb) + "," + to_string(yb) + ")";
	char * text = stringToChar(s);
	setbkcolor(0);
	setcolor(0);
	outtextxy(xb, yb, text);
	rotate_point(xb, yb, xo, yo, goc);
	s = "(" + to_string(xb) + "," + to_string(yb) + ")";
	text = stringToChar(s);
	normal();
	outtextxy(xb, yb, text);
	
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
		int banKinh = 20;
	
	// xo, yo la tam cua canh quat
	int goc = 5;
	int xo=400, yo=400;
	int chieuDaiCanh = 30;
	int chieuCaoThan = 150;
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
			v_veTrucOxyz();
			break;
		}
		if(Mx>265 && Mx<365 && My>7 && My<34){
			chonNguCanh(1);
			veHCN(xo-chieuDaiCanh-chieuDaiTamGiac, yo-chieuDaiCanh-chieuDaiTamGiac, chieuDaiCanh+chieuDaiTamGiac+chieuCaoThan,0);
			return 1;		
		}
		if(Mx > 50 && Mx < 200 && My > 80 && My <120){
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
			cout <<"b = "<<b;
			if(b==1){
				xuli3D();
			}
			if(b==2){
				continue;
			}
			if(b==3) return;
		}
		
	}
	if(a==2){
		xuli3D();
	}
	if(a==3) return;
}
void getMouseClick(){
	int x, y;        // Coordinates of the mouse click


    while (1)

    {
		
        
		
	    if(x > 50 && x < 200 && y > 20 && y <60){ //xua li 2d
	    	setcolor(1);
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
			break;
			
		}
	    
	    if(x > 50 && x < 200 && y > 80 && y <120){ //xu li 3d
	    	setcolor(1);
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