#include <graphics.h> 
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
//#define length 200;
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
int color = 1;

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
int v_nhapDuLieu(){
			v_veTrucOxyz();
			outtextxy(50, 200, "X: ");
			outtextxy(50, 250, "Y: ");
			outtextxy(50, 300, "Z: ");
			outtextxy(50, 350, "Dai: ");
			outtextxy(50, 400, "Rong: ");
			outtextxy(50, 450, "Cao: ");
			int x = 150;
			int y = 200;
			string so;
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
						if(check > 5){
							v_hinhHopCN((kichThuoc[0] - kichThuoc[2])*5 + 450, 400 - (kichThuoc[1] - kichThuoc[2])*5, kichThuoc[3], kichThuoc[4], kichThuoc[5]);
							//v_hinhChopVuong(kichThuoc[0]*5 + 450, kichThuoc[1]*5 + 400, kichThuoc[2], kichThuoc[3], kichThuoc[4]);
							break;
						}
					}
					
				}
			}
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
			outtextxy(50, 200, "Height: ");
			
			
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
			
			
			//vinh:
			v_nhapDuLieu();
		}
		if(x>70 && x<180 && y>520 && y<550){
			setfillstyle(1, 0);
			bar(250,0,890,590);
			v_veTrucOxyz();
			setfillstyle(1, 15);
			bar(30,190,220,480); 
		}
		if(kbhit()) break;
    }
	
    
    
    
}



int main()
{
	
	giaoDien();	
	getMouseClick();
	

    


    closegraph( );
}
