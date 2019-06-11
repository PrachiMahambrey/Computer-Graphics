#include<iostream.h>
#include<conio.h>
#include<graphics.h>

 void floodfill4(int x, int y, int fill,int old_col){
  if(getpixel(x,y)==old_col){
       putpixel(x,y,fill);
      floodfill4 (x+1, y, fill, old_col);
      floodfill4 (x-1, y, fill, old_col);
      floodfill4 (x, y+1, fill, old_col);
      floodfill4 (x, y-1, fill, old_col);
  }
 }

  void floodfill8(int x, int y, int fill,int old_col){
  if(getpixel(x,y)==old_col){
       putpixel(x,y,fill);
      floodfill8 (x+1, y, fill, old_col);
      floodfill8 (x-1, y, fill, old_col);
      floodfill8 (x, y+1, fill, old_col);
      floodfill8 (x, y-1, fill, old_col);
      floodfill8 (x-1, y-1, fill, old_col);
      floodfill8 (x-1, y+1, fill, old_col);
      floodfill8 (x+1, y-1, fill, old_col);
      floodfill8 (x+1, y+1, fill, old_col);
  }
 }

void main(){
int gd=DETECT,gm=DETECT;
initgraph(&gd, &gm, "C:\\TC\\BGI");
 rectangle(10,40,50,10) ;

  outtextxy(10,120,"8-side flood fill ");
 outtextxy(10,50,"4-side flood fill");
  rectangle(10,110,50,70);
   getch();
   floodfill4(15,15,YELLOW,BLACK);
  floodfill8(15,75,YELLOW,BLACK);

getch();
closegraph();
}
