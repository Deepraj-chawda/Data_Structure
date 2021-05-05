#include<iostream>
using namespace  std;
#define N 8

void count_sort(int a[],int n,int pos){
  int count[10]={0};
  int b[n];

  for(int i=0;i<n;i++)
  ++count[(a[i]/pos)%10];

  for(int i=1;i<10;i++)
  count[i]=count[i]+count[i-1];

  for(int i=n-1;i>=0;i--)
  b[--count[(a[i]/pos)%10]]=a[i];

  for(int i=0;i<n;i++)
  a[i]=b[i];

  }


void radix_sort(int a[],int n,int l)
{
    int max=l;
    for( int pos=1;max/pos >0;pos=pos*10)
    {
        count_sort(a,n,pos);
    }
}
int main(){
    int a[N];
    cout<<"Enter the elements";
    for(int i=0;i<N;i++)
    cin>>a[i];
     
      int large=a[0]; //find largest one
  for(int i=1;i<N;i++)
  {
      if (a[i]>large)
      large=a[i];    
  }
     
       radix_sort(a,N,large);
     cout<<"radix sort :";
    for(int i=0;i<N;i++)
    cout<<" "<<a[i];

    return 0;
}