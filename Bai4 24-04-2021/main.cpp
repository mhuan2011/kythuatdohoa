#include<iostream>
#include<winbgim.h>
#include<math.h>
#include<conio.h>
using namespace std;
int color=15;
void Elipse(int x_center,int y_center,int a,int b,int color)// ve elipse
{
    float p,a2,b2;
    int x,y;
    a2=pow(a,2);
    b2=pow(b,2);
    x=0;
    y=b;
     
    p=2*((float)b2/a2)-(2*b)+1;
     
    int dem = 0;
    //ve nhanh thu 1(tu tren xuong )
    while(((float)b2/a2)*x<=y)
    {
		//put pixel
		if(dem == 3){
			dem = 0;
		}
		else{
			
    		putpixel(y_center+x,y_center-y,color);
    		putpixel(y_center-x,y_center-y,color);
    		dem++;
		}
		putpixel(y_center+x,y_center+y,color);
    	putpixel(y_center-x,y_center+y,color);
    	
    	//thuat toan ve
        if(p<0)
        {
            p=p+2*((float)b2/a2)*(2*x+3);
            
        }
        else{
            p= p- 4*y + 2*((float)b2/a2)*(2*x+3);
            y--;
        }
        x++;
    }
    //ve nhanh thu 2(tu duoi len )
    y=0;
    x=a;
    p=2*((float)a2/b2)-2*a+1;
    int dem2 = 0;
    while(((float)a2/b2)*y<=x)
    {
    	//put pixel
    	if(dem == 3){
			dem = 0;
		}
		else{
			
    		putpixel(y_center+x,y_center-y,color);
    		putpixel(y_center-x,y_center-y,color);
    		dem++;
		}
		putpixel(y_center+x,y_center+y,color);
    	putpixel(y_center-x,y_center+y,color);
        
        //thuat toan ve
        if(p<0)
        {
            p=p +2*((float)a2/b2)*(2*y+3);
        }
        else
        {
            p=p- 4*x + 2*((float)a2/b2)*(2*y+3);
            x=x-1;
        }
        y=y+1;
    }
}
int main()
{
    int rLon, rBe;
    //nen nhap ban kinh lon la 100
    //ban kinh nho la 50 de nhin` cho dep
    cout << "Nhap ban kinh lon: "; cin >> rLon;
    cout << "\nNhap ban kinh nho: "; cin >> rBe;
    
    int gd,gm=VGAMAX; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    Elipse(250,250,rLon,rBe,color);
    getch();
    return 0;
}
