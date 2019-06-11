#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void boundaryfill4 ( int x, int y, int fill, int boundary)
 {
 int current;
 current = getpixel (x, y);
 if ((current != boundary) &&(current != fill)  )
 {

 putpixel ( x, y,fill);
 boundaryfill4 (x+1, y, fill, boundary);
 boundaryfill4 (x-1, y, fill, boundary);
 boundaryfill4 (x, y+1, fill, boundary);
 boundaryfill4 (x, y-1, fill, boundary);
 }
 }
 void boundaryfill8 ( int x, int y, int fill, int boundary)
 {
 int current;
 current = getpixel (x, y);
 if ((current != boundary) &&(current != fill)  )
 {

 putpixel ( x, y,fill);
 boundaryfill8 (x+1, y, fill, boundary);
 boundaryfill8 (x-1, y, fill, boundary);
 boundaryfill8 (x, y+1, fill, boundary);
 boundaryfill8 (x, y-1, fill, boundary);
 boundaryfill8(x-1,y-1,fill,boundary);
 boundaryfill8(x-1,y+1,fill,boundary);
 boundaryfill8(x+1,y-1,fill,boundary);
 boundaryfill8(x+1,y+1,fill,boundary);
 }
 }
void main(){
int gd=DETECT,gm=DETECT;
initgraph(&gd, &gm, "C:\\TC\\BGI");
 rectangle(10,40,50,10) ;
 getch();
 boundaryfill4(15,15,YELLOW,WHITE);
 outtextxy(10,50,"4-side boundry fill");
  rectangle(10,110,50,70);
  boundaryfill8(15,75,YELLOW,WHITE);
  outtextxy(10,120,"8-side boundary fill ");
getch();
closegraph();
}
