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
void preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }

}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}
int main(){
 class Node* root=NULL;
 root=create();
 cout<<"\nPre-order is : ";
 preorder(root);
 cout<<"\nIn-order is : ";
 inorder(root);
 cout<<"\nPost-order is : ";
 postorder(root);
    return 0;
}