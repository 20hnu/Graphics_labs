#include<iostream>
#include <graphics.h>
using namespace std;

// Function to perform the Lian-Barsky Line Clipping Algorithm
const  int xmin=50,  ymin=50, xmax=500,ymax=500;
void lian_barsky_line_clip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int p[5] = {-dx, dx, -dy, dy};
    int q[5] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float tmin = 0.0, tmax = 1.0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return; // Line is outside the clipping window
            }
        } else {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                if (t > tmin) {
                    tmin = t;
                }
            } else {
                if (t < tmax) {
                    tmax = t;
                }
            }
        }
    }

    if (tmin < tmax) {
        int x_start = x1 + tmin * dx;
        int y_start = y1 + tmin * dy;
        int x_end = x1 + tmax * dx;
        int y_end = y1 + tmax * dy;

        // Draw the clipped line
        line(x_start, y_start, x_end, y_end);
        cout<<"The end points of the line after cliping are ("<<x_start<<","<<y_start<<") and ("<< x_end << "," <<y_end << ")";
    }
    
    
}

   int main(int argc,char** argv) {

	initwindow(1000,1000,"Graphics in C++");
	

    int x1, y1, x2, y2; // Coordinates of the line
    rectangle(xmin, ymin, xmax, ymax); // Window coordinates

    cout<<"Enter the starting point (x1, y1) of the line: ";
    cin>>x1>>y1;

	cout<<"Enter the ending point (x2, y2) of the line: ";
	cin>>x2>>y2;

    // Draw the window
    rectangle(xmin, ymin, xmax, ymax);

 
    // Clip and draw the line
    lian_barsky_line_clip(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

   delay(10000);
    closegraph();
    return 0;
}