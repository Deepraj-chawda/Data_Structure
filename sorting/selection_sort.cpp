#include<iostream>
using namespace std;
#define N 5
int main(){

    int a[N];
    cout<<"enter elements : \n";
     for(int i=0;i<N;i++)
     cin>>a[i];
     for (int i=0;i<N-1;i++){
         int min=i;
         for(int j=i+1;j<N;j++){
             if(a[j]<a[min])
             min=j;
         }
         if(min!=i){
             int temp=a[i];
             a[i]=a[min];
             a[min]=temp;
         }
    }
    cout<<"selection sort :";
    for(int i=0;i<N;i++)
    cout<<a[i]<<"  ";

    return 0;
}