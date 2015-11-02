#include <stdio.h>
#include <stdlib.h>
#define newNode (struct node*)malloc(sizeof(struct node))
struct node 
{
  int vertex;
  struct node *next;
};
typedef struct node NODE;
void readGraph(NODE *adjList[10],int n){
  int i,j;
  char reply[2];
  NODE *p,*c;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      // condition for self loops
      // if(i==j)
      //   continue;
      printf("\nVertices %d & %d are Adjacent ?(Y/N) :",i,j );
      fflush(stdout);
      scanf("%s",reply);
      if(reply[0]=='y' || reply[0]=='Y'){
        c=newNode;
        c->vertex=j;
        c->next=NULL;
        // when first adjacent edge is added
        if(adjList[i]==NULL){
          adjList[i]=c;
        }
        else{
          p=adjList[i];
          while(p->next!=NULL){
            p=p->next;
          }
          p->next=c;
        }
      }
    }
  } 
}
void undir_graph(){
  NODE *adjList[10],*p;
  int deg,i,j,n;
  printf("\nHow Many Vertices? : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    adjList[i]=NULL;
  }
  readGraph(adjList,n);
  printf("\n Vertex \t Degree ");
  for(i=1;i<=n;i++)
  {
    deg=0;
    p=adjList[i];
    while(p!=NULL){
      deg++;
      p=p->next;
    }
    printf("\n\n %5d \t\t %d\n\n",i,deg);
  }
}
void dir_graph()
{
    NODE *adj_list[10], *p;
    int n;
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    for( i = 1 ; i <= n ; i++ )
        adj_list[i] = NULL;
    readGraph(adj_list, n);
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
        p = adj_list[i];
        while( p != NULL )
        {
            out_deg++;
            p = p -> next;
        }
        for ( j = 1 ; j <= n ; j++ )
        {
            p = adj_list[j];
            while( p != NULL ) 
            {
                if ( p -> vertex == i )
                   in_deg++;
                p = p -> next;
            }
        }
        printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n", i, in_deg, out_deg, in_deg + out_deg);
    } 
    return;
}
void main()
{
    int option;
    do
    {
        printf("\n A Program to represent a Graph by using an Adjacency List \n ");
        printf("\n 1. Directed Graph ");
        printf("\n 2. Un-Directed Graph ");
        printf("\n 3. Exit ");
        printf("\n\n Select a proper option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1 : dir_graph();
                     break;
            case 2 : undir_graph();
                     break;
            case 3 : exit(0);
        }
    }while(1);
}
