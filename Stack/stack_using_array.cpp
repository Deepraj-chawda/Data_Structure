#include<iostream>
using namespace std;
#define N 5
class Stack{
  int top;
  int s[N];
  public :
  Stack(){
   top=-1;
  }
  void push(int n){
	  if(top==N-1)
	  cout<<"overflow";
	  else{
	  top=top+1;
	  s[top]=n;
	  }
  }
  int pop(){
	 if(top==-1) {//IF(TOP<0)
	 cout<<"underflow";
	      return 0;
	      }
	      else{
	      int n=s[top];
	      top=top-1;
	      return n;}
  }
  int peek(){
  if (top==-1) {
  cout<<"stack is empty!!!";
  return 0;     }
  else
  return s[top];
  }
   
   bool isEmpty(){
	   if(top==-1)
	   return true;
	   else
	   return false;
   }
  void display(){
    for(int i=0;i<=top;i++)
    cout<<s[i]<<"   ";
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
	cout<< obj.pop();
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