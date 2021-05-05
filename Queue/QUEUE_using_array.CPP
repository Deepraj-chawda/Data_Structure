#include<iostream.h>
#include<conio.h>

class Queue{
  int front,rear,q[5];
  public :
  Queue(){
   front=rear=-1;
  }
  void enqueue(int n){
  if(rear==4){  //if(rear==max-1)
  cout<<"OVERFLOW";
  }
  else{
  rear=rear+1;
  q[rear]=n;
  if(front==-1)
  front=front+1;
  }

  }

  int dequeue(){
  if(front<0){
  cout<<"underflow";
  return NULL;

  }
  else {
   int a=q[front];
   if(rear==front)
   front=rear=-1;
   else
   front=front+1;
   return a;
  }
  }
  void display(){
  cout<<"\nQueue is :\n";
   for(int i=front;i<=rear;i++)
   cout<<"  "<<q[i];
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