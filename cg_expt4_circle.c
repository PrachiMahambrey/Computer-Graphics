#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void circle1();
void circleplotpoints(int,int,int,int);
void main()
{
int gd=DETECT,gm=DETECT;
initgraph(&gd,&gm,"C:\\TC\\BGI");
circle1();
getch();
closegraph();
}
void circle1()
{
int xcenter,ycenter,r,p,x,y,k=0;

printf("\n\n\n\n\nEnter the center point\n");
scanf("%d%d",&xcenter,&ycenter);
printf("Enter the radius\n");
scanf("%d",&r);
x=0; y=r;
p=1-r;
//void circleplotpoints(int,int,int,int);
circleplotpoints(xcenter,ycenter,x,y);
printf("k\tpk\t(x,y)\t2xk+1\t2yk+1\t(x+xc,y+yc)\n");
printf("\t\t%d,%d\t\t\t%d,%d\n",x,y,x+xcenter,y+ycenter);
while(x<y)
{
printf("%d\t%d\t",k,p);
k++;
x++;
if(p<0)
p+=2*x+1;
else
{
y--;
p+=2*(x-y)+1;
}
circleplotpoints(xcenter,ycenter,x,y);

printf("%d,%d\t\%d\t%d\t%d,%d\n",x,y,2*x,2*y,x+xcenter,y+ycenter);
}
}
void circleplotpoints(int xcenter,int ycenter,int x,int y)
{
putpixel(xcenter+x,ycenter+y,WHITE);
putpixel(xcenter-x,ycenter+y,WHITE);
putpixel(xcenter+x,ycenter-y,WHITE);
putpixel(xcenter-x,ycenter-y,WHITE);
putpixel(xcenter+y,ycenter+x,WHITE);
putpixel(xcenter-y,ycenter+x,WHITE);
putpixel(xcenter+y,ycenter-x,WHITE);
putpixel(xcenter-y,ycenter-x,WHITE);
}
