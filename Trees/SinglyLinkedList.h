#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int item;
struct node{
  item data;
  struct node *next; 
};
typedef struct node NODE;

bool Push(NODE **start,item data){
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
void Traverse(NODE **start){
  NODE *p;
  p=*start;
  while(p){
    printf("%d",p->data);
    p=p->next;
  }
}
bool Pop(NODE **start,item *out){
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