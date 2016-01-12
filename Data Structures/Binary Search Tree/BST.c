#include "BST.h"
void main(){
  Node *add,*root;
  root=NULL;
  int i;
  add=(Node *)malloc(sizeof(Node));
  for(i=0;i<8;i++){
    addBST(&root,i);
  }
  printf("test\n");
  add=findSmallestNode(&root);
  printf("smallest %d",add->data);
  deleteBST(&root,add->data);
  add=findSmallestNode(&root);
  printf("smallest %d",add->data);
}