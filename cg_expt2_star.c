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
initgraph(&gd,&gm,"C:\\TC\\BGI");

DDA(300,275,400,425);
DDA(300,275,200,425);
DDA(200,425,400,425);
DDA(300,475,200,325);
DDA(300,475,400,325);
DDA(200,325,400,325)

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
