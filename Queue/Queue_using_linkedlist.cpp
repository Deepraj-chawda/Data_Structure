#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
};
class Queue{
 public :
  Node *front;
  Node *rear;
  Queue(){
  front=rear=NULL;
  }
  void enqueue(int n){
    Node *newnode=new Node();
    newnode->data=n;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL)
    { front=rear=newnode;
    }
    else{
     rear->next=newnode;
     rear=newnode;
    }
  }

  int dequeue(){
   if(front==NULL)
   {
    cout<<"underflow";
    return 0;
   }
   else
   { int a=front->data;
    Node *tem=front;
     if(front==rear){
     front=rear=NULL;
     }
     else{
      front=front->next;
     }
     delete tem;
     return a;

   }

  }
   void display(){
    if(front==NULL&&rear==NULL)
    cout<<"Queue is Empty !!!";
    else{
    Node *temp=front;
    while(temp!=NULL){
    cout<<"  "<<temp->data;
    temp=temp->next;
    }
      }
   }

    ~Queue(){
     class Node* del=front;
      for(Node* tem=front->next;tem!=NULL;tem=tem->next){
     delete del;
     del=tem;
     }
     delete del;
    }


};
int main()
{     

	int a,n;
	Queue obj;
    g:  cout<<"1. For ENQUEUE";
	cout<<"\n2. For DEQUEUE";
	cout<<"\n3. For DISPLAY";

	cout<<"\n\nEnter your choice : ";
	cin >>a;
	switch (a){
	 case 1:
	 cout<<"Enter Element : ";
	 cin>>n;
	 obj.enqueue(n);
	 break;

	 case 2:
	cout<< obj.dequeue();
	 break;

	 case 3:
	 obj.display();
	 break;

	 default :
	 cout<<"INVALID CHOICE !!";

	}
		char ch;
	   cout<<"\nDo you want to continue ? (y or n) : ";
	   cin>>ch;
	   if(ch=='Y' ||ch=='y'){
	   goto g;
	    }

       return 0;
}