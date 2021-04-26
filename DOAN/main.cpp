#include <graphics.h> 
#include <iostream>
#include <windows.h>
using namespace std;
//#define length 200;

// Huan
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

void getMouseClick(){
	int x, y;        // Coordinates of the mouse click


    while (1)

    {

        getmouseclick(WM_LBUTTONDOWN, x, y);

	    if(x > 50 && x < 200 && y > 20 && y <60){ //xua li 2d
	    	setcolor(GREEN);
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
	    	setcolor(GREEN);
			settextstyle(8, 0, 3);
			outtextxy(100, 88, "3D");
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(100, 28, "2D");
			setfillstyle(1, 2);
			bar(250,0,890,590);
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
