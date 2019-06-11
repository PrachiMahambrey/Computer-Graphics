#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
void DDA(float,float,float,float);
void main()
{
int gd=DETECT,gm=DETECT;
float x1,y1,x2,y2;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

DDA(281, 101, 488, 101);
DDA(205, 196, 556, 196);
DDA(281, 101, 205, 196);
DDA(488, 101, 556, 196);
DDA(205, 196, 225, 218);
DDA(556, 196, 535, 218);
DDA(225, 218, 535, 218);
DDA(225, 218, 225, 395);
DDA(535, 218, 535, 395);
DDA(225, 395, 535, 395);
DDA(254, 395, 254, 413);
DDA(254, 413, 358, 413);
DDA(358, 413, 358, 395);
DDA(266, 395, 266, 376);
DDA(346, 395, 346, 376);
DDA(266, 376, 346, 376);
DDA(272, 376, 272, 280);
DDA(272, 280, 341, 280);
DDA(341, 280, 341, 376);
DDA(399, 277, 485, 277);
DDA(485, 277, 485, 346);
DDA(485, 346, 399, 346);
DDA(399, 346, 399, 277);
DDA(410, 333, 410, 290);
DDA(410, 290, 475, 290);
DDA(475, 290, 475, 333);
DDA(475, 333, 410, 333);
DDA(441, 334, 441, 290);
DDA(410, 312, 475, 312);
DDA(345, 176, 398, 176);
DDA(345, 176, 345, 148);
DDA(398, 176, 398, 148);
DDA(320, 172, 312, 166);
DDA(425, 176, 434, 166);
DDA(320, 172, 372, 122);
DDA(425, 176, 372, 122);
DDA(312, 166, 372, 106);
DDA(372, 106, 434, 166);

getch();
closegraph();
}

void DDA(float x1,float y1,float x2, float y2){
float x,y,length,xi,yi,dx,dy;//x1,y1,x2,y2;
int i;
x=x1; y=y1;
putpixel(x,y,WHITE);
dx=x2-x1; dy=y2-y1;
if(fabs(dx)>=fabs(dy)){
length=fabs(dx);
}
else{
length=fabs(dy);
}
xi=dx/length;
yi=dy/length;
for(i=1;i<=length;i++)
{
x=x+xi;
y=y+yi;
putpixel(x,y,WHITE);
}
}
