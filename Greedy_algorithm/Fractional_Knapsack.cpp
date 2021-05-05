#include<iostream>
using namespace std;
#define N 10


void sort (float objects[][3],int obj){
    for(int i=0;i<obj-1;i++){
        int count=0;
        for(int j=0;j<obj-1-i;j++){
            if(objects[j][0]<objects[j+1][0]){
                float ratio = objects[j][0];
                int profit = objects[j][1];
                int weight = objects[j][2];

                objects[j][0] =  objects[j+1][0];
                objects[j][1] =  objects[j+1][1];
                objects[j][2] =  objects[j+1][2];
                
                objects[j+1][0] = ratio;
                objects[j+1][1] = profit;
                objects[j+1][2] = weight;
                
                count++;
            }
        }
        if(count==0)
        break;
    }
}

int main(){

    float objects[N][3], profit = 0;
    int p,w,weight,obj;

    cout<<"Enter the Total number of objets : ";
    cin>>obj;

    cout<<"Enter the Total Weight of bag : ";
    cin>>weight;

    cout<<"Enter "<<obj<<" objects : profit weight \n";
    
    for(int i = 0; i < obj ; i++){
        cout<<"profit weight : ";
        cin>>p>>w;
        objects[i][0] = p/(1.0*w);
        objects[i][1] = p;
        objects[i][2] = w;
    }
    


    sort(objects,obj) ;
    for(int i = 0;i < obj;i++){
        
        if(objects[i][2] <= weight ){
            profit += objects[i][1];
            weight -= objects[i][2];
        }
        else{
            profit += (weight/objects[i][2])*objects[i][1];
            break;
        }
    }
    

    cout<<"Maximum Profit Gain : "<<profit;

    return 0;
}