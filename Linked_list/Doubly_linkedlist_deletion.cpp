#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    class Node *next;
    class Node *prev;
};

class Doubly_LL{
    public: 
    class Node *head;
    class Node *tail;
    
    Doubly_LL(){
        head=tail=NULL;
    }

    void create(){
           class Node *newnode=new Node();
           cout<<"\nEnter data : ";
           cin>>newnode->data;

           newnode->next=NULL;
           if(head==NULL){
               head=tail=newnode;
               newnode->prev=NULL;
           }
           else{
               tail->next=newnode;
               newnode->prev=tail;
               tail=newnode;
           }
    }

    void display(){
        class Node *temp=head;
        cout<<"\nDoubly linked list : \n";
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    }

    ~Doubly_LL(){
     class Node *del=head;
      for(Node *tem=head->next;tem!=NULL;tem=tem->next){
     delete del;
     del=tem;
     }
     delete del;
    }

int del_pos(int p){
        class Node *temp=head;
        int i=1;
        while(i<p){
            temp=temp->next;
            if(temp==NULL){
                cout<<"Invalid position";
                return 0;
            }
            i++;
        }
        if(temp->prev==NULL){
            head=temp->next;
            temp->next->prev=NULL;
        }
        else if(temp->next==NULL){
            temp->prev->next=NULL;
        }else
       {        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
       }
        delete temp;

        return 0;
    }

};
int main(){
    Doubly_LL obj;
    int n,p;
    cout<<"Enter the no. of nodes : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    obj.create();

    obj.display();
    
   cout<<"\nEnter the position : ";
    cin>>p;
    obj.del_pos(p);
    obj.display();
 return 0;    
    }