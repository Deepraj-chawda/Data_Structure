#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    class Node *
    left,*right;
};
class Node* create(){
    int x;
    class Node *newnode=new Node();
    cout<<"Enter data (press -1 for no node) : ";
    cin>>x;
    if(x==-1)
    return NULL;

      newnode->data=x;
      cout<<"Enter left child of "<<x<<" : ";
      newnode->left=create();
      cout<<"Enter right child of "<<x<<" : ";
      newnode->right=create();

      return newnode;
}
int main(){
 class Node* root=NULL;
 root=create();

 return 0;
}