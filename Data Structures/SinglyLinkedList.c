#include <stdio.h>
#include <stdlib.h>
typedef struct NODE 
{
  int item;
  struct NODE *next;
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
Deletionll(node **head_ptr)
{
    if(*head_ptr != NULL)
    {
       // store the old value of pointer to head pointer
       node *temp;
       temp=*head_ptr;
 
       // Change head pointer to point to next node
       *head_ptr = (*head_ptr)->next;
 
       // delete memory allocated for the previous head node
       free(temp);
    }
    else{
      printf("Underflow\n");
    }
}
traversell(node **head_ptr){
  node *temp;
  temp=*head_ptr;
  while(*head_ptr != NULL){
    printf("%d ",(*head_ptr)->item);
    *head_ptr=(*head_ptr)->next;
  }
  *head_ptr=temp;
}
Insertionllx(node **head_ptr){
  node *temp,*node1,*temp2;
  temp=*head_ptr;
  int loc,value;
  node1=(node *)malloc(sizeof(node));
  if(node1==NULL){
    printf("Overflow\n");
    exit(1);
  }
  printf("Enter location and value: ");
  scanf("%d%d",&loc,&value);
  node1->item=value;
  while(loc--){
    if(*head_ptr==NULL){
      printf("Overflow");
      exit(1);
    }
    *head_ptr=(*head_ptr)->next;
  }
  temp2=(*head_ptr)->next;
  (*head_ptr)->next=node1;
  node1->next=temp2;
  *head_ptr=temp;
}
deletionllx(node **head_ptr){
  node *temp,*temp1;
  int loc;
  temp=*head_ptr;
  printf("Enter the index you want to delete");
  scanf("%d",&loc);
  loc--;
  while(loc--){
    if(*head_ptr==NULL){
      printf("Underflow\n");
      exit(1);
    }
    *head_ptr=(*head_ptr)->next;
  }
  temp1=(*head_ptr)->next;
  (*head_ptr)->next=(temp1)->next;
  *head_ptr=temp;
}
void main(){
    node *head,**head_ptr;
    int flag=1,ch;
    head=(node*)malloc(sizeof(node));
    head_ptr=(node **)malloc(sizeof(node*));
    head_ptr=&head;
    head=NULL;
  while(flag==1){
    printf("Enter the operation you want to do on linked list\n");
    printf("1.Insertion\n2.Deletion\n3.Traverse\n4.Insertion at a particular location\n5.Deletion at a particular location\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:Insertionll(head_ptr);
              break;
      case 2:Deletionll(head_ptr);
              break;
      case 3:traversell(head_ptr);
              break;
      case 4:Insertionllx(head_ptr);
              break;
      case 5:deletionllx(head_ptr);
              break;
    }

    printf("Press 1 to perform another operation: ");
    scanf("%d",&flag);
  }
}