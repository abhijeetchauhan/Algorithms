#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
  struct node *left,*right;
  unsigned long long int data;
};
typedef struct node Node;
unsigned long long int countBST(Node **root,unsigned long long int targetkey){
  if(*root==NULL){
    return 0;
  }
  if(((*root)->data)>targetkey){
   return 1+countBST(&(*root)->left,targetkey);
  }
  else if(((*root)->data)<targetkey){
    return countBST(&(*root)->right,targetkey);
  }
}
void addBST(Node **root,unsigned long long int no){
  if((*root)==NULL){
    Node *add;
    add=(Node*)malloc(sizeof(Node));
    add->left=NULL;
    add->right=NULL;
    add->data=no;
    *root=add;
    return;
  }
  if(((*root)->data)>no){
    addBST(&(*root)->left,no);
    return;
  }
  else{
    addBST(&(*root)->right,no);
    return;
  } 
}
void main(){
  unsigned long long int no;
  Node *root;
  printf("%llu\n",countBST(&root,2));
  addBST(&root,2);
  printf("%llu\n",countBST(&root,3));
  addBST(&root,3);
  printf("%llu\n",countBST(&root,7));
  addBST(&root,7);
  printf("%llu\n",countBST(&root,5));
  addBST(&root,5);
  printf("%llu\n",countBST(&root,4));
}