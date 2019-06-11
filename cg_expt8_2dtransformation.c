#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int x1,x2,x3,y1,y2,y3;

void translate(int tx, int ty);
void scale(int sx, int sy);
void rotate();
void reflect();
void shear(int c,int value);

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}

void main()
{
	int choice;
	int tx,ty,sx,sy,c,value;
	char str1[20],str2[20],str3[20];
            
	int gd=DETECT,gm=DETECT,i,j;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
            
	setcolor(4);
	x1=200;y1=100;x2=250;y2=150;x3=200;y3=150;	
  setcolor(15);
	do{
	  printf("\n\t::MENU::\n 1. Translate\n 2. Scale\n 3. Rotate\n 4. Reflect\n 5. Shear\n 0. Quit\nEnter your choice: ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	    case 1:
				drawTriangle(x1,y1,x2,y2,x3,y3);
				sprintf(str1,"A(%d,%d)",x1,y1);
				sprintf(str2,"B(%d,%d)",x2,y2);
				sprintf(str3,"C(%d,%d)",x3,y3);
				outtextxy(400,10,"Before Translation :");
				outtextxy(400,20,str1);
				outtextxy(400,30,str2);
				outtextxy(400,40,str3);
				printf("\n\nEnter the translation factors tx and ty :\n");
				scanf("%d%d",&tx,&ty);
				translate(tx,ty);
				break;
	    case 2:
				setcolor(15);
drawTriangle(x1,y1,x2,y2,x3,y3);
				sprintf(str1,"A(%d,%d)",x1,y1);
				sprintf(str2,"B(%d,%d)",x2,y2);
				sprintf(str3,"C(%d,%d)",x3,y3);
				outtextxy(400,10,"Before Scaling :");
				outtextxy(400,20,str1);
				outtextxy(400,30,str2);
				outtextxy(400,40,str3);
				printf("\n\nEnter the scaling factors sx and sy :\n");
				scanf("%d%d",&sx,&sy);
				scale(sx,sy);
				break;	
	
	    case 3:
				rotate();
				break;    
			
			case 4:
				reflect();
				break;    
			
			case 5:
				drawTriangle(x1,y1,x2,y2,x3,y3);
				sprintf(str1,"A(%d,%d)",x1,y1);
				sprintf(str2,"B(%d,%d)",x2,y2);
				sprintf(str3,"C(%d,%d)",x3,y3);
				outtextxy(400,10,"Before Shear Transformation :");
				outtextxy(400,20,str1);
				outtextxy(400,30,str2);
				outtextxy(400,40,str3);
				printf("\n\n\t::Shear Transformation::\n 1. x-shear\n 2. y-shear\nEnter your choice: ");
				scanf("%d",&c);
				printf("\nEnter the shear parameter value: ");
				scanf("%d",&value);
				shear(c,value);
				break;		                
			case 0: break;
			default:	printf("\tInvalid Input\n");
	  }
	  delay(3000);
	  cleardevice();
}while(choice!=0);
	setcolor(15);
	outtextxy(20,400,"Press any key to exit.");
  getch();
  closegraph();
}
void translate(int tx, int ty)
{
	int nx1,nx2,nx3,ny1,ny2,ny3;
	char str1[20],str2[20],str3[20];
	setcolor(10);
	nx1=x1+tx;
	ny1=y1+ty;
	nx2=x2+tx;
	ny2=y2+ty;
	nx3=x3+tx;
	ny3=y3+ty;
	drawTriangle(nx1,ny1,nx2,ny2,nx3,ny3);
	sprintf(str1,"A'(%d,%d)",nx1,ny1);
	sprintf(str2,"B'(%d,%d)",nx2,ny2);
	sprintf(str3,"C'(%d,%d)",nx3,ny3);
	outtextxy(400,80,"After Translation:");
	outtextxy(400,90,str1);
	outtextxy(400,100,str2);
	outtextxy(400,110,str3);  
}
void scale(int sx, int sy)
{
	int nx1,nx2,nx3,ny1,ny2,ny3;
	char str1[20],str2[20],str3[20];	
	setcolor(10);
	nx1=x1*sx;
	ny1=y1*sy;
	nx2=x2*sx;
	ny2=y2*sy;
	nx3=x3*sx;
	ny3=y3*sy;
	drawTriangle(nx1,ny1,nx2,ny2,nx3,ny3);
	sprintf(str1,"A'(%d,%d)",nx1,ny1);
	sprintf(str2,"B'(%d,%d)",nx2,ny2);
	sprintf(str3,"C'(%d,%d)",nx3,ny3);
	outtextxy(400,80,"After Scaling:");
	outtextxy(400,90,str1);
	outtextxy(400,100,str2);
	outtextxy(400,110,str3);
}
void rotate()
{
	int nx1,nx2,nx3,ny1,ny2,ny3,r;
	float t;
	char str1[20],str2[20],str3[20];
	int x1=60,y1=50,x2=110,y2=50,x3=110,y3=100;
	int xc=330,yc=230;
	printf("\nEnter the angle of rotation (theta): ");
	scanf("%d",&r);
	t=r*3.14/180;

	cleardevice();
	delay(100);
	setcolor(15);
	line(xc,0,xc,500);
	line(0,yc,650,yc);
	outtextxy(590,220,"x-axis");
	outtextxy(335,5,"y-axis");
	
	outtextxy(xc+150,yc-200,"Before Rotation");
	drawTriangle(x1+xc,yc-y1,x2+xc,yc-y2,x3+xc,yc-y3);

	sprintf(str1,"A(%d,%d)",x1,y1);
	sprintf(str2,"B(%d,%d)",x2,y2);
	sprintf(str3,"C(%d,%d)",x3,y3);
	outtextxy(20,10,"Before Rotation: ");
	outtextxy(20,20,str1);
	outtextxy(20,30,str2);
	outtextxy(20,40,str3);

	nx1=(int)(x1*cos(t)-y1*sin(t));
	ny1=(int)(x1*sin(t)+y1*cos(t));
	nx2=(int)(x2*cos(t)-y2*sin(t));
	ny2=(int)(x2*sin(t)+y2*cos(t));
	nx3=(int)(x3*cos(t)-y3*sin(t));
	ny3=(int)(x3*sin(t)+y3*cos(t));

	delay(500);
	setcolor(10);
	outtextxy(xc+150,yc-190,"After Rotation");
	drawTriangle(nx1+xc,yc-ny1,nx2+xc,yc-ny2,nx3+xc,yc-ny3);

	sprintf(str1,"A'(%d,%d)",nx1,ny1);
	sprintf(str2,"B'(%d,%d)",nx2,ny2);
	sprintf(str3,"C'(%d,%d)",nx3,ny3);
	outtextxy(20,80,"After Rotation: ");
	outtextxy(20,90,str1);
	outtextxy(20,100,str2);
	outtextxy(20,110,str3);
}
void reflect()
{
	int nx1,nx2,nx3,ny1,ny2,ny3,value,c;
	int x1=60,y1=50,x2=110,y2=50,x3=110,y3=100;
	int xc=330,yc=230;
	char str1[20],str2[20],str3[20];
	printf("\n\t::Reflection::\n 1. x-axis\n 2. y-axis\n 3. line y=x\n 4. line y=-x\nEnter your choice: ");
	scanf("%d",&c);
	cleardevice();
	delay(100);
	setcolor(15);
	line(xc,0,xc,500);
	line(0,yc,650,yc);
	outtextxy(590,220,"x-axis");
	outtextxy(335,5,"y-axis");

	outtextxy(xc+150,yc-200,"Before Reflection");
	drawTriangle(x1+xc,yc-y1,x2+xc,yc-y2,x3+xc,yc-y3);

	sprintf(str1,"A(%d,%d)",x1,y1);
	sprintf(str2,"B(%d,%d)",x2,y2);
	sprintf(str3,"C(%d,%d)",x3,y3);
	outtextxy(20,10,"Before Reflection: ");
	outtextxy(20,20,str1);
	outtextxy(20,30,str2);
	outtextxy(20,40,str3);

	if(c==1)
	{
		nx1=x1;
		ny1=-y1;
		nx2=x2;
		ny2=-y2;
		nx3=x3;
		ny3=-y3;
	}
	else if (c==2)
	{
		nx1=-x1;
		ny1=y1;
		nx2=-x2;
		ny2=y2;
		nx3=-x3;
		ny3=y3;
	}
	else if (c==3)
	{
		line(xc-400,yc+400,xc+400,yc-400);
		outtextxy(xc+210,yc-200,"y=x");
		nx1=y1;
		ny1=x1;
		nx2=y2;
		ny2=x2;
		nx3=y3;
		ny3=x3;
	}
	else
	{
		line(xc-400,yc-400,xc+400,yc+400);
		outtextxy(xc+210,yc+200,"y=-x");
		nx1=-y1;
		ny1=-x1;
		nx2=-y2;
		ny2=-x2;
		nx3=-y3;
		ny3=-x3;
	}
	delay(500);
	setcolor(10);
	outtextxy(xc+150,yc-190,"After Reflection");
	drawTriangle(nx1+xc,yc-ny1,nx2+xc,yc-ny2,nx3+xc,yc-ny3);

	sprintf(str1,"A'(%d,%d)",nx1,ny1);
	sprintf(str2,"B'(%d,%d)",nx2,ny2);
	sprintf(str3,"C'(%d,%d)",nx3,ny3);
	outtextxy(20,80,"After Reflection :");
	outtextxy(20,90,str1);
	outtextxy(20,100,str2);
	outtextxy(20,110,str3);
}
void shear(int c,int value)
{
	int nx1,nx2,nx3,ny1,ny2,ny3;
	char str1[20],str2[20],str3[20];


	sprintf(str1,"A(%d,%d)",x1,y1);
	sprintf(str2,"B(%d,%d)",x2,y2);
	sprintf(str3,"C(%d,%d)",x3,y3);
	outtextxy(400,10,"Before Shear Transformation: ");
	outtextxy(400,20,str1);
	outtextxy(400,30,str2);
	outtextxy(400,40,str3);
	setcolor(10);
	
	if(c==1)
	{
		nx1=x1+y1*value;
		ny1=y1;
		nx2=x2+y2*value;
		ny2=y2;
		nx3=x3+y3*value;
		ny3=y3;
	}
	else
	{
		nx1=x1;
		ny1=y1+x1*value;
		nx2=x2;
		ny2=y2+x2*value;
		nx3=x3;
		ny3=y3+x3*value;
	}
	drawTriangle(nx1,ny1,nx2,ny2,nx3,ny3);
	
	sprintf(str1,"A'(%d,%d)",nx1,ny1);
	sprintf(str2,"B'(%d,%d)",nx2,ny2);
	sprintf(str3,"C'(%d,%d)",nx3,ny3);
	outtextxy(400,80,"After Shear Transformation: ");
	outtextxy(400,90,str1);
	outtextxy(400,100,str2);
	outtextxy(400,110,str3);
}
