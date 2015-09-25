#include "SinglyLinkedList.h"

test1(){
  int no=10;
  NODE *test1,*test2;
  test1=(NODE*)malloc(sizeof(NODE));
  test2=(NODE*)malloc(sizeof(NODE));
  (test1->data)=no;
  no=20;
  test1->next=test2;
  (test2->data)=no;
  test2->next=NULL;
  while(test1){
    printf("%d",test1->data);
    test1=test1->next;
  }
}
void main(){
  NODE *start;
  start=NULL;
  int no;
  InsertFirst(&start,10);
  InsertFirst(&start,20);
  InsertLast(&start,30);
  InsertSpe(&start,40,2);
  InsertSpe(&start,40,4);
  InsertSpe(&start,40,6);
  Traverse(&start);
  DeleteFirst(&start,&no);
  DeleteLast(&start,&no);
  printf("\n");
  Traverse(&start);
  DeleteSpe(&start,&no,0);
  printf("\n");
  Traverse(&start);
}