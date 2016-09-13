#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long int
typedef struct pair{
  ll first,second;
}pair;
typedef struct pairs{
  pair data;
  struct pairs *next; 
}pairs;
void InsertFirst(pairs **start,pair data){
  // This algorithm inserts ll as the first pairs of the linked list pointed by START
  pairs *p;
  p=(pairs*)malloc(sizeof(pairs));
  if(!p){
    printf("Overflow\n");
  }
  p->data=data;
  if(*start==NULL){
    p->next=NULL;
  }
  else{
    p->next=*start;
  }
  *start=p;
}
void Traverse(pairs **start){
  pairs *p;
  p=*start;
  while(p){
    printf("(%lld,%lld)",p->data.first,p->data.second);
    p=p->next;
  }
}
bool DeleteFirst(pairs **start){
  pairs *temp;
  if(*start==NULL){
    printf("UnderFlow\n");
    return false;
  }
  temp=*start;
  *start=(*start)->next;
  free(temp);
  return true;
}
void Check(pairs **one,pairs **kdec,pairs **k,ll *count,ll no){
  pairs *in,*check,*out;
  in=*kdec;check=*one;out=*k;
  while(in){
    if((check->data.first)>(in->data.first) && (check->data.second)<(in->data.second)){
      in=in->next;
    }
    else{
      break;
    }
  }
  if(in!=NULL){
    return;
  }
  else{
    in=*kdec;
    while(in){
      InsertFirst(k,in->data);
      in=in->next;
    }
    InsertFirst(k,check->data);
    *count=*count+1;
    return;
  }
}