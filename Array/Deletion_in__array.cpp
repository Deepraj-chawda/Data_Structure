#include<iostream>
using namespace std;
 int a[50],size;

 void display(int size){
 cout<<"\n Elements are : ";
    for (int i=0;i<size;i++)
    cout<<a[i]<<"  ";
 }
 void beg(){
     if(size-1==0)
     cout<<"Underflow";
     else{
         for(int i=0;i<size-1;i++)
         a[i]=a[i+1];

         size--;
     }
 }
 void end(){
     if(size-1==0)
     cout<<"Underflow";
     else{
         size--;
     }
 }

 void position(int p){
     if(size-1==0)
     cout<<"Underflow";
     else{
         for(int i=p-1;i<size;i++)
         a[i]=a[i+1];

         size--;
     }
 }
int main(){

     int c,ch;   
    cout<<"Enter the no. of elements(or size ) in array : ";
    cin>>size;
    cout<<"\nEnter the "<<size<<" elements :\n";

    for(int i=0;i<size;i++)
    cin>>a[i];

      g:   cout<<"\n1. Delete from beginning";
     cout<<"\n2. Delete from End";
     cout<<"\n3. Delete from any position";
     cout<<"\n4. Display";
     cout<<"\nEnter your choice : ";
     cin>>ch;

     switch (ch)
     {
     case 1:
        beg();
         break;
     
     case 2:
        end();
         break;
      
      case 3:
     int p;
        cout<<"enter a position";
        cin>>p;
        position(p);
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