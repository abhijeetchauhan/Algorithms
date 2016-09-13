#include "pairs.h"
// void palindrome(ll size){
//   pairs *start[size];
//   for()
// }
void insert(pair no,pairs **start,ll index){
  InsertFirst(&start[index],no);
}
void main(){
  struct pairs *start[3];

  start[1]=NULL;
  start[2]=NULL;
  struct pair no;
  no.first=10;
  no.second=20;
  // InsertFirst(&start[1],no);
  insert(no,start,1);
  Traverse(&start[1]);
  // no.first=100;no.second=70;
  // InsertFirst(&start[2],no); 
  // printf("\n");
  // Traverse(&start[2]);

}