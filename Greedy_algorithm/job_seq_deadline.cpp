#include<iostream>
using namespace std;
#define N 10


void sort(int jobs[][2],int job){

        for(int i=0;i<job-1;i++){
            int count=0;
            for(int j=0;j<job-1-i;j++){
                if(jobs[j][0] < jobs[j+1][0]){
                    int profit = jobs[j][0];
                    int deadline = jobs[j][1];

                    jobs[j][0] = jobs[j+1][0];
                    jobs[j][1] = jobs[j+1][1];
                    
                    jobs[j+1][0] = profit;
                    jobs[j+1][1] = deadline;
                
                    count++;
                }
            }
            if(count == 0)
            break;
        }

}

int main(){

        int jobs[N][2],job,max_profit=0,max_deadline=0;

        cout<<"Enter the number of Jobs : ";
        cin>>job;
        
        cout<<"Enter "<<job <<" jobs : Profit Deadline \n";
        for(int i = 0 ; i < job; i++){
            cout<<"Profit Deadline : ";
            cin>>jobs[i][0]>>jobs[i][1];

            if(jobs[i][1] > max_deadline)
                max_deadline = jobs[i][1];
        }

        sort(jobs,job);

        for(int i = 0 ; i < job; i++){
            for(int j = 0 ; j < 2; j++){
                cout<<jobs[i][j]<<"  ";
            }
            cout<<"\n";
        }
        
        int job_seq[max_deadline] = {0};

        for(int i = 0; i < job ;i++){
            for(int j = jobs[i][1]-1 ;j >= 0; j--){
                
                if (job_seq[j] == 0){
                    job_seq[j] = jobs[i][0];
                    max_profit += jobs[i][0];
                    break;
                }
            }
        }
        cout<<"Maximun profit : "<<max_profit<<"\n";
        cout<<"sequencing jobs are : ";
        for(int i = 0;i<max_deadline;i++)
        cout<<job_seq[i]<<"  ";
    return 0;
}