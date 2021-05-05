#include<iostream.h>
#include<conio.h>
class Node {
public :
  int data;
  Node *next;

};
class Queue{
  Node *front;
  Node *rear;
  public :
  Queue(){
   front=rear=NULL;
  }
 void enqueue(int n){
       Node *newnode=new Node();
       newnode->data=n;
	if(rear==NULL){
	    rear=front=newnode;

	}
	else{
	 rear->next=newnode;
	 rear=newnode;

	 }
	  rear->next=front;
	}

    int dequeue(){
      if(front==NULL){
       cout<<"underflow";
       return NULL;
      }
      else{
	int a=front->data;
	Node *tem=front;
       if(front==rear){
	front=rear=NULL;
       }
       else{
	front=front->next;
	rear->next=front;
	  }
	 delete tem;
	 return a;
       }
     }

     void display(){
      if(front==NULL&&rear==NULL){
       cout<<"Queue is Empty !!!!";
      }
      else{
	 for(Node* i=front;i!=rear;i=i->next){
       cout<<" " <<i->data;
      }
      cout<<" "<<i->data;
     }
    }

	   ~Queue(){
     class Node* del=front;
      for(Node* tem=front->next;tem!=front;tem=tem->next){
     delete del;
     del=tem;
     }
     delete del;
    }

  };

void main()
{      clrscr();
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
	   clrscr();
	   goto g;
	    }

       getch();
}