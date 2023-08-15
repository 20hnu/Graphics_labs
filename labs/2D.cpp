#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

	void draw(int a[][2]){
		for (int i=0;i<3;i++){
			int x1=a[i][0];
			int y1=a[i][1];
			int x2=a[(i+1)% 3][0];
			int y2 = a[(i+1)%3][1];
			
			line(x1,y1,x2,y2);
		}
	}
	void translation(int a[][2]){
		int tx=150,ty=150;
		for(int i=0;i< 3;i++){
			a[i][0] += tx;
			a[i][1] += ty;
			
		}
		draw(a);
	}
	void scaling(int a[][2]){
		int sx=2,sy=2;
		for(int i=0;i<3;i++){
			a[i][0] = a[i][0]*sx;
			a[i][1] = a[i][1]*sy;
		}
		draw(a);
	}
	
	void rotation_fixedpoint(int a[][2],int pivot_x,int pivot_y){
		int temp1,temp2;
		float angle=(3.1415/180)*80;
		for(int i=0;i<3;i++){
			temp1=a[i][0]-pivot_x;
			temp2=a[i][1] - pivot_y;
			a[i][0] = static_cast<int>(temp1*cos(angle) - temp2*sin(angle))+pivot_x;
			a[i][1] = static_cast<int>(temp1*sin(angle) + temp2*cos(angle))+pivot_y;
		}
		draw(a);
		cout<<cos(angle);
	}
	
		void rotation(int a[][2]){
		int temp1,temp2;
		float angle=(3.1415/180)*80;
		for(int i=0;i<3;i++){
			temp1=a[i][0];
			temp2=a[i][1];
			a[i][0] = static_cast<int>(temp1*cos(angle) - temp2*sin(angle));
			a[i][1] = static_cast<int>(temp1*sin(angle) + temp2*cos(angle));
		}
		draw(a);
		cout<<cos(angle);
	}
	
		void scaling_fixedpoint(int a[][2],int xf,int yf){
			int sx=2,sy=2;
			for(int i=0;i<3;i++){
				a[i][0] =xf + (a[i][0]-xf)*sx;
				a[i][1] =yf + (a[i][1]-yf)*sy;
				}
			draw(a);
		}
		void shearing(int a[][2]){
			float shx = 0.75, shy = 0.0;
		    for (int i = 0; i < 3; i++) {
		        int x = a[i][0];
		        int y = a[i][1];
		        a[i][0] = x + shx * y;
		        a[i][1] = y + shy * x;
		    }
		    draw(a);
		}
		void reflection_x(int a[][2]){
			for(int i=0;i<3;i++){
				a[i][1] = 1000-a[i][1];
				}
			draw(a);
		}
		void reflection_y(int a[][2]) {
		    for (int i = 0; i < 3; i++) {
		        a[i][0] = 1000-a[i][0];
		    }
		    draw(a);
		}

		void reflection_line(int a[][2], float m, float c) {
		    float t1 = (1 - m * m) / (1 + m * m);
		    float t2 = (2 * m) / (1 + m * m);
		    float t3 = (2 * c * m) / (1 + m * m);
		    for (int i = 0; i < 3; i++) {
		        int x = a[i][0];
		        int y = a[i][1];
		        a[i][0] = static_cast<int>(t1 * x + t2 * y - t3);
		        a[i][1] = static_cast<int>(t2 * x - t1 * y + t3);
		    }
		    draw(a);
		}




	int main(int argc, char** argv){
		initwindow(1000,1000,"Graphics using Dev-C++");
		int a[3][2] ={	//700,700,800,800,600,800 for reflection x,y
			{200,200},
			{300,300},
			{100,300},
		};
		int choice;
		draw(a);
		cout<<"Enter your choice: \n1:translation \n2:scaling about origin \n3:scaling about fixed point \n4:Rotation about origin \n5:Rotation about fixed point \n6:Reflection about x-axis \n7:Reflection about y-axis \n8:Reflection about a line \n9:Shearing\n";
		cin>>choice;
			switch(choice){
				case 1:{
					translation(a);
					break;
				}
				case 2:{
					scaling(a);
					break;
				}
				case 3:{
					scaling_fixedpoint(a,50,50);
					break;
				}
				case 4:{
					rotation(a);
					break;
				}			
				case 5:{
					rotation_fixedpoint(a,250,250);
					break;
				}
				case 6:{
					reflection_x(a);
					break;
				}
				case 7:{
					reflection_y(a);
					break;
				}
				case 8:{
					reflection_line(a,2,50);
					break;
				}
				case 9:{
					shearing(a);
					break;
				}
				default:{
					cout<<"Choose appropriate one!!";
					break;
				}
			}

		getch();
		return 0;
	}