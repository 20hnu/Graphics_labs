#include<iostream>
#include<graphics.h>
#include<math.h>

void drawCircle(int x,int y,int h,int k){
	putpixel(x + h,y + k,WHITE);
	putpixel(x - h, y + k, WHITE);
    putpixel(x + h, y - k, WHITE);
    putpixel(x - h, y - k, WHITE);
    putpixel(x + k, y + h, WHITE);
    putpixel(x - k, y + h, WHITE);
    putpixel(x + k, y - h, WHITE);
    putpixel(x - k, y - h, WHITE);
}
int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
	int x,y,r,x0,y0,p;	
	std::cout<<"Enter the center and radius:";
	std::cin>>x>>y>>r;
	x0=0;
	y0=r;
	p=(5/4)-r;
	while(x0<=y0){
		drawCircle(x,y,x0,y0);
		if(p<0){
			p += 2*x0 + 1;
		}else{		
			y0--;
			p += 2*x0 - 2*y0 +1;
		}
		x0++;
		delay(100);
		
			}
	getch();
	return 0;
}
