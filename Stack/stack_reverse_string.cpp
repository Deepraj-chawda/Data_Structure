#include<iostream>
using namespace std;
#define N 50

int top=-1;
char stack[N];
void push(int d){
     if(top==N-1)
	  cout<<"overflow";
	  else{
          stack[++top]=d;
      }
}
char pop(){
    return stack[top--];
}

int main(){
      string st;
     cout<<"Enter string : ";
     cin>>st;
  int l=st.length();
  
  for(int i=0;i<l;i++)
      push(st[i]);

  for(int i=0;i<l;i++)
  cout<<pop();

    return 0;
}