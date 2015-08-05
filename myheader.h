int * DecimalToBaseN(int no,int base){
  int output[100],reverse[100];
  int *out;
  out=reverse;
  int i=1;
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
int * DecimalToBaseNr(int no,int base){
  int output[100];
  int *out;
  out=output;
  int i=1;
  while(no){
    output[i]=no%base;
    no=no/base;
    i++;
  }
  output[0]=i;
  return out;
}
int ModExpo(int base,int decimalpower,int divisor){
  int rem=1,i;
  int *bin=DecimalToBaseNr(decimalpower,2);
  int power=base%divisor;
  for(i=1;i<bin[0];i++){
    if(bin[i]==1)
      rem=(rem*power)%divisor;
    power=(power*power)%divisor;
  }
  return rem;
}