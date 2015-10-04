#include "SinglyLinkedList.h"
void main(){
  NODE *start;
  start=NULL;
  int no;
  Push(&start,10);
  Push(&start,20);
  Push(&start,30);
  Traverse(&start);
  Pop(&start,&no);
  printf("\n");
  Traverse(&start);
  Pop(&start,&no);
  printf("\n");
  Traverse(&start);
}
void Preorder(node *root) {
    STACK* tree;
    node* cur;
    tree=createStack();
    pushStack(tree,root);
    while(emptyStack(tree)){
        cur=stackTop(tree);
        printf("%d ",cur->data);
        popStack(tree);
        if(cur->right)
            pushStack(tree,(cur->right));
        if(cur->left)
            pushStack(tree,(cur->left));
        
    }
}