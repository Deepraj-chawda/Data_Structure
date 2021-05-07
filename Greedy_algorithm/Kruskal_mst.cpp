#include<iostream>
using namespace std;
#define N 50

void sort (int graph[][3],int edge){
    for(int i=1;i<=edge-1;i++){
        int count=0;
        for(int j=1;j<=edge-i;j++){
            if(graph[j][0] > graph[j+1][0]){
                int weight = graph[j][0];
                int e1 = graph[j][1];
                int e2 = graph[j][2];

                graph[j][0] =  graph[j+1][0];
                graph[j][1] =  graph[j+1][1];
                graph[j][2] =  graph[j+1][2];
                
                graph[j+1][0] = weight;
                graph[j+1][1] = e1;
                graph[j+1][2] = e2;
                
                count++;
            }
        }
        if(count==0)
        break;
    }
}

void kruskal(int graph[][3],int v,int edge){
    
    int MST[v+1][v+1] = {0};
    int mst = 0;
    int visit[v+1] = {0};

    int vertex = 0;

    for(int i=1;i<=edge;i++){
        if (vertex == v-1)
            break;
            
        int e1 = graph[i][1];
        int e2 = graph[i][2];
        if( (visit[e1] == 0) || (visit[e2] == 0) ){

            MST[e1][e2] = graph[i][0];
            visit[e1] = 1;
            visit[e2] = 1;

            mst += graph[i][0];
            vertex += 1;
        }
    }

    cout<<"\nMinimum cost of Minimum Spanning Tree : "<<mst<<endl;
    cout<<"Minimum Spanning Tree : \n";
    for(int i =1;i<=v;i++){
        for(int j =1 ;j<=v;j++){
            cout<<MST[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){

    int graph[N][3],v,edge;
     
    cout<<"Enter the no. of vertices : ";
    cin>>v;
  
    cout<<"Enter the no. of edges : ";
    cin>>edge;
    
    cout<<"Enter "<<edge<<" edges and their weight :\n ex :-> weight edge : 5 1 2  \n";
    
    for(int i=1;i<=edge;i++){
        cout<<"Weight edge : ";
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    }

    sort(graph,edge);

    kruskal(graph,v,edge);

    return 0;
}