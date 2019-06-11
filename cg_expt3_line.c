#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void bres();
int sign(int);
void main()
{
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	bres();
	getch();
	closegraph();
}
void bres()
{
	int x, y, x1, y1, dx, dy, x2, y2, t, interchange, i, e, s1, s2;
	printf("\n\n\n\n\nEnter the start point: \n");
	scanf("%d%d", &x1, &y1);
	printf("Enter the end point: \n");
	scanf("%d%d", &x2, &y2);
	x = x1;
	y = y1;
	dx = abs(x2 - x1); dy = abs(y2 - y1);
	s1 = sign(x2 - x1); s2 = sign(y2 - y1);
	if (dy > dx)
	{
		t = dx; dx = dy; dy = t; interchange = 1;
	}
	else
	{
		interchange = 0;
	}
	e = 2 * dy - dx;
	printf("k\t\t(x,y)\t\tpk\n");
	for (i = 1; i <= dx; i++)
	{
		printf("%d\t\t%d,%d\t\t%d\n", i, x, y, e);
		putpixel(x, y, WHITE);
		while (e >= 0)
		{
			if (interchange == 1) {
				x = x + s1;
			}
			else {
				y = y + s2;
			}
			e = e - 2 * dx;
		}
		if (interchange == 1)
		{
			y = y + s2;
		}
		else {
			x = x + s1;
		}
		e = e + 2 * dy;
	}
}
int sign(int xp)
{
	if (xp > 0) return 1;
	if (xp < 0) return -1;
	return 0;
}
