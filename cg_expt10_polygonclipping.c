#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
int xmin=100,ymin=100,xmax=400,ymax=300;

void clipline(int x1,int y1,int x2,int y2){
	int c=1;
	float x,y,m;
	if(x1>xmin && x2>xmin && x1<xmax && x2<xmax && y1>ymin && y2>ymin && y1<ymax && y2<ymax)
	   c=1;
	else if((x1<xmin && x2<xmin)||(x1>xmax && x2>xmax)||(y1<ymin && y2<ymin)||(y1>ymax && y2>ymax))
		c=2;
	else
		c=3;
	switch(c){
		case 1:	 line(x1,y1,x2,y2); break;
		case 2:	 break;
		case 3:	 m=(float)(y2-y1)/(x2-x1);  //compute slope of line
				//check point 1
				if(x1<xmin){		//check left
					y1=(int)(y1+m*(xmin-x1));
					x1=xmin;
				}

				if(x1>xmax){                //check right
					y1=(int)(y1+m*(xmax-x1));
					x1=xmax;
				}

				if(y1>ymax){                //check below
					x1=(int)(x1+(float)(ymax-y1)/m);
					y1=ymax;
				}

				if(y1<ymin){                //check above
					x1=(int)(x1+(float)(ymin-y1)/m);
					y1=ymin;
				}

				//check point 2
				if(x2<xmin){                //check left
					y2=(int)(y2+m*(xmin-x2));
					x2=xmin;
				}

				if(x2>xmax){                //check right
					y2=(int)(y2+m*(xmax-x2));
					x2=xmax;
				}

				if(y2>ymax){                //check below
					x2=(int)(x2+(float)(ymax-y2)/m);
					y2=ymax;
				}

				if(y2<ymin){                //check above
					x2=(int)(x2+(float)(ymin-y2)/m);
					y2=ymin;
				}
				line(x1,y1,x2,y2);
				break;
	}
}
int main(){
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	settextstyle(SANS_SERIF_FONT,0,4);
	setcolor(LIGHTRED);
	outtext("*********Polygon before clipping************");
	rectangle(xmin,ymin,xmax,ymax);//Drawing the clipping Window
	setcolor(YELLOW);
	line(200,40,40,200);
	line(40,200,200,340);
	line(200,340,440,200);
	line(440,200,200,40);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(200,200,YELLOW);

	outtextxy(100,350,"\nPress Enter to Clip the Line.....");
	getch();
	cleardevice();
    setcolor(LIGHTGREEN);
	outtext("**********Polygon after clipping*********");
    setcolor(YELLOW);
	rectangle(xmin,ymin,xmax,ymax);
	clipline(200,40,40,200);
	clipline(40,200,200,340);
	clipline(200,340,440,200);
	clipline(440,200,200,40);
    //boundary_fill_4(200,200,MAGENTA,YELLOW);/*Boundary=YELLOW,fill=MAGENTA*/
     setfillstyle(SOLID_FILL,MAGENTA);
     floodfill(200,200,YELLOW);
	getch();
	closegraph();
	return 0;
}
