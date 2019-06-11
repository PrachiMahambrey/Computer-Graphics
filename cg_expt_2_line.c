#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
void dda(float,float,float,float);
float x,y,x1,y1,x2,y2,dx,dy,s,xi,yi,length=0;
int xc,yc;
int gd=DETECT,gm=DETECT,i;
void main(){
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the start points (x1,y1)");
	scanf("%f %f",&x1,&y1);
	printf("Enter the end points (x2,y2)");
	scanf("%f %f",&x2,&y2);
	dda(x1,y1,x2,y2);
	getch();
	closegraph();
}
 void dda
(float x1,float y1,float x2,float y2){
	x=x1,y=y1;
	putpixel(x,y,WHITE);
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		length=abs(dx);
	else
		length=abs(dy);
	xi=dx/length;
	yi=dy/length;
	printf("i\tPlot(x,y)\tx\ty\n");
	printf("  \t(%d,%d)\t\t%d\t%d\n",(int)x,(int)y,(int)x,(int)y);
	for(i=1;i<=length;i++){
		x=x+xi;
		xc=(int)x;
		if(x>=xc+0.5)
			xc+=1;

		y=y+yi;
		yc=(int)y;
		if(y>=yc+0.5)
			yc+=1;
		putpixel(x,y,WHITE);
		printf("%d\t(%d,%d)\t\t%g\t%g\n",i,xc,yc,x,y);
	}
}
