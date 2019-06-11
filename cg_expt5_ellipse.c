#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void ellipse1();
void main()
{
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	ellipse1();
	getche();
	closegraph();
}
void ellipse1()
{
	int rx, ry, xc, yc, x0, y0, p1k, p20, px, py, px2, py2;
	printf("\n\n\nEnter the x radius: ");
	scanf("%d", &rx);
	printf("\n");
	printf("Enter the y radius: ");
	scanf("%d", &ry);
	printf("\n");
	printf("Enter the center point: \n");
	scanf("%d%d", &xc, &yc);
	x0 = 0;
	y0 = ry;
	py = (2 * ry*ry*x0); px = (2 * rx*rx*y0);
printf("Region 1\n");
	printf("\tPk\tPlot\t\t2ry2xk+1\t2rx2yk+1\n");
	putpixel(x0 + xc, y0 + yc, WHITE);
	putpixel(x0 + xc, -y0 + yc, WHITE);
	putpixel(-x0 + xc, -y0 + yc, WHITE);
	putpixel(-x0 + xc, y0 + yc, WHITE);
	printf("\t\t(%d,%d)\n", x0, y0);
	p1k = (ry*ry) - (rx*rx*ry) + (rx*rx / 4);
	while (py < px)
	{
		if (p1k < 0)
		{
			x0 = x0 + 1;
			putpixel(x0 + xc, y0 + yc, WHITE);
			putpixel(x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, y0 + yc, WHITE);

			py = (2 * ry*ry*x0); px = (2 * rx*rx*y0);
			printf("\t%d\t(%d,%d)\t\t%d\t\t%d\n", p1k, x0, y0, py, px);
			p1k = p1k + (2 * ry*ry*x0) + (ry*ry);
		}
		else
		{
			x0 = x0 + 1; y0 = y0 - 1;
			putpixel(x0 + xc, y0 + yc, WHITE);
			putpixel(x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, y0 + yc, WHITE);
			py = (2 * ry*ry*x0); px = (2 * rx*rx*y0);
			printf("\t%d\t(%d,%d)\t\t%d\t\t%d\n", p1k, x0, y0, py, px);
			p1k = p1k + (2 * ry*ry*x0) - (2 * rx*rx*y0) + (ry*ry);
		}
	}
	p20 = (ry*ry)*(x0 + 0.5)*(x0 + 0.5) + (rx*rx)*(y0 - 1)*(y0 - 1) - (rx*rx*ry*ry);
	printf("Region 2\n");
	printf("\tPk\tPlot\t\t2ry2xk+1\t2rx2yk+1\n");
	printf("\t\t(%d,%d)\n", x0, y0);
	while (y0 > 0)
	{
		if (p20 > 0)
		{
			y0 = y0 - 1;
			putpixel(x0 + xc, y0 + yc, WHITE);
			putpixel(x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, y0 + yc, WHITE);
			py2 = (2 * ry*ry*x0); px2 = (2 * rx*rx*y0);
			printf("\t%d\t(%d,%d)\t\t%d\t\t%d\n", p20, x0, y0, py2, px2);
			p20 = p20 - (2 * rx*rx*y0) + (rx*rx);
		}
		else {
			x0 = x0 + 1; y0 = y0 - 1;
			putpixel(x0 + xc, y0 + yc, WHITE);
			putpixel(x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, -y0 + yc, WHITE);
			putpixel(-x0 + xc, y0 + yc, WHITE);
			py2 = (2 * ry*ry*x0); px2 = (2 * rx*rx*y0);
			printf("\t%d\t(%d,%d)\t\t%d\t\t%d\n", p20, x0, y0, py2, px2);
			p20 = p20 + (2 * ry*ry*x0) - (2 * rx*rx*y0) + (rx*rx);
		}


	}

}

