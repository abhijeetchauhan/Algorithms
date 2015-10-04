#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
  struct node *left,*right;
  char next;
  unsigned long long int data,count;
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
    add->count=1;
    *root=add;
    return;
  }
  if(((*root)->data)>no){
    addBST(&(*root)->left,no);
    return;
  }
  else if(((*root)->data)<no){
    addBST(&(*root)->right,no);
    return;
  } 
  else{
    if((*root)->right==NULL && (*root)->left)==NULL)){
      (*root)->count=(*root)->count+1;
      return;
    }
    else if((*root)->right==NULL){
      (*root)->next="l"
      addBST(&(*root)->left,no);
      return;
    }
    else if((*root)->left)==NULL){
      (*root)->next="r";
      addBST(&(*root)->right,no);
      return;
    }
    else{
      if((*root)->next="r"){
        addBST(&(*root)->right,no);
        return;
      }
      else{
        addBST(&(*root)->left,no);
        return;
      }
    }
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