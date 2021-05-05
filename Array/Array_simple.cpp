#include<iostream>
using namespace std;

int main(){

    int a[50],n;
    cout<<"Enter the no. of elements in array : ";
    cin>>n;
    cout<<"\nEnter the "<<n<<" elements :\n";

    for(int i=0;i<n;i++)
    cin>>a[i];


    cout<<"\n Elements are : ";
    for (int i=0;i<n;i++)
    cout<<a[i]<<"  ";

    return 0;
}