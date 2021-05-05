#include<iostream>
using namespace std;

int main(){

    int a[50],n,min,max;
    cout<<"Enter the no. of elements in array : ";
    cin>>n;
    cout<<"\nEnter the "<<n<<" elements :\n";

    for(int i=0;i<n;i++)
    cin>>a[i];


    cout<<"\n Elements are : ";
    for (int i=0;i<n;i++)
    cout<<a[i]<<"  ";

    max=min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
        max=a[i];
        else if(a[i]<min)
        min=a[i];
    }
    cout<<"\nMaximum element is : "<<max;
    cout<<"\nMinimum element is : "<< min;
    return 0;
}