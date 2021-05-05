#include<iostream>
using namespace std;
#define N 10


 
 
 void min_heapify(int files[],int file,int i){
     int smallest=i;
     int left=(2*i)+1;
     int right=(2*i)+2;

     if(left<file && files[left] < files[smallest])
        smallest = left;
     if(right<file && files[right] < files[smallest])
        smallest = right;

     if(smallest != i){
         int temp=files[i];
         files[i] = files[smallest];
         files[smallest] = temp;

         min_heapify(files,file,smallest);
     }
 }

void insert(int files[],int file, int value){
     files[file] = value;
     int i = file;

     while(i > 0){
         int parent = i/2;

         if(files[parent] > files[i]){
             int temp = files[parent];
             files[parent] = files[i];
             files[i] = temp;

             i = parent; 
         }
         else{
             break;
         }
     }

}

int main(){

    int files[N],file,length=0;
    
    cout<<"Enter the number of files : ";
    cin>>file;

    cout<<"Enter "<<file<<" files :\n";
    for(int i = 0;i < file; i++ ){
        cout<<"file "<<i+1<<" : ";
        cin>>files[i];
    }

    for(int i= file/2-1; i >= 0;i--)
        min_heapify(files,file,i);
         

    while (file > 1){
        int sum = 0;
        for(int i =0;i <2;i++){
            sum += files[0];
            file -= 1;
     
            files[0] = files[file];
            
            min_heapify(files,file,0);
             
        }

        length += sum;

        insert(files,file,sum);
        file += 1;
        
    }

    cout<<"\nExternal or weighted path length : "<<length<<"\n";
    
    //for(int i =0;i<file;i++)
    //cout<<"Top element : "<<files[i]<<" ";

    return 0;
}