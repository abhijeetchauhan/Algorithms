#include <stdio.h>
#include <stdlib.h>
unsigned long long int * DecimalToBaseN(unsigned long long int no,unsigned long long int base){
  unsigned long long int output[100],reverse[100];
  unsigned long long int *out;
  out=reverse;
  unsigned long long int i=1;
  while(no){
    output[i]=no%base;
    no=no/base;
    i++;
  }
  output[0]=i;
  reverse[0]=i;
  for(i=1;i<output[0];i++){
    reverse[i]=output[output[0]-i];
  }
  return out;
}
unsigned long long int * DecimalToBaseNr(unsigned long long int no,unsigned long long int base){
  unsigned long long int output[100];
  unsigned long long int *out;
  out=output;
  unsigned long long int i=1;
  while(no){
    output[i]=no%base;
    no=no/base;
    i++;
  }
  output[0]=i;
  return out;
}
unsigned long long int ModExpo(unsigned long long int base,unsigned long long int decimalpower,unsigned long long int divisor){
  unsigned long long int rem=1,i;
  unsigned long long int *bin=DecimalToBaseNr(decimalpower,2);
  unsigned long long int power=base%divisor;
  for(i=1;i<bin[0];i++){
    if(bin[i]==1)
      rem=(rem*power)%divisor;
    power=(power*power)%divisor;
  }
  return rem;
}