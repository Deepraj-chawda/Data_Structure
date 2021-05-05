#include<iostream>
using namespace std;
class Node{
public :
 int data;
 class Node *next;
};
class Stack{
  class Node *top;
  public :
  Stack(){
  top=NULL;
  }
  void push(int n){

      class Node *newnode=new Node();
      newnode->data=n;
      newnode->next=top;
      top=newnode;
       }

  void pop(){
  if(top==NULL)
  cout<<"uderflow";
  else{
      cout<<top->data;
      class Node *tem=top;
     top=top->next ;
     delete tem;
     }
  }

   int peek(){
  if (top==NULL) {
  cout<<"stack is empty!!!";
  return 0;     }
  else
  return top->data;
  }

 bool isEmpty(){
	   if(top==NULL)
	   return true;
	   else
	   return false;
   }
   void display(){
    class Node* temp=top;
    while(temp!=NULL){
     cout<<temp->data<<"    ";
     temp=temp->next;
    }
   }
    ~Stack(){
     class Node *tm=top;
     class Node *del=top->next;
     while(del!=NULL){
       delete tm;
       tm=del;
       del=del->next;
     }
     delete tm;
    }

};
int main()
{     
	int a,n;
	Stack obj;
	do{
    cout<<"\n\n1. For PUSH ";
	cout<<"\n2. For POP ";
	cout<<"\n3. For DISPLAY";
	cout<<"\n4. For PEEK";
	cout<<"\n5. For ISEMPTY";
	cout<<"\n6. For EXIT";
	cout<<"\n\nEnter your choice : ";
	cin >>a;
	switch (a){
	 case 1:
	 cout<<"Enter Element : ";
	 cin>>n;
	 obj.push(n);
	 break;

	 case 2:
	 obj.pop();
	 break;

	 case 3:
	 obj.display();
	 break;

	 case 4:
	cout<< obj.peek();
	break;

    case 5:
	cout<< obj.isEmpty();
	break;

	}
	}while(a<6);
		

      return 0;
}