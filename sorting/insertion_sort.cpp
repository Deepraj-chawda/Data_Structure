#include<iostream>
using namespace std;
#define N 5
int main(){
  int a[N],temp,j;
  cout<<"Enter "<<N<<" elements : "<<endl;
  for(int i=0;i<N;i++)
  cin>>a[i];

  for(int i=1;i<N;i++){
      temp=a[i];
      for(j=i-1;j>=0&&a[j]>temp;j--){
         a[j+1]=a[j];
      }
      a[j+1]=temp;
  }

cout<<"Insertion sort :  ";
for(int i=0;i<N;i++)
cout<<a[i]<<"  ";

    return 0;
}