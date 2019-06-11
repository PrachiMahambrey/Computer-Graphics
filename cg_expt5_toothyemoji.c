#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
void ellipseMid(int xc, int yc, int rx, int ry);
void main() {
	int xc, yc, rx, ry;
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setfillstyle(SOLID_FILL, YELLOW);
    cleardevice();
	ellipseMid(110, 110, 25, 25);//head
	ellipseMid(100, 105, 5, 3);//eyes
	ellipseMid(120, 105, 5, 3);
    ellipseMid(100, 105, 2, 2);
    ellipseMid(120, 105, 2, 2);
	ellipseMid(110, 120, 12, 5);//mouth
    line(100, 120, 120, 120);
    line(103, 117, 103, 123);
    line(107, 116, 107, 124);
    line(110, 115, 110, 125);
    line(113, 116, 113, 124);
    line(117, 117, 117, 123);
	floodfill(115,108,WHITE);

	getch();
	closegraph();
}
void ellipseMid(int xc, int yc, int rx, int ry) {
	int x, y, rx2, ry2, twoRy2Xk_1, twoRx2Yk_1;
	float P1, P2;
	x = 0;
	y = ry;
	rx2 = rx * rx;
	ry2 = ry * ry;
	P1 = (int)(ry2 - rx2 * ry + rx2 / 4);
	putpixel(x + xc, y + yc, WHITE);
	putpixel(x + xc, -y + yc, WHITE);
	putpixel(-x + xc, -y + yc, WHITE);
	putpixel(-x + xc, y + yc, WHITE);

	twoRy2Xk_1 = 2 * ry2*x + 2 * ry2;
	twoRx2Yk_1 = 2 * rx2*y - 2 * rx2;
	while (twoRy2Xk_1 < twoRx2Yk_1) {
		x++;
		if ((int)P1 < 0) {
			putpixel(x + xc, y + yc, WHITE);
			putpixel(x + xc, -y + yc, WHITE);
			putpixel(-x + xc, -y + yc, WHITE);
			putpixel(-x + xc, y + yc, WHITE);
			twoRy2Xk_1 = 2 * ry2*x;
			twoRx2Yk_1 = 2 * rx2*y;
			P1 = P1 + twoRy2Xk_1 + ry2;
		}
		else {
			y--;
			putpixel(x + xc, y + yc, WHITE);
			putpixel(x + xc, -y + yc, WHITE);
			putpixel(-x + xc, -y + yc, WHITE);
			putpixel(-x + xc, y + yc, WHITE);
			twoRy2Xk_1 = 2 * ry2*x;
			twoRx2Yk_1 = 2 * rx2*y;
			P1 = P1 + twoRy2Xk_1 - twoRx2Yk_1 + ry2;
		}
	}
	P2 = (int)(ry2*(x + 0.5)*(x + 0.5) + rx2 * (y - 1)*(y - 1) - rx2 * ry2);
	while (y > 0) {
		y--;
		if ((int)P2 > 0) {
			putpixel(x + xc, y + yc, WHITE);
			putpixel(x + xc, -y + yc, WHITE);
			putpixel(-x + xc, -y + yc, WHITE);
			putpixel(-x + xc, y + yc, WHITE);
			twoRy2Xk_1 = 2 * ry2*x;
			twoRx2Yk_1 = 2 * rx2*y;
			P2 = P2 - twoRx2Yk_1 + rx2;
		}
		else {
			x++;
			putpixel(x + xc, y + yc, WHITE);
			putpixel(x + xc, -y + yc, WHITE);
			putpixel(-x + xc, -y + yc, WHITE);
			putpixel(-x + xc, y + yc, WHITE);
			twoRy2Xk_1 = 2 * ry2*x;
			twoRx2Yk_1 = 2 * rx2*y;
			P2 = P2 + twoRy2Xk_1 - twoRx2Yk_1 + rx2;
		}
	}
}
