#include<iostream>
#include<graphics.h>
#include<math.h>

int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
	float x,y,xinc,yinc;
	int x1,y1,x2,y2,stepsize,dx,dy;
	std::cout<<"Put the values of x1 and y1";
	std::cin>>x1>>y1;
	std::cout<<"put the values of x2 and y2";
	std::cin>>x2>>y2;
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	if(abs(dy)>abs(dx)){
		stepsize = abs(dy);
	}
	else{
		stepsize = abs(dx);
	}
	xinc = dx/(float)stepsize;
	yinc = dy/(float)stepsize;
	putpixel(x,y,RED);
	for(int i =0;i<stepsize;i++){
		x=x + xinc;
		y=y+yinc;
		putpixel((int)(x+0.5),(int)(y+0.5),RED);
	}
	getch();
	return 0;
}
