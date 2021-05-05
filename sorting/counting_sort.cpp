#include<iostream>
using namespace std;
#define N 8
void counting_sort(int a[],int n,int l){
    int count[l+1]={0};
    int b[n];

    for(int i=0;i<n;i++)
    ++count[a[i]];

    for(int i=1;i<=l;i++)
    count[i]=count[i]+count[i-1];

    for(int i=n-1;i>=0;i--)
    b[--count[a[i]]]=a[i];
      
      //copy array 
    for(int i=0;i<n;i++)
    a[i]=b[i];  
}
int main(){
    int a[N];
    cout<<"Enter elements : "<<endl;
  for(int i=0;i<N;i++)
  cin>>a[i];
    
   
    int large=a[0]; //find largest one
  for(int i=1;i<N;i++)
  {
      if (a[i]>large)
      large=a[i];    
  }
    
    counting_sort(a,N,large);
  cout<<"Counting sort : ";
  for(int i=0;i<N;i++)
  cout<<a[i]<<"  ";

}
