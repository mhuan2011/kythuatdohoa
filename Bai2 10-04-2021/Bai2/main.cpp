#include <iostream>
#include <graphics.h>
#include <math.h>
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define DELAY 10
#include <conio.h>
using namespace std ;
int color = WHITE;


//huan duong dut gach
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

// hien hcn co to mau
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
	
	// long gach cham cham gach
	
void HaiChamGach(int x1, int y1, int x2, int y2, int c){ //---- - - ----
        int x, y, dx, dy,d; 
        y = y1; 
       dx = x2 - x1; 
       dy = y2 - y1; 
       d= dy - dx/2; 
       int count = 0;
	   if(x1==x2){
       	while(y1<=y2){
			if((count != 4)&&(count != 6)&&(count != 8))
				putpixel(x1, y1++, c);
			count = count + 1 ;
			if(count == 9){
				count = 0;
			}
		   }
	   }else{
       for (x=x1; x<=x2; x++){ 
           if((count != 4)&&(count != 6)&&(count != 8))
				putpixel(x, y, c);
           if (d <= 0) 
                d = d + dy; 
          else { 
                y ++; 
               d = d + dy - dx; 
          }
          count ++ ;
			if(count == 9){
				count = 0;
		  } 
    	}
	}
}

void MotChamGach(int x1, int y1, int x2, int y2, int c){ //---- - - ----
        int x, y, dx, dy,d; 
        y = y1; 
       dx = x2 - x1; 
       dy = y2 - y1; 
       d= dy - dx/2; 
       int count = 0;
	   if(x1==x2){
       	while(y1<=y2){
			if((count != 4)&&(count != 6))
				putpixel(x1, y1++, c);
			count = count + 1 ;
			if(count == 7){
				count = 0;
			}
		   }
	   }else{
       for (x=x1; x<=x2; x++){ 
           if((count != 4)&&(count != 6))
				putpixel(x, y, c);
           if (d <= 0) 
                d = d + dy; 
          else { 
                y ++; 
               d = d + dy - dx; 
          }
          count ++ ;
			if(count == 7){
				count = 0;
		  } 
    	}
	}
}


//vinh: ve~ mui ten
void lineDDA1(int x1, int y1, int x2, int y2){ // ve duong thang~ binh` thuong`
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

void hinhMuiTen(){
	int x, y, canh = 20;
	cout << "Nhap x: "; cin >> x;
	cout << "Nhap y: "; cin >> y;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);  
	 
	//ve tam giac deu
	lineDDA1(x, y, x, (y+canh));
	lineDDA1(x, y+canh, x + ((canh*sqrt(3))/2), y + canh/2);
	lineDDA1(x + ((canh*sqrt(3))/2), y+canh/2, x, y);
	
	
	
	//ve duong thang
	lineDDA1(x , y + canh/2, x-100, y+canh/2);
	lineDDA1(x , y + canh/2 + 1, x-100, y+canh/2 + 1);
	lineDDA1(x , y + canh/2 - 1, x-100, y+canh/2 - 1);
}


void menu(){
	int chon = -1;
	while(chon!=0){
		cout << "1.Ve duong dut gach\n";
		cout << "2.Ve hcn va to mau\n";
		cout << "3. Ve mui ten\n";
		cout << "4. Ve duong 2 cham gach\n";
		cout << "5. Ve duong cham gach\n";
		cout << "0.Thoat\n";
		cout << "Vui long chon so? ";

		cin >> chon;
		switch(chon){
			case 1:{
				int Ax, Ay, Bx, By;
			    int length;
			    cout << "---Toa do diem dau--- \n";
			    cout <<"xA = ";
			    cin >> Ax;
			    cout <<"yA = ";
			    cin >> Ay;
			    cout << "---Toa do diem cuoi--- \n";
			    cout <<"xB = ";
			    cin >> Bx;
			    cout <<"yB = ";
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
			    closegraph();
				break;
			}
			case 2:{
				int xa, ya, d, r;
				cout << "Nhap toa do diem A cua hinh chu nhat\nxA = ";
				cin >> xa;
				cout << "yA = ";
				cin >> ya;
				cout << "Chieu dai = ";
				cin >> d;
				cout << "Chieu rong = ";
				cin >> r;
				int xc = xa + d;
				int yc = ya + r;
				int gd,gm;
				gd=DETECT;
			    initgraph(&gd,&gm,NULL);        
			    setcolor(255);
			    settextstyle(10,0,2);
			    outtextxy(100,10,"Hinh chu nhat");
				veHCN(xa, ya, xc, yc, color);
				getch();
				closegraph();
				break;
			}
			case 3:{
				hinhMuiTen();
			    getch();
				break;
			}
			case 4:{
				int Ax, Ay, Bx, By;
			    int length;
			    cout << "---Toa do diem dau--- \n";
			    cout <<"xA = ";
			    cin >> Ax;
			    cout <<"yA = ";
			    cin >> Ay;
			    cout << "---Toa do diem cuoi--- \n";
			    cout <<"xB = ";
			    cin >> Bx;
			    cout <<"yB = ";
			    cin >> By;
		
			    int gd,gm;
			    gd=DETECT;
			    initgraph(&gd,&gm,NULL);        
			    setcolor(255);
			    settextstyle(10,0,2);
			    outtextxy(100,10,"duong thang 2 cham gach");
			    HaiChamGach(Ax,Ay,Bx,By, color);      
			    getch();
			    closegraph();
				break;
				break;
			}
			case 5:{
				int Ax, Ay, Bx, By;
			    int length;
			    cout << "---Toa do diem dau--- \n";
			    cout <<"xA = ";
			    cin >> Ax;
			    cout <<"yA = ";
			    cin >> Ay;
			    cout << "---Toa do diem cuoi--- \n";
			    cout <<"xB = ";
			    cin >> Bx;
			    cout <<"yB = ";
			    cin >> By;
		
			    int gd,gm;
			    gd=DETECT;
			    initgraph(&gd,&gm,NULL);        
			    setcolor(255);
			    settextstyle(10,0,2);
			    outtextxy(100,10,"duong thang 1 cham gach");
			    MotChamGach(Ax,Ay,Bx,By, color);      
			    getch();
			    closegraph();
				break;
			}
			case 0:{
				return;
				break;
			}
		}
	}
	
	
	
	}
	
int main(){
	menu();
    return 0;
}
