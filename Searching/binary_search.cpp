#include<iostream>
using namespace std;
#define N 10
int binary_search_iterative(int a[],int beg,int end,int data){
    //Iterative
   
    int mid;
    while(beg<=end){
     mid=(beg+end)/2;

     if(a[mid]==data)
     return mid;
     else if(data>a[mid])
     beg=mid+1;
     else
     end=mid-1;
    }
     return -1;
}

int binary_search_Recursive(int a[],int beg,int end,int data){
    //Recursive

    int mid;
    if(beg<=end){
     mid=(beg+end)/2;
   
     if(a[mid]==data)
     return mid;
    
     else if(data>a[mid])
     return binary_search_Recursive(a,mid+1,end,data);
    
     else
     return binary_search_Recursive(a,beg,mid-1,data);
    
    }
     return -1;
}
int main()
{     
 int a[N],tem,n;
 cout<<"Enter "<<N<<" elments : \n";
    for(int i=0;i<N;i++)
    cin>>a[i];

 for(int i=0;i<N;i++){
  for(int j=i+1;j<N;j++){
   if(a[i]>a[j]){
       tem=a[i];
       a[i]=a[j];
       a[j]=tem;
	 }
      }
   }
  for(int i=0;i<N;i++)
  cout<<a[i]<<"  ";
  cout<<"\nEnter element to be search : ";
  cin>>n;

  int result=binary_search_iterative(a,0,N-1,n);
  
   if(result==-1)
   cout<<"Element not found !!!";
   else
   cout<<"Element is at "<<result+1 <<" position using Iterative approach\n\n";



   result=binary_search_Recursive(a,0,N-1,n);
  
   if(result==-1)
   cout<<"Element not found !!!";
   else
   cout<<"Element is at "<<result+1 <<" position using Recursive approach";

  return 0;
}