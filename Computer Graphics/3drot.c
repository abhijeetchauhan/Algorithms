#include <stdio.h>
#include <graphics.h>
float pres(float x,float z,float d){
  return x/((z/d)+1);
}
void drawRectangle(float x1,float y1,float x2,float y2){
  line(x1,y1,x1,y2);
  line(x1,y1,x2,y1);
  line(x2,y1,x2,y2);
  line(x1,y2,x2,y2);
}
void drawCube(float x1,float y1,float z1,float x2,float y2,float z2){
  float z=z2-z1;
  float d=30,x3,y3,x4,y4;
  drawRectangle(x1,y1,x2,y2);
  x3=pres(x1,z,d);
  y3=pres(y1,z,d);
  x4=pres(x2,z,d);
  y4=pres(y2,z,d);
  drawRectangle(x3,y3,x4,y4);
  line(x1,y1,x3,y3);
  line(x2,y2,x4,y4);
  line(x1,y2,x3,y4);
  line(x2,y1,x4,y3);
}
int main(){
  int gdriver=DETECT,gmode;
  float x1,x2,y1,y2,z1,z2,x,y,z;
  scanf("%f%f%f%f%f%f",&x1,&y1,&z1,&x2,&y2,&z2);
  initgraph(&gdriver,&gmode,NULL);
  drawCube(x1,y1,z1,x2,y2,z2);
  x=(x1+x2)/2;y=(y1+y2)/2;z=(z1+z2)/2;
  
  getch();
}