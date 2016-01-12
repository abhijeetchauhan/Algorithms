#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
  struct node *left,*right;
  int data;
};
typedef struct node Node;
// this algorithms is to find the smallest node in a BST
Node *findSmallestNode(Node **root){
  if(!(*root)->left){
    return *root;
  }
  return findSmallestNode(&(*root)->left);
}
Node *findLargestNode(Node **root){
  if(!(*root)->right){
    return *root;
  }
  return findLargestNode(&(*root)->right);
}
Node *searchBST(Node **root,int targetkey){
  if(*root==NULL){
    return NULL;
  }
  if(((*root)->data)>targetkey){
   return searchBST(&(*root)->left,targetkey);
  }
  else if(((*root)->data)<targetkey){
    return searchBST(&(*root)->right,targetkey);
  }
  else{
    return *root;
  }
}
void Preorder(node *root) {
    if(root!=NULL){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void addBST(Node **root,int no){
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
void deleteBST(Node **root,int no){
  Node *temp;
  if((*root)==NULL){
    return;
  }
  if((*root)->data>no){
    deleteBST(&(*root)->left,no);
    return;
  }
  else if((*root)->data<no){
    deleteBST(&(*root)->right,no);
    return;
  }
  else{
    if(!(*root)->left){
      *root=(*root)->right;
      return;
    }
    else if(!(*root)->right){
      *root=(*root)->left;
      return;
    }
    else{
      temp=(*root)->left;
      while(temp->right){
        temp=temp->right;
      }
      (*root)->data=temp->data;
      deleteBST(&temp,temp->data);
    }
  }
}
