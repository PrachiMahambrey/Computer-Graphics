#include<stdio.h>
#include<conio.h>
#include<graphics.h>
const int INSIDE=0;
const int LEFT=1;
const int RIGHT=2;
const int BOTTOM=4;
const int B_LEFT=5;
const int B_RIGHT=6;
const int T_LEFT=9;
const int TOP=8;
const int T_RIGHT=10;
int WXMin=0,WYMin=0,WXMax=0,WYMax=0;
int Region_Code(int X,int Y);
int main()
{	
int i=0,n=1,gd=DETECT,gm=DETECT;
	int Code_1,X1,Y1,X2,Y2,Code_2,FLAG=0,Accept=0,temp=0,Code_Temp=0,x=0,y=0;
	float slope=0.0,xdiff=0,ydiff=0;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();
	printf("\n\n\n\n\n\n\n\*   Cohen Suthernland Line Clipping    *\n");
	printf(" Line %d : X1 Y1 :",i+1);
	scanf("%d%d",&X1,&Y1);
	printf("        : X2 Y2 :");
	scanf("%d%d",&X2,&Y2);
		line(X1,Y1,X2,Y2);
     
    printf(" Enter Window Co-ordinates : \n");
    printf(" Bottom Left : ");
    scanf("%d%d",&WXMin,&WYMin);
    printf(" Top Right   : ");
    scanf("%d%d",&WXMax,&WYMax);
    rectangle(WXMin,WYMin,WXMax,WYMax);
    printf(" Press 1 To Start Clipping : ");
	scanf("%d",&FLAG);
	if (FLAG!=1)    exit(0);
    cleardevice();
    rectangle(WXMin,WYMin,WXMax,WYMax);
    for(i=0;i<n;i++)
    {  Code_1=Region_Code(X1,Y1);
		Code_2=Region_Code(X2,Y2);
		ydiff= Y2-Y1;
		xdiff= X2-X1;
		slope=ydiff/xdiff;
		Accept=0;
		while(temp==0)
		       {	if((Code_1==0)&&(Code_2==0)){
				Accept=1;
				printf(" Inside: \n");
				break;
			}
			else if(Code_1==Code_2){
				printf(" Outside: \n");
				break;
			}
			else{
		if(Code_1!=0){
					Code_Temp=Code_1;
					x=X1;
					y=Y1;
				}
				else{
					Code_Temp=Code_2;
					x=X2;
					y=Y2;
				}
				printf(" PARTIALLY:  %d %d\n",x,y);
		if(Code_Temp==TOP){
					x=x+(1/slope)*(WYMax-y);
					y=WYMax;
				}
				else if(Code_Temp==BOTTOM){
					x=x+(1/slope)*(WYMin-y);
					y=WYMin;
				}else if(Code_Temp==LEFT){
					x=WXMin;
					y=y+slope*(WXMin-x);
				}else if(Code_Temp==RIGHT){
					x=WXMax;
					y=y+slope*(WXMax-x);
				}else if(Code_Temp==T_LEFT){
		    x=WXMin;
					y=y+slope*(WXMin-x);
				}else if(Code_Temp==T_RIGHT){
		    x=WXMax;
					y=y+slope*(WXMax-x);
				}else if(Code_Temp==B_LEFT){
		    x=WXMin;
					y=y+slope*(WXMin-x);
				}else if(Code_Temp==B_RIGHT){
		    x=WXMax;
					y=y+slope*(WXMax-x);
				}
				if(Code_Temp==Code_1){
					X1=x;
					Y1=y;
					Code_1=Region_Code(X1,Y1);
				}else{
					X2=x;
					Y2=y;
					Code_2=Region_Code(X2,Y2);
				}
			}
		}
	    setcolor(RED);
	    line(X1,Y1,X2,Y2);
	    setcolor(WHITE);
	    printf("new coordinates : X1=%d Y1=%d  X2=%d  Y2=%d",X1,Y1,X2,Y2);
    }
	getch();
	closegraph();
	return 0;
}
int Region_Code(int X,int Y){
	int Code=0;
	if((Y-WYMax)>0)	Code+=8;
	if((WYMin-Y)>0)	Code+=4;
	if((X-WXMax)>0)	Code+=2;
	if((WXMin-X)>0)	Code+=1;
	return Code;
}
