#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int item;
struct node{
  item data;
  struct node *next; 
};
typedef struct node NODE;

bool InsertFirst(NODE **start,item data){
  // This algorithm inserts item as the first NODE of the linked list pointed by START
  NODE *p;
  p=(NODE*)malloc(sizeof(NODE));
  if(!p){
    printf("Overflow\n");
    return false;
  }
  p->data=data;
  if(*start==NULL){
    p->next=NULL;
  }
  else{
    p->next=*start;
  }
  *start=p;
  return true;
}

bool InsertLast(NODE **start,item data){
  // This algorithm inserts an item at the last of the linked list
  NODE *p,*loc;
  p=(NODE*)malloc(sizeof(NODE));
  if(!p){
    printf("Overflow\n");
    return false;
  }
  p->data=data;
  p->next=NULL;
  if(*start==NULL){
    *start=p;
  }
  else{
    loc=*start;
    while(loc->next!=NULL){
      loc=loc->next;
    }
    loc->next=p;
  }
  return true;
}
bool InsertSpe(NODE **start,item data,int loc){
  NODE *p,*temp;
  unsigned long long int k;
  p=(NODE*)malloc(sizeof(NODE));
  if(!p){
    printf("Overflow\n");
    return false;
  }
  p->data=data;
  for(k=0,temp=*start;k<loc;k++){
    temp=temp->next;
    if(temp==NULL){
      return false;
    }
  }
  p->next=temp->next;
  temp->next=p;
  return true;
}
void Traverse(NODE **start){
  NODE *p;
  p=*start;
  while(p){
    printf("%d",p->data);
    p=p->next;
  }
}
bool DeleteFirst(NODE **start,item *out){
  NODE *temp;
  if(*start==NULL){
    printf("UnderFlow\n");
    return false;
  }
  temp=*start;
  *out=temp->data;
  *start=(*start)->next;
  free(temp);
  return true;
}
bool DeleteLast(NODE **start,item *out){
  NODE *temp,*ptr;
  if(*start==NULL){
    printf("UnderFlow\n");
    return false;
  }
  else if((*start)->next==NULL){
    ptr=*start;
    *start=NULL;
    *out=ptr->data;
    free(ptr);
    return true;
  }
  else{
    ptr=*start;
    while(ptr->next!=NULL){
      temp=ptr;
      ptr=ptr->next;
    }
    temp->next=ptr->next;
    *out=ptr->data;
    free(ptr);
    return true;
  }
}
bool DeleteSpe(NODE **start,item *out,int loc)
{
  NODE *temp,*ptr;
  int i;
  if((*start)==NULL){
    printf("UnderFlow\n");
    return false;
  }
  for(ptr=*start,i=0;i<=loc;i++){
    temp=ptr;
    ptr=ptr->next;
    if(ptr==NULL){
      return false;
    }
  }
  temp->next=ptr->next;
  *out=ptr->data;
  free(ptr);
}
