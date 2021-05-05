#include<iostream>
using namespace std;

int main()
{      int a[10][10],b[10][10],c[10][10];
     int r1,r2,c1,c2;
    cout<<"Enter the no. of row for 1st Matrix : ";
    cin>>r1;
    cout<<"Enter the no. of column for 1st Matrix : ";
    cin>>c1;
     cout<<"Enter the no. of row for 2nd Matrix : ";
    cin>>r2;
    cout<<"Enter the no. of column for 2nd Matrix : ";
    cin>>c2;
   cout<<"enter "<<r1*c1<<" elements of 1st matirx \n";
   for( int i=0;i<r1;i++)
     {     for(int j=0;j<c1;j++)
	      cin>>a[i][j];
     }

  cout<<"enter "<<r2*c2<<" elements of 2nd matirx \n";
     for(int i=0;i<r2;i++)
     {     for(int j=0;j<c2;j++)
	     cin>>b[i][j];
	 }
  
  if(r1==r2&&c1==c2){
      cout<<"Addition is \n";
	 for(int i=0;i<r1;i++)
	 {
	  for(int j=0;j<c1;j++){
	 c[i][j]=a[i][j]+b[i][j];
     cout<<c[i][j]<<"  ";
      }
     cout<<endl;
     	 }
	    }
    else
    {
        cout<<"Addition is not possible";
    }
    
	 
    return 0;

}