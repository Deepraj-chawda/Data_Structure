#include<iostream>
using namespace std;
#define N 10

void floyd_warshall(int graph[][N],int v){
    int dist[v][v];
    
    //copying values
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
        dist[i][j] = graph[i][j];
        }
    }

    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(dist[i][k] == INT32_MAX || dist[k][j] == INT32_MAX)
                    continue;
                else if (dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(dist[i][j] == INT32_MAX)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";

        }
        cout<<endl;
    }
}

int main(){

    int graph[N][N],vertex,edge;

    cout<<"Enter the no. of vertices : ";
    cin>>vertex;
  
    cout<<"Enter the no. of edges : ";
    cin>>edge;

    //initialising graph
    for(int i=1;i<=vertex;i++){
        for(int j=1;j<=vertex;j++){
            if (i==j)
                graph[i][j] = 0;
            else 
                graph[i][j] = INT32_MAX;
        }
    }

    cout<<"Enter "<<edge<<" edges and their weight :\n ex :->edge weight : 1 2 5  \n";
    
    int e1,e2,w;
    for(int i=1;i<=edge;i++){
        cout<<"Edge Weight : ";
        cin>>e1>>e2>>w;
        graph[e1][e2]=w;
        
    }

    floyd_warshall(graph,vertex);

    return 0;
}