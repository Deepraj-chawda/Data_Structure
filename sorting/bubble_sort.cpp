#include<iostream>
using namespace std;
#define N 5
int main(){
 int a[N],count;
 cout<<"Enter elemnts";
 for(int i=0;i<N;i++)
 cin>>a[i];

for(int i=0;i<N-1;i++){
    count=0;
    for(int j=0;j<N-1-i;j++){
        if(a[j]>a[j+1]){
            int tem=a[j];
            a[j]=a[j+1];
            a[j+1]=tem;
            count++;
        }
    }
    if(count==0)
    break;
}
cout<<"sorted : " ;
for(int i=0;i<N;i++)
cout<<a[i]<<"  ";
return 0;

}