#include <iostream>
using namespace std;
#define N 5

int main(){
    int a[N],s;
    cout<<"Enter "<<N<<" elments : \n";
    for(int i=0;i<N;i++)
    cin>>a[i];

    cout<<"Enter element to be searched : ";
    cin>>s;

    for(int i=0;i<N;i++){
        if(a[i]==s){
            cout<<"Element found at "<<i+1<<" position";
            break;
        }
        if(i==N-1)
        cout<<"Element  not found";
    }

    return 0;
}