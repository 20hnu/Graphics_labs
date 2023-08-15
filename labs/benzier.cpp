#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


int x[4]={420,220,220,420};
int y[4]={185,155,225,195};
int num = 4;


int factorial(int n) {
      if(n == 0 || n==1){return 1;}
      else{
      	return n*factorial(n-1);
	  }
}
 
float nCk(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

float B_value(float k,float u){
	float value = nCk(num-1,k)* pow(u,k)* pow(1-u,num-1-k);
	return value;	
}

void curve_points(){
float u=0,sum_x,sum_y,temp_x,temp_y;
	while(u<=1){
		sum_x = 0;
		sum_y=0;
		for (int i=0;i<num;i++){
			temp_x = x[i]*B_value((float)i,u);
			sum_x += temp_x;
			temp_y = y[i]*B_value((float)i,u);
			sum_y += temp_y;	
		}
		putpixel((int)sum_x,(int)sum_y,RED);
		u+=0.0001;
	}
}


int main(int argc,char **argv){
	initwindow(1000,1000,"Graphics in C++");
	line(x[0],y[0],x[1],y[1]);
	line(x[1],y[1],x[2],y[2]);
	line(x[2],y[2],x[3],y[3]);
	curve_points();
	getch();
	return 0;
}
