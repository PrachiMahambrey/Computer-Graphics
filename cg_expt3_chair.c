#include<conio.h>
#include<graphics.h>
#include<math.h>
void bres(int, int, int, int);
int sign(int);
void main()
{
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	bres(114,25,292,25);
	bres(114,118,292,118);
	bres(114,25,114,118);
	bres(292,25,292,118);
	bres(120,118,120,203);
	bres(145,118,145,203);
	bres(260,118,260,203);
	bres(286,118,286,203);
	bres(120,203,286,203);
	bres(58,258,224,258);
	bres(120,203,58,258);
	bres(286,203,224,258);
	bres(58,258,58,426);
	bres(58,426,85,426);
	bres(85,426,85,258);
	bres(194,426,194,258);
	bres(194,426,224,426);
	bres(224,426,224,258);
	bres(258,370,286,370);
	bres(286,370,286,203);
	bres(258,370,258,227);
	bres(122,370,150,370);
	bres(122,370,122,258);
	bres(150,370,150,258);

	getch();
	closegraph();
}
void bres(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, t, interchange, s1, s2, e, i;
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
	for (i = 0; i < dx; i++)
	{
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
