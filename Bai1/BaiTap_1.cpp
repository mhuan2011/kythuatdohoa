#include<iostream>
#include <graphics.h>
#include<string.h>
using namespace std;
int main(){
	int x,y,x1,y1;
	cout<<"Nhap x:";cin>>x1;
	cout<<"Nhap y:";cin>>y1;
	initwindow(600,600);
	
	
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
	if(x1>0){
    		x=x1*5+300;
		}
		if(y1<0){
			y=y1*5+300;
		}
        if(x1<0){
        	x=300-x1*5;
		}
		if(y1>0){
			y=300-y1*5;
		}
        circle(x,y,2);
        line(x,y,300,y);
        line(x,y,x,300);
        char c='1';
	while(c!='0'){
		
	    if (ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, x, y);
	    	if(x>300){
	    		x1=(x-300)/5;
			}
			if(y<300){
				y1=(300-y)/5;
			}
	        if(x<300){
	        	x1=-(300-x)/5;
			}
			if(y>300){
				y1=-(y-300)/5;
			}
	        printf("\nleft click : (%d,%d)n", x1, y1);
	        circle(x,y,2);
	        line(x,y,300,y);
        	line(x,y,x,300);
    	}
    	c=getch();
	}
	return 0;
	
}
