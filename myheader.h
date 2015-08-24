typedef struct 
{
  int item;
  struct node *next;
}node;
Insertionll(node **head_ptr){
  int value;
  node *node1=(node *)malloc(sizeof(node));
  if(node1==NULL){
    printf("Overflow");
    exit(1);
  }
  printf("Enter value: ");
  scanf("%d",&value);
  node1->item=value;
  if(*head_ptr==NULL){
    node1->next=NULL;
    *head_ptr=node1;
  }
  else{
    node1->next=*head_ptr;
    *head_ptr=node1;
  }

}
voidint * DecimalToBaseN(int no,int base){
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