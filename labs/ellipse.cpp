#include<iostream>
#include<graphics.h>
#include<math.h>


void drawEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;

    // Initial decision parameter of region 1
    int p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        drawEllipse(xc, yc, x, y);
		delay(100);
        x++;
        dx += 2 * ry * ry;
        p1 += dx + ry * ry;

        if (p1 >= 0)
        {
            y--;
            dy -= 2 * rx * rx;
            p1 -= dy;
        }
    }

    // Decision parameter of region 2
    int p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        drawEllipse(xc, yc, x, y);
		delay(100);
        y--;
        dy -= 2 * rx * rx;
        p2 -= dy + rx * rx;

        if (p2 <= 0)
        {
            x++;
            dx += 2 * ry * ry;
            p2 += dx;
        }
    }
}

int main(int argc, char** argv){
	initwindow(1000,1000,"Graphics using Dev-C++");
    int xc = 320; // X-coordinate of the center
    int yc = 240; // Y-coordinate of the center
    int rx = 150; // X-axis radius
    int ry = 100; // Y-axis radius
    
    midpointEllipse(xc,yc,rx,ry);
	getch();
	return 0;
}
