#include<iostream>
using namespace std;

 int a[50],size;
void display(int size){
    cout<<"\n Elements are : ";
    for (int i=0;i<size;i++)
    cout<<a[i]<<"  ";
}
void end(int data){
    if(size-1==50-1)
    cout<<"Array is overflow";
    else
    {
    
      a[size]=data;
      size++;
    }   
}
void beg(int data){
    if(size-1==50-1)
    cout<<"Array is overflow";
    else{
        size++;
        for(int i=size-1;i>=1;i--)
        a[i]=a[i-1];

        a[0]=data;
    }
}
void position(int data,int pos){
        if(size-1==50-1)
    cout<<"Array is overflow";
    else{
        size++;
        for(int i=size-1;i>=pos-1;i--)
        a[i+1]=a[i];

        a[pos-1]=data;
    }
}
int main(){

   int ch,c,n;
    cout<<"Enter the no. of elements(or size) in array : ";
    cin>>size;
    cout<<"\nEnter the "<<size<<" elements :\n";

    for(int i=0;i<size;i++)
    cin>>a[i];
   
  g:   cout<<"\n1. Insert at beginning";
     cout<<"\n2. Insert at End";
     cout<<"\n3. Insert at any position";
     cout<<"\n4. Display";
     cout<<"\nEnter your choice : ";
     cin>>ch;

     switch (ch)
     {
     case 1:
        cout<<"\nenter the element";
        cin>>n;
        beg(n);
         break;
     
     case 2:
        cout<<"\nenter the element";
        cin>>n;
        end(n);
         break;
      
      case 3:
     int p;
        cout<<"\nenter the element";
        cin>>n;
        cout<<"enter a position";
        cin>>p;
        position(n,p);
         break;
      
       case 4:
        display(size);
         break;

     default:
     cout<<"Invaild choice";    
     }

    cout<<"\npress 1 for continue : ";
    cin>>c;
    if(c==1)
    goto g;

    return 0;
}