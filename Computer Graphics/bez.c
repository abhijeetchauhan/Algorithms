#include <stdio.h>
#include <graphics.h>
int main(){
  int gdriver=DETECT,gmode;
  float x1,y1,x2,y2,x3,y3,x4,y4,i,x,y;
  scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
  initgraph(&gdriver,&gmode,NULL);
  for(i=0;i<=1;i=i+0.0001){
    x=pow((1-i),3)*x1+pow((1-i),2)*3*i*x2+3*i*i*(1-i)*x3+3*i*i*i*x4;
    y=pow((1-i),3)*y1+pow((1-i),2)*3*i*y2+3*i*i*(1-i)*y3+3*i*i*i*y4;
    putpixel(x,y,WHITE);    
  }
  getch();
}