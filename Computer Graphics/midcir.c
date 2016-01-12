#include <stdio.h>
#include <graphics.h>
int main(){
  int gdriver=DETECT,gmode;
  int r,xc,yc,x,y,p;
  scanf("%d%d%d",&xc,&yc,&r);
  x=0;y=r;
  initgraph(&gdriver,&gmode,NULL);
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);  
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  putpixel(xc+y,yc+x,WHITE);
  putpixel(xc+y,yc-x,WHITE);  
  putpixel(xc-y,yc+x,WHITE);
  putpixel(xc-y,yc-x,WHITE);
  p=3-2*r;
  while(x<=y){
    if(p<0){
      x++;
      p=p+4*x+6;
    }
    else{
      x++;
      y--;
      p=p+4*(x-y)+10;
    }
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);  
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  putpixel(xc+y,yc+x,WHITE);
  putpixel(xc+y,yc-x,WHITE);  
  putpixel(xc-y,yc+x,WHITE);
  putpixel(xc-y,yc-x,WHITE);
 }
   getch();

}