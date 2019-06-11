#include<conio.h>
#include<graphics.h>
#include<math.h>
void circle1(int, int, int);
void circleplotpoints(int, int, int, int);
void main()
{
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setfillstyle(SOLID_FILL, YELLOW);

	circle1(269, 210, 12);
	circle1(312, 238, 100);
	circle1(352, 210, 12);
	circle1(310, 270, 30);
	floodfill(270, 240, WHITE);

	getch();
	closegraph();
}
void circle1(xcenter, ycenter, r)
{
	int p, x, y, k = 0;
	x = 0; y = r;
	p = 1 - r;
	circleplotpoints(xcenter, ycenter, x, y);
	while (x < y)
	{
		k++;
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else
		{
			y--;
			p += 2 * (x - y) + 1;
		}
		circleplotpoints(xcenter, ycenter, x, y);
	}
}
void circleplotpoints(int xcenter, int ycenter, int x, int y)
{
	putpixel(xcenter + x, ycenter + y, WHITE);
	putpixel(xcenter - x, ycenter + y, WHITE);
	putpixel(xcenter + x, ycenter - y, WHITE);
	putpixel(xcenter - x, ycenter - y, WHITE);
	putpixel(xcenter + y, ycenter + x, WHITE);
	putpixel(xcenter - y, ycenter + x, WHITE);
	putpixel(xcenter + y, ycenter - x, WHITE);
	putpixel(xcenter - y, ycenter - x, WHITE);
}
