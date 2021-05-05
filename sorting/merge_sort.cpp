#include <iostream>
using namespace std;
#define N 8
int b[N];
void merge(int a[],int lb,int mid,int ub){
      int i=lb;
       int j=mid+1;
        int k=lb;
    
        while(i<=mid && j<=ub)
        {
            if(a[i]<=a[j]){
            b[k]=a[i];
             i++;
            }
            else{
                b[k]=a[j];
                j++;
            }
            k++;
        }

          while(j<=ub){
              b[k]=a[j];
              j++;
              k++;
          }
        
            while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
            }
    

        for(int i=lb;i<=ub;i++)
        a[i]=b[i];
}
void Merge_sort(int a[],int lb, int ub){
    if(lb<ub){
        int mid =(lb+ub)/2;
        Merge_sort(a,lb,mid);
        Merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);

    }


}
int main(){
    int a[N];
    cout<<"Enter elements : "<<endl;
  for(int i=0;i<N;i++)
  cin>>a[i];

  Merge_sort(a,0,N);

  cout<<"Merge sort : ";
  for(int i=0;i<N;i++)
  cout<<a[i]<<"  ";

 return 0;
}