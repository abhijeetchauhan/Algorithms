#include <stdio.h>
#include <graphics.h>
int sign(float n){
  if(n>0) return 1;
  else if(n<0)  return -1;
  else  return 0;
}
int main(){
  float x1,x2,y1,y2,dx,dy,step,x,y,x3,y3,x4,y4;
  int flag[4];
  int i,gdriver=DETECT,gmode,p;
  scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
  scanf("%f%f%f%f",&x3,&y3,&x4,&y4);  
  initgraph(&gdriver,&gmode,NULL);
  if(x1==x2 && y1 == y2){
    putpixel(x1,y1,WHITE);
    return 0;
  }
  dx=abs(x2-x1);dy=abs(y2-y1);
  step=dx>dy?dx:dy;
  dx=(x2-x1)/step;dy=(y2-y1)/step;
  x=x1+0.5*sign(dx);
  y=y1+0.5*sign(dy);
  rectangle(x3,y3,x4,y4);
  for(i=0;i<step;i++){
    flag[0]=flag[1]=flag[2]=flag[3]=0;
    if(x>x3)flag[0]=1;
    if(y>y3)flag[1]=1;
    if(x<x4)flag[2]=1;
    if(y<y4)flag[3]=1;
    if(flag[0]==1 && flag[1]==1 && flag[2]==1 && flag[3]==1){
    putpixel(x,y,WHITE);
  }
    x=x+dx;
    y=y+dy;
  }
  // dx=abs(x2-x1);dy=abs(y2-y1);
  // if(dy<dx){
  //   p=2*dy-dx;x=x1;y=y1;
  //   while(x<x2){
  //     putpixel(x,y,WHITE);
  //     if(p<0){
  //       x++;
  //       p=p+2*dy;
  //     }
  //     else{
  //       x++;
  //       y++;
  //       p=p+2*(dy-dx);
  //     }
  //   }
  // }
  // else{
  //   p=2*dx-dy;x=x1;y=y1;
  //   while(y<y2){
  //     putpixel(x,y,WHITE);
  //     if(p<0){
  //       y++;
  //       p=p+2*dx;
  //     }
  //     else{
  //       y++;x++;
  //       p=p+2*(dx-dy);
  //     }
  //   }
  // }
  getch();
  return 0;
}