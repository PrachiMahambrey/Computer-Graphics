#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT, gm=DETECT;
 initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
 line(2,50,2,120);//P
 arc(10,65,300,60,17);//p
 line(2,50,18,50);//P
 line(2,80,18,80);//P
 line(34,50,34,120);//R
 arc(42,65,300,60,17);//R
 line(34,79,61,120);//R
 line(34,50,50,50);//R
 line(34,80,50,80);//R
 line(70,120,90,50);//A
 line(90,50,110,120);//A
 line(80,85,100,85);//A
 arc(150,85,99,260,35);//C
 line(160,50,160,120);//H
 line(190,50,190,120);//H
 line(160,85,190,85);//H
 line(200,50,230,50);//I
 line(200,120,230,120);//I
 line(215,50,215,120);//I

 //in devnagari
 line(0,200,140,200);
 line(45,200,45,260);
 line(65,200,65,260);
 line(115,200,115,260);
 line(135,200,135,260);
 line(45,207,15,260);
 arc(24,200,180,0,20);
 arc(125,200,0,180,10);
 arc(102,225,180,0,12);
 line(75,225,95,225);

 getch();
 closegraph();
}
