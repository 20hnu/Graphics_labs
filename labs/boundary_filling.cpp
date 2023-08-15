#include<iostream>
#include<graphics.h>
using namespace std;

void Boundary_fill4(int x,int y,int b_color,int fill_color){
	int value = getpixel(x,y);
	if(value != b_color && value != fill_color ){
		putpixel(x,y,fill_color);
		Boundary_fill4(x-1,y,b_color,fill_color);
		Boundary_fill4(x+1,y,b_color,fill_color);
		Boundary_fill4(x,y-1,b_color,fill_color);
		Boundary_fill4(x,y+1,b_color,fill_color);	
	}	
	
}

void Boundary_fill8(int x,int y,int b_color,int fill_color){
	int value = getpixel(x,y);
	if(value != b_color && value != fill_color ){
		putpixel(x,y,fill_color);
		Boundary_fill8(x+1,y,b_color,fill_color);
		Boundary_fill8(x-1,y,b_color,fill_color);
		Boundary_fill8(x,y+1,b_color,fill_color);
		Boundary_fill8(x,y-1,b_color,fill_color);
		Boundary_fill8(x+1,y+1,b_color,fill_color);
		Boundary_fill8(x-1,y-1,b_color,fill_color);
		Boundary_fill8(x+1,y-1,b_color,fill_color);
		Boundary_fill8(x-1,y+1,b_color,fill_color);	
	}	
	
}
int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
	int choice;
	cout<<"Choose 4 for 4-connected Boundary filling and 8 for 8_connected:";
	cin>>choice;
	rectangle(100,100,300,300);
	switch(choice){
		case 4:{
			int b_color = WHITE;
			int f_color = RED;
			Boundary_fill4(150,150,b_color,f_color);
			break;
		}
		case 8:{
			int b_color = WHITE;
			int f_color = RED;
			Boundary_fill8(150,150,b_color,f_color);
			break;
		}
		default:{
			cout<<"Choose apprioprate option.";
			break;
		}
	}
	getch();
	return 0;
}
		