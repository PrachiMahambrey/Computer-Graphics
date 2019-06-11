#include<conio.h>
#include<graphics.h>
#include<math.h>
void bres(int, int, int, int);
int sign(int);

void main()
{
	int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	//setfillstyle(SOLID_FILL, BROWN);
	//floodfill(324, 115, WHITE);
	
	bres(261,171,302,132);
	bres(383,201,302,132);
	bres(383,201,356,224);
	bres(356,224,261,171);
	bres(413,203,483,134);
	bres(483,134,538,162);
	bres(538,162,444,223);
	bres(444,223,413,203);
	bres(440,242,538,296);
	bres(538,296,495,336);
	bres(440,242,414,267);
	bres(414,267,495,336);
	bres(260,306,314,336);
	bres(260,306,353,245);
	bres(314,336,388,264);
	bres(388,264,353,245);
	bres(351,300,325,383);
	bres(436,288,460,383);
	bres(310,383,475,383);
	bres(310,383,310,407);
	bres(475,383,475,407);
	bres(310,407,475,407);
	bres(296,407,492,407);
	bres(296,407,296,437);
	bres(492,407,492,437);
	bres(296,437,492,437);
	bres(368,383,368,335);
	bres(368,335,420,335);
	bres(420,335,420,383);
	bres(411,222,422,211);
	bres(419,245,429,252);
	bres(386,246,375,256);
	bres(378,222,368,215);
	bres(378,222,420,222);
	bres(420,222,420,244);
	bres(420,244,378,244);
	bres(378,244,378,222);
	
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
