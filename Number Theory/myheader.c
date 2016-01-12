#include <stdio.h>
#include "myheader.c"
int main(void) {
  // your code goes here
  int t,d,x,y,a;
  // scanf("%llu%llu",&t,&d);
  // while(t--){
  //  scanf("%llu%llu",&x,&y);
  //  a=ModExpo(x,y,d);
  //  printf("%llu",a);
  // }
  a=ModExpo(5,2,3);
  printf("%d",a);
  return 0;
}