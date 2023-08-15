#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

const int INSIDE = 0; //0000
const int LEFT = 1;   //0001
const int RIGHT = 2;  //0010
const int BOTTOM = 4; //0100
const int TOP = 8;    //1000


const int xmin = 50,xmax=500,ymin=50,ymax=500;

int computeRegionCode(int x,int y){
	int code = INSIDE;
	
	if (x<xmin){
		code |= LEFT;	
	}
		
	else if(x> xmax){
		code |= RIGHT;
	}
	
	if (y < ymin){
		code |= BOTTOM;
	}
	else if(y>ymax){
		code |= TOP;
	}
	
	return code;
}
void cohenSutherlandClip(int x1,int y1,int x2,int y2){
	setcolor(RED);
	line(x1,y1,x2,y2);
	int regionCode1 = computeRegionCode(x1,y1);
	int regionCode2 = computeRegionCode(x2,y2);
	bool accept = false;
	
	while(true){
		if((regionCode1 == 0) && (regionCode2 == 0)){
			accept = true;
			break;
		}else if(regionCode1 & regionCode2){
			break;
		}else{
				int x,y;
				int regionCodeOut = regionCode1 ? regionCode1:regionCode2;
				float m=(y2-y1)/(x2-x1);
				if(regionCodeOut & TOP){
				    x = x1 + (1/m) * (ymax - y1);
	                y = ymax;
	            } else if (regionCodeOut & BOTTOM) {
	                x = x1 + (1/m) * (ymin - y1);
	                y = ymin;
	            } else if (regionCodeOut & RIGHT) {
	                y = y1 + m * (xmax - x1);
	                x = xmax;
	            } else if (regionCodeOut & LEFT) {
	                y = y1 + m * (xmin - x1) ;
	                x = xmin;
	            }
	            
            
	            if (regionCodeOut == regionCode1){
	            	x1=x;
	            	y1=y;
	            	regionCode1 = computeRegionCode(x1,y1);
				}else{
					x2=x;
					y2=y;
					regionCode2 = computeRegionCode(x2,y2);
				}
        	}
    	}
	
//	setcolor(BLUE);
	line(x1,y1,x2,y2);
	if (accept){
		cout<<"line ("<<x1<<","<<y1<<") to ("<< x2 << "," <<y2 << ") is visible."<<endl;
	}else{
		cout<<"Line is outside the clip window."<<endl;
	}
	
}


int main(int argc ,char** argv){
	initwindow(1000,1000,"Graphics in c++");
	rectangle(xmin,ymin,xmax,ymax);
	cohenSutherlandClip(25,25,600,600);
	cohenSutherlandClip(45,25,300,200);
	cohenSutherlandClip(500,500,600,600);
	cohenSutherlandClip(205,253,891,600);
	getch();
	return 0;
}