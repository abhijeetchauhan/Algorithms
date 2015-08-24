#include <stdio.h>
#include <stdlib.h>
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
void main(){
    node *head,**head_ptr;
    int flag=1,ch;
    head_ptr=&head;
    head=NULL;
  while(flag==1){
    printf("Enter the operation you want to do on linked list\n");
    printf("1.Insertion\n2.Deletion\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:Insertionll(head_ptr);
    }
    printf("Press 1 to perform another operation: ");
    scanf("%d",&flag);
  }
}