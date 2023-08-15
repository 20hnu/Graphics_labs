#include<iostream>
#include<graphics.h>
#include<math.h>

int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
	int x1,y1,x2,y2,lx,ly,pk,pk1,p0,dy,dx;
	std::cout<<"Enter two end points of the line:";
	std::cin>>x1>>y1>>x2>>y2;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(x2 > x1){
		lx= 1;
	}else{
		lx= -1;
	}
	if(y2>y1){
		ly= 1;
	}else{
		ly= -1;
	}
	putpixel(x1,y1,WHITE);
	if(dx>dy){
		p0=2*dy-dx;
		for(int i=0;i<dx;i++){
			if(p0<0){
				x1=x1+1;
				pk1=pk+2*dy;
			}else{
				x1=x1+1;
				y1=y1+1;
				pk1 = pk + 2*dy - 2*dx;
			}
			putpixel(x1,y1,WHITE);
		}
	}else{
		p0=2*dx-dy;
		for(int i=0;i<dy;i++){
			if(p0<0){
				y1=y1+1;
				pk1=pk+2*dx;
			}else{
				x1=x1+1;
				y1=y1+1;
				pk1 = pk + 2*dx - 2*dy;
			}
			putpixel(x1,y1,WHITE);
		}
	}	
	getch();
	return 0;
}