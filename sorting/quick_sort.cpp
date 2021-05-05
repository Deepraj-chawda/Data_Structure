#include<iostream>
using namespace std;
#define N 10
int partition(int a[],int lb,int ub){
   int pivot=a[lb];
   int start=lb; //or left=lb;
   int end=ub;  //or right=ub;
     while(start<end)
     {
    while(a[start]<=pivot)
    start++;
       
    while(a[end]>pivot)  
    end--;
     
     if(start<end){
        int tem=a[start];
        a[start]=a[end];
        a[end]=tem;
     }
   } 
         int tem=a[end];
         a[end]=a[lb]; //or pivot
         a[lb]=tem;

     return end;
} 
void Quick_sort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        Quick_sort(a,lb,loc-1);
        Quick_sort(a,loc+1,ub);
    }
}
int main(){
    int a[N];
    cout<<"Enter the elements";
    for(int i=0;i<N;i++)
    cin>>a[i];
     
     Quick_sort(a,0,N-1);

     cout<<"Quick sort :";
    for(int i=0;i<N;i++)
    cout<<" "<<a[i];

    return 0;
}