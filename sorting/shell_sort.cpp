#include<iostream>
using namespace std;
#define N 8


int main(){
    int a[N];
    cout<<"Enter elements : "<<endl;
  for(int i=0;i<N;i++)
  cin>>a[i];

 //shell sort logic
 for(int grap;grap>=1;grap=grap/2)
 {
     for(int j=grap;j<N;j++)
     {
        for(int i=j-grap;i>=0;i=i-grap)
         {
             if(a[i+grap]>a[i])
             break;
             else{
                 int tem=a[i];
                 a[i]=a[i+grap];
                 a[i+grap]=tem;
             }
         }
     }
 }

  cout<<"Shell sort : ";
  for(int i=0;i<N;i++)
  cout<<a[i]<<"  ";

 return 0;
}