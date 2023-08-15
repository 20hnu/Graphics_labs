#include<iostream>
#include<graphics.h>
using namespace std;

void flood_fill(int x,int y,int fill_color,int old_color){
 if(getpixel(x,y) == old_color){
 	putpixel(x,y,fill_color);
 	flood_fill(x-1,y,fill_color,old_color);
 	flood_fill(x,y-1,fill_color,old_color);
 	flood_fill(x,y+1,fill_color,old_color);
 	flood_fill(x+1,y,fill_color,old_color);
 }		
}


int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
	rectangle(100,100,300,300);
	int fill_color = RED;
	int old_color = getpixel(150,150);
	flood_fill(150,150,fill_color,old_color);
	getch();
	return 0;
}
		