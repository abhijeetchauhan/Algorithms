#include <stdio.h>
#include "myheader.h"
void main(){
  int power,base,divisor;
  printf("Enter base,power and divisor");
  scanf("%d%d%d",&base,&power,&divisor);
  printf("The remainder is %d\n",ModExpo(base,power,divisor));
}
