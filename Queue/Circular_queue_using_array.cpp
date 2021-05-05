#include<iostream>
using namespace std;
#define N 5
class Queue{
  int front,rear,q[N];
  public :
  Queue(){
  front=rear=-1;
  }

   void enqueue(int n){
    if(((rear+1)%N)==front){ //if((front==0&&rear==N-1)||front==rear+1)
     cout<<"overflow";
    }
    else {
     if(front==-1){
      front=rear=0;
      }
    else{
     rear=(rear+1)%N;
    }
    q[rear]=n;
   }
  }
  int dequeue(){
    if(front==-1){
    cout<<"underflow";
    return 0;
    }
   else {
       int a=q[front];
       if(front==rear){
	front=rear=-1;
       }
       else{
	front=(front+1)%N;
       }

      return a;
   }

  }

  void display(){
   if(front==-1&&rear==-1){
     cout<<"Queue is Empty";
   }
   else{
    int i;
    for(i=front;i!=rear;i=(i+1)%5){
     cout<<" "<<q[i];
    }
    cout<<" "<<q[i];
   }
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