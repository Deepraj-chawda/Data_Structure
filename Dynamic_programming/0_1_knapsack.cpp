#include<iostream>
using namespace std;
#define N 10


int max(int a, int b)
    {
    return (a > b) ? a : b;
    }


int knapsack(int objects[][2], int n,int Weight){
    
    int knap[n+1][Weight+1];

    for(int i = 0;i<=n;i++){

        for(int w=0;w<=Weight;w++){
            if ((i == 0) || (w == 0))
                knap[i][w] = 0;
            else if((w-objects[i-1][1]) < 0){
                knap[i][w] = knap[i-1][w];
            }

            else{
          
           knap[i][w] = max(knap[i-1][w],knap[i-1][w-objects[i-1][1]] + objects[i-1][0]);
            }
        }


    }
    for(int i = 0;i<=n;i++){

        for(int w=0;w<=Weight;w++){
            cout<<knap[i][w]<<"  ";
        }
        cout<<"\n";

    }

    return knap[n][Weight];

}
int main(){
    
    int objects[N][2],no_of_obj,Knapsack_weight;

    cout<<"Enter the number of objects : ";
    cin>>no_of_obj;

    cout<<"Enter the Knapsack weight or Capacity : ";
    cin>>Knapsack_weight;

    cout<<"Enter "<<no_of_obj<<" : profit weight \n";
    for(int i = 0;i<no_of_obj;i++){
        cout<<"Profit Weight : ";
        cin>>objects[i][0]>>objects[i][1];
    }

    int max_profit = knapsack(objects,no_of_obj,Knapsack_weight);

    cout<<"\nMaximun profit : "<<max_profit;




    return 0;
}