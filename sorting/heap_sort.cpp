#include<iostream>
using namespace std;
#define N 8
 void max_heapify(int a[],int n,int i){
     int largest=i;
     int left=(2*i)+1;
     int right=(2*i)+2;

     if(left<n && a[left]>a[largest])
     largest=left;
     if(right<n && a[right]>a[largest])
     largest=right;

     if(largest!=i){
         int temp=a[i];
         a[i]=a[largest];
         a[largest]=temp;

         max_heapify(a,n,largest);
     }
 }

    void heapsort(int a[],int n){
        //build heap
        for(int i=n/2-1;i>=0;i--)
        max_heapify(a,n,i);
         
         //one by one delete element from heap
        for(int i=n-1;i>0;i--){
            int temp=a[0];
            a[0]=a[i];
            a[i]=temp;

            max_heapify(a,i,0);
        }
    } 

 


int main(){

    int a[N];
    cout<<"Enter the elements";
    for(int i=0;i<N;i++)
    cin>>a[i];
     
     heapsort(a,N);

   cout<<"Heap sort : ";    
    for(int i=0;i<N;i++)
    cout<<" "<<a[i];

    return 0;
}