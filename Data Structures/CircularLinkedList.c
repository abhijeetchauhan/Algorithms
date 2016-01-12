#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int index;
  int value;
}item;
typedef struct 
{
  item item;
  struct node *link;
}node;
Insertionll(node **head_ptr){
  node *test,*temp;
  int value;
  test=(node *)malloc(sizeof(node));
  if(test==NULL){
    printf("NO Space Available");
  }
  printf("Enter the value: ");
  scanf("%d",&value);
  (*test).item.value=value;
  if(*head_ptr==NULL){
    (*test).item.index=0;
    (*test).link=test;
    (*head_ptr)=test;
  }
  else{
    (*test).item.index=(**head_ptr).item.index+1;
    temp=(**head_ptr).link;
    (*head_ptr)->link=test;
    (*test).link=test;
    (*head_ptr)=test;
  }

  printf("Index is %d and value is %d",(*test).item.index,(*test).item.value);
}
deletionllx(node **head_ptr){
  node *temp,*temp2;
  int index;
  temp=*head_ptr;
  printf("Enter the index: \n");
  scanf("%d",&index);
  index++;
  while((**head_ptr).item.index!=index){
    (*head_ptr)=(*head_ptr)->link;
  }
  temp2=(*head_ptr)->link;
  (*head_ptr)->link=temp2->link;
  *head_ptr=temp;
}
NodeNumber(node **head_ptr){
  printf("%d",(**head_ptr).item.index);
}
void main(){
    node *head,**head_ptr;
    int flag=1,ch;
    head_ptr=&head;
    head=NULL;
  while(flag==1){
    printf("Enter the operation you want to do on circular linked list\n");
    printf("1.Insertion\n2.Deletion\n3.Traverse\n4.Insertion at a particular location\n5.Deletion at a particular location\n6.Calculate no. of nodes");
    scanf("%d",&ch);
    switch(ch){
      case 1:Insertionll(head_ptr);
              break;
      // case 2:Deletionll(head_ptr);
      //         break;
      // case 3:traversell(head_ptr);
      //         break;
      // case 4:Insertionllx(head_ptr);
      //         break;
      case 5:deletionllx(head_ptr);
              break;
      case 6:NodeNumber(head_ptr);
              break;
      default:printf("Invalid input\n");
    }

    printf("Press 1 to perform another operation: ");
    scanf("%d",&flag);
  }
}