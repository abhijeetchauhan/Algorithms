#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int,long long int>
#define f first
#define s second
using namespace std;
map <string,string > codes;
struct node{
  ll freq;
  string data;
  struct node *left,*right;
};
string code="";
void getPrefixCodes(node *root){
  //cout << "I am here";
  if(root->left != NULL){
    code=code + "0";
    getPrefixCodes(root->left);
    code.pop_back();
  }
  //cout << "I am too";
  if(root->right != NULL){
    code=code + "1";
    getPrefixCodes(root->right);
    code.pop_back();
  }
  if(root->left==NULL && root->right==NULL){
    codes[root->data]=code;
    return;
  }
}
int main(){
  ll start_s=clock();
  ll size;
  scanf("%lld",&size);
  // camparison function that forms min heap according to the second element in the pair
  class comp{public:bool operator()(node *p1,node *p2){return p1->freq>p2->freq;}};
  priority_queue<node *,vector<node *>,comp> pq;
  for(ll i=1;i<=size;i++){
    node *temp=new node;string in;
    cin >> in;
    temp->data=in;
    scanf("%lld",&(temp->freq));
    temp->left=temp->right=NULL;
    pq.emplace(temp);
  }
  for(ll i=1;i<size;i++){
    node *add=new node;
    node *x,*y;
    //string name;
    //name=pq.top().first;
    x=pq.top();
    add->left=pq.top();pq.pop();
    y=pq.top();
    //name = name + pq.top().first;
    add->right=pq.top();pq.pop();
    add->freq=x->freq+y->freq;
    add->data=x->data+y->data;
    //cout << x->data << " " << y->data << endl;
    pq.emplace(add);
  }
  cout << (pq.top()->right)->data;
  printf("%lld\n",pq.top()->freq);
  node *root=pq.top();
  getPrefixCodes(root);
  for(map <string,string >::iterator it=codes.begin();it!=codes.end();it++){
    cout << it->f << " " << it->s << endl;
  }
  ll stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}