#include <stdio.h>
#include <math.h>
#include <graphics.h>
int main(){
  int gdriver=DETECT,gmode;
  float x1,y1,x2,y2,x3,y3,ang,a,b,x,y,t;
  scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
  scanf("%f",&ang);
  a=sin((ang*3.14)/180);
  b=cos((ang*3.14)/180);
  x=(x1+x2+x3)/3;y=(y1+y2+y3)/3;
  initgraph(&gdriver,&gmode,NULL);
  line(x1,y1,x2,y2);line(x2,y2,x3,y3);line(x3,y3,x1,y1);
  x1-=x;x2-=x;x3-=x;
  y1-=y;y2-=y;y3-=y;
  t=x1;
  x1=x1*b-a*y1;
  y1=t*a+b*y1;t=x2;
  x2=x2*b-a*y2;
  y2=t*a+b*y2;t=x3;
  x3=x3*b-a*y3;
  y3=t*a+b*y3;
  x1+=x;x2+=x;x3+=x;
  y1+=y;y2+=y;y3+=y;  
  line(x1,y1,x2,y2);line(x2,y2,x3,y3);line(x3,y3,x1,y1);
  getch();
} 