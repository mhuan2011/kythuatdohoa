#include <iostream>
#include <graphics.h>
#include <string>
#include "xuli.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reset_color();
void draw_xOy();
void draw_triangle_direction(int x1, int y1, int x2, int y2, int x3, int y3);
void put_pixel(int x, int y);
void put_pixel_grid(int x, int y);
void put_pixel_screen(int x, int y);
bool is_in_range(int x, int y);
bool is_in_range_get_position_x(int x, int y);
bool is_in_range_get_position_y(int x, int y);
bool is_in_range_get_coords_button(int x,int y);
bool is_in_range_clear(int x,int y);
void execute();
void enter_coords_x();
void enter_coords_y();
void first_screen();
void draw_all_button();
void draw_line(int x1,int y1,int x2,int y2);
void draw_net_dut(int x1,int y1,int x2,int y2);
void draw_net_cham_gach(int x1,int y1,int x2,int y2);
void draw_net_hai_cham_gach(int x1,int y1,int x2,int y2);
void draw_mui_ten(int x1,int y1,int x2,int y2);
void draw_rectangle(int x1,int y1,int x2,int y2);

const int max = 101;
const int x_offset = 50;
const int y_offset = 30;
int x_text=0;
int y_text=0;
int x_coord = 0;
int y_coord = 0;
int x1,y1,x2,y2;
int draw = 0;

int mode=0;

int main(int argc, char** argv) {
	// now, you can run project
    initwindow(800, 600);           // init window graphics
    first_screen();
 	execute();
 	
    while(!kbhit()) delay(1);       // pause screen
    return 0;
}

void first_screen(){
	reset_color();                 // set background
    cleardevice();               // set text color
 	draw_xOy();
 	
 	outtextxy(600,100,"Nhap toa do:");
 	outtextxy(700,100,"X: ");
 	outtextxy(700,120,"Y: ");
 	rectangle(700,100,750,120);
 	rectangle(700,120,750,140);
 	
 	setcolor(RED);
	setfillstyle(SOLID_FILL, BLUE);
	rectangle(700,150,750,165);
	floodfill(725,160,RED);
	outtextxy(715,152,"Put");										
	reset_color();
	
	draw_all_button();
}

void draw_all_button(){
	setcolor(RED);
 	setfillstyle(SOLID_FILL, YELLOW);
 	rectangle(600,170,750,210);
 	floodfill(700,180,RED);
 	outtextxy(605,175,"NET DUT");
 	
 	rectangle(600,210,750,240);
 	floodfill(700,220,RED);
 	outtextxy(605,215,"NET CHAM GACH");
 	
 	rectangle(600,240,750,280);
 	floodfill(700,260,RED);
 	outtextxy(605,245,"NET HAI CHAM GACH");
 	
 	rectangle(600,280,750,320);
 	floodfill(700,300,RED);
 	outtextxy(605,285,"MUI TEN");
 	
 	rectangle(600,320,750,360);
 	floodfill(700,340,RED);
 	outtextxy(605,325,"HINH CHU NHAT");
 	reset_color();
 	
 	setfillstyle(SOLID_FILL, CYAN);
 	rectangle(600,370,750,400);
	floodfill(700,380,BLACK);
 	outtextxy(605,375,"CLEAR");
 	reset_color();
}

void draw_xOy(){
	//draw grid pixel			
	for(int x = 0;x<max;x++){
		for(int y = 0;y<max;y++){
			put_pixel_grid(x,y);
		}
	}
	//draw axis
	//x axis
	setcolor(1);
	line(x_offset-10, 5*max/2+ y_offset, x_offset+max*5+10, 5*max/2+ y_offset);
	line(5*max/2+ x_offset, y_offset-10, 5*max/2+x_offset, y_offset+max*5+10);
	draw_triangle_direction(x_offset-25,5*max/2+ y_offset,
							x_offset-10,5*max/2+ y_offset-15,
							x_offset-10,5*max/2+ y_offset+15);
	draw_triangle_direction(x_offset+max*5+25, 5*max/2+ y_offset,
							x_offset+max*5+10, 5*max/2+ y_offset-15,
							x_offset+max*5+10, 5*max/2+ y_offset+15);
	//ve bi ho nen putpixel vo de kin hinh tam giac de ma to
	putpixel(5*max/2+ x_offset, y_offset-25,BLUE);
	putpixel(5*max/2+x_offset, y_offset+max*5+25,BLUE);
	draw_triangle_direction(5*max/2+ x_offset-15, y_offset-10,
							5*max/2+ x_offset+15, y_offset-10,
							5*max/2+ x_offset, y_offset-25);
	draw_triangle_direction(5*max/2+x_offset-15, y_offset+max*5+10,
							5*max/2+x_offset+15, y_offset+max*5+10,
							5*max/2+x_offset, y_offset+max*5+25);
	reset_color();
	outtextxy(x_offset+max*5+10, 5*max/2+ y_offset+20,"X");
	outtextxy(5*max/2+ x_offset + 20, y_offset-10,"Y");
	outtextxy(5*max/2+ x_offset + 15, 5*max/2+ y_offset + 5, "O");
}

void put_pixel_screen(int x, int y){
	x=(x-x_offset)/5*5;
	y=(y-y_offset)/5*5;
	setcolor(RED);
	setfillstyle(SOLID_FILL, YELLOW);
	rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
	floodfill(x+2+x_offset,y+2+y_offset,RED);													
	reset_color();
}

void put_pixel_grid(int x, int y){
	int pos_x = x*5;
	int pos_y = y*5;
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, YELLOW);
	rectangle(pos_x+1+x_offset,pos_y+1+y_offset,pos_x+4+x_offset,pos_y+4+y_offset);
	floodfill(pos_x+2+x_offset,pos_y+2+y_offset,CYAN);													
	reset_color();
}

void put_pixel(int x, int y){
	put_pixel_screen(x*5+x_offset+max/2*5, -y*5+y_offset+max/2*5);
}

void reset_color(){
	setcolor(0);
	setbkcolor(15);
}

void draw_triangle_direction(int x1, int y1, int x2, int y2, int x3, int y3){
	setcolor(1);
	setfillstyle(SOLID_FILL, BLUE);
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	floodfill(((x1+x3)/2+x2)/2, ((y1+y3)/2+y2)/2, BLUE);
	reset_color();
}

bool is_in_range(int x, int y){
	return (x>x_offset && x<5*max+x_offset)&&(y > y_offset && y<5*max+y_offset)?true:false;
}

bool is_in_range_get_position_x(int x, int y){
	return (x>700&&x<750)&&(y>100&&y<120)?true:false;
}

bool is_in_range_get_position_y(int x, int y){
	return (x>700&&x<750)&&(y>120&&y<140)?true:false;
}


bool is_in_range_get_coords_button(int x,int y){
	return (x>700&&x<750)&&(y>150&&y<165)?true:false;
}

bool is_in_range_net_dut(int x,int y){
	return (x>600&&x<750)&&(y>170&&y<210)?true:false;
}

bool is_in_range_net_cham_gach(int x,int y){
	return (x>600&&x<750)&&(y>210&&y<240)?true:false;
}

bool is_in_range_get_hai_cham_gach(int x,int y){
	return (x>600&&x<750)&&(y>240&&y<280)?true:false;
}

bool is_in_range_mui_ten(int x,int y){
	return (x>600&&x<750)&&(y>280&&y<320)?true:false;
}

bool is_in_range_hinh_chu_nhat(int x,int y){
	return (x>600&&x<750)&&(y>320&&y<360)?true:false;
}

bool is_in_range_clear(int x,int y){
	return (x>600&&x<750)&&(y>370&&y<400)?true:false;
}

void execute(){
	while(true){
 		delay(0.0001);
 		if(ismouseclick(WM_LBUTTONDOWN)){
 			int x,y;
 			getmouseclick(WM_LBUTTONDOWN,x,y);
 			//put pixel bang click chuot
 			if(is_in_range(x,y)){
				put_pixel_screen(x,y);
				x1 = x2;
				y1 = y2;
				x2 = (x-x_offset)/5-max/2;
				y2 = -((y-y_offset)/5-max/2);
				draw++;
				if(draw == 2){
					switch(mode){
						case 0:draw_line(x1,y1,x2,y2);
						break;
						case 1:draw_net_dut(x1,y1,x2,y2);
						break;
						case 2:draw_net_cham_gach(x1,y1,x2,y2);
						break;
						case 3:draw_net_hai_cham_gach(x1,y1,x2,y2);
						break;
						case 4:draw_mui_ten(x1,y1,x2,y2);
						break;
						case 5:draw_rectangle(x1,y1,x2,y2);
						break;
					}
					draw = 0;
				}
			}
			//click vao vung nhap toa do x
			if(is_in_range_get_position_x(x,y)){
				moveto(715,102);
				enter_coords_x();
			}
			//click vao vung nhap toa do y
			if(is_in_range_get_position_y(x,y)){
				moveto(715,122);
				enter_coords_y();
			}
			if(is_in_range_get_coords_button(x,y)){
				put_pixel(x_coord,y_coord);
			}
			//click vao o putpixel
			if(is_in_range_net_dut(x,y)){
				draw_all_button();
				setcolor(BLUE);
			 	setfillstyle(SOLID_FILL, MAGENTA);
			 	rectangle(600,170,750,210);
			 	floodfill(700,190,BLUE);
			 	outtextxy(605,175,"NET DUT");
			 	reset_color();
			 	mode=1;
			}
			if(is_in_range_net_cham_gach(x,y)){
				draw_all_button();
				setcolor(BLUE);
				rectangle(600,210,750,240);
				setfillstyle(SOLID_FILL, MAGENTA);
			 	floodfill(700,220,BLUE);
			 	outtextxy(605,215,"NET CHAM GACH");
			 	reset_color();
			 	mode=2;
			}
			if(is_in_range_get_hai_cham_gach(x,y)){
				draw_all_button();
				setcolor(BLUE);
				rectangle(600,240,750,280);
				setfillstyle(SOLID_FILL, MAGENTA);
			 	floodfill(700,260,BLUE);
			 	outtextxy(605,245,"NET HAI CHAM GACH");
			 	reset_color();
			 	mode=3;
			}
			if(is_in_range_mui_ten(x,y)){
				draw_all_button();
				setcolor(BLUE);
				rectangle(600,280,750,320);
				setfillstyle(SOLID_FILL, MAGENTA);
			 	floodfill(700,290,BLUE);
			 	outtextxy(605,285,"MUI TEN");
			 	reset_color();
			 	mode=4;
			}
			if(is_in_range_hinh_chu_nhat(x,y)){
				draw_all_button();
				setcolor(BLUE);
				rectangle(600,320,750,360);
				setfillstyle(SOLID_FILL, MAGENTA);
			 	floodfill(700,330,BLUE);
			 	outtextxy(605,325,"HINH CHU NHAT");
			 	reset_color();
			 	mode=5;
			}
			if(is_in_range_clear(x,y)){
				first_screen();
			}
		}
	}
}

void enter_coords_x(){
	x_coord=process_coord();
}

void enter_coords_y(){
	y_coord=process_coord();
}

void draw_line(int x1,int y1,int x2,int y2){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;

	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
			if(p < 0) {
				p = p + 2*dy;
			} else {
				p = p + 2*dy - 2*dx;
				if(y <= y2) {
					y++;
				} else {
					y--;
				}
			}
			x--;
			put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
			if(p < 0) {
				p = p + 2*dy;
				y =y ;
			} else {
				p = p + 2*dy - 2*dx;
				if(y >= y2) {
					y--;
				} else {
					y++;
				}
			}
			x++;
			put_pixel(x, y);
			}
		}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x <= x2) {
					x++;
				} else {
					x--;
				}
			}
			y--;
			put_pixel(x, y);
			}
		} else if( y < y2) {
				while(y < y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x >= x2) {
					x--;
				} else {
					x++;
				}
			}
			y++;
			put_pixel(x, y);
			}
		}
	}
}

void draw_net_dut(int x1,int y1,int x2,int y2){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;

	int dem = 1;
	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
			if(p < 0) {
				p = p + 2*dy;
			} else {
				p = p + 2*dy - 2*dx;
				if(y <= y2) {
					y++;
				} else {
					y--;
				}
			}
			x--;
			dem++;
			if(dem %12 !=0&&dem%12!=11)put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
			if(p < 0) {
				p = p + 2*dy;
				y =y ;
			} else {
				p = p + 2*dy - 2*dx;
				if(y >= y2) {
					y--;
				} else {
					y++;
				}
			}
			x++;
			dem++;
			if(dem %12 !=0&&dem%12!=11)put_pixel(x, y);
			}
		}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x <= x2) {
					x++;
				} else {
					x--;
				}
			}
			y--;
			dem++;
			if(dem %12 !=0&&dem%12!=11)
				put_pixel(x, y);
			}
		} else if( y < y2) {
			while(y < y2) {
				if(p < 0) {
					p = p + 2*dx;
				} else {
					p = p + 2*dx - 2*dy;
					if(x >= x2) {
						x--;
					} else {
						x++;
					}
				}
				y++;
				dem++;
				if(dem %12 !=0&&dem%12!=11)
					put_pixel(x, y);
			}
		}
	}
}
void draw_net_cham_gach(int x1,int y1,int x2,int y2){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;

	int dem = 1;
	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
			if(p < 0) {
				p = p + 2*dy;
			} else {
				p = p + 2*dy - 2*dx;
				if(y <= y2) {
					y++;
				} else {
					y--;
				}
			}
			x--;
			dem++;
			if(dem %12 !=0&&dem%12!=10)put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
			if(p < 0) {
				p = p + 2*dy;
				y =y ;
			} else {
				p = p + 2*dy - 2*dx;
				if(y >= y2) {
					y--;
				} else {
					y++;
				}
			}
			x++;
			dem++;
			if(dem %12 !=0&&dem%12!=10)put_pixel(x, y);
			}
		}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x <= x2) {
					x++;
				} else {
					x--;
				}
			}
			y--;
			dem++;
			if(dem %12 !=0&&dem%12!=10)
				put_pixel(x, y);
			}
		} else if( y < y2) {
			while(y < y2) {
				if(p < 0) {
					p = p + 2*dx;
				} else {
					p = p + 2*dx - 2*dy;
					if(x >= x2) {
						x--;
					} else {
						x++;
					}
				}
				y++;
				dem++;
				if(dem %12 !=0&&dem%12!=10)
					put_pixel(x, y);
			}
		}
	}
}
void draw_net_hai_cham_gach(int x1,int y1,int x2,int y2){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;

	int dem = 1;
	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
			if(p < 0) {
				p = p + 2*dy;
			} else {
				p = p + 2*dy - 2*dx;
				if(y <= y2) {
					y++;
				} else {
					y--;
				}
			}
			x--;
			dem++;
			if(dem %12 !=0&&dem%12!=10&&dem%12!=8)put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
			if(p < 0) {
				p = p + 2*dy;
				y =y ;
			} else {
				p = p + 2*dy - 2*dx;
				if(y >= y2) {
					y--;
				} else {
					y++;
				}
			}
			x++;
			dem++;
			if(dem %12 !=0&&dem%12!=10&&dem%12!=8)put_pixel(x, y);
			}
		}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x <= x2) {
					x++;
				} else {
					x--;
				}
			}
			y--;
			dem++;
			if(dem %12 !=0&&dem%12!=10&&dem%12!=8)
				put_pixel(x, y);
			}
		} else if( y < y2) {
			while(y < y2) {
				if(p < 0) {
					p = p + 2*dx;
				} else {
					p = p + 2*dx - 2*dy;
					if(x >= x2) {
						x--;
					} else {
						x++;
					}
				}
				y++;
				dem++;
				if(dem %12 !=0&&dem%12!=10&&dem%12!=8)
					put_pixel(x, y);
			}
		}
	}
}
void draw_mui_ten(int x1,int y1,int x2,int y2){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;
	int x_last,y_last;
	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
				if(p < 0) {
					p = p + 2*dy;
				} else {
					p = p + 2*dy - 2*dx;
					if(y <= y2) {
						y++;
					} else {
						y--;
					}
				}
				if((x-x2)==3){
					x_last=x;
					y_last=y;
				}
				x--;
				put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
					if(p < 0) {
						p = p + 2*dy;
						y =y ;
					} else {
						p = p + 2*dy - 2*dx;
						if(y >= y2) {
							y--;
						} else {
							y++;
						}
					}
					x++;
					if((x2-x)==3){
						x_last=x;
						y_last=y;
					}
					put_pixel(x, y);
				}
			}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
				if(p < 0) {
					p = p + 2*dx;
				} else {
					p = p + 2*dx - 2*dy;
					if(x <= x2) {
						x++;
					} else {
						x--;
					}
				}
				y--;
				if((y-y2)==3){
					x_last=x;
					y_last=y;
				}
				put_pixel(x, y);
			}
		} else if( y < y2) {
			while(y < y2) {
				if(p < 0) {
					p = p + 2*dx;
				} else {
					p = p + 2*dx - 2*dy;
					if(x >= x2) {
						x--;
					} else {
						x++;
					}
				}
				y++;
				if((y2-y)==3){
					x_last=x;
					y_last=y;
				}
				put_pixel(x, y);
			}
		}
	};
}
void draw_rectangle(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x1,y2);
	draw_line(x1,y1,x2,y1);
	draw_line(x2,y2,x1,y2);
	draw_line(x2,y2,x2,y1);
}






