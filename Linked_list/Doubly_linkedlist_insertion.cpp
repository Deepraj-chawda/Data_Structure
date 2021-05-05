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

void beg(int d){
        class Node *newnode=new Node();
        newnode->data=d;

        newnode->prev=NULL;
        if(head==NULL)
        {
            newnode->next=NULL;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
        }
        head=newnode;
    }
    
int position(int p){
        int i=1;
        class Node *tem=head;
        while(i<p-1){
        tem=tem->next;
        if(tem==NULL){
        cout<<"\nInvaild position";
        return 0;
           }
        i++;
        }
           
      class Node *newnode=new Node();
          cout<<"\nEnter data : ";
          cin>>newnode->data;

          if(p==1)
          beg(newnode->data);
          else{
              newnode->prev=tem;
              newnode->next=tem->next;
              tem->next=newnode;
              tem->next->prev=newnode;
          }

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
    obj.position(p);
    obj.display();
 return 0;    
    }