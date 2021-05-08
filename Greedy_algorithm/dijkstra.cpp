#include<iostream>
using namespace std;
#define N 10


int minimum(int visit[],int distance[],int v){
    int min_vertex, min = INT16_MAX;

    for(int i = 1;i<=v;i++){
        
        if( visit[i] == 0 && distance[i] < min){
            min_vertex = i;
            min = distance[i];
        }
    }

    return min_vertex;

}


void dijkstra(int graph[][N],int v){

  
    int visit[v+1] = {0};
    int distance[v+1];
    int parent[v+1] ={0};

    //set all values to infinite
    for(int i=1;i<=v;i++)
        distance[i] = INT16_MAX;

    int vertex, mst = 0;
    cout<<"\nEnter source vertex : ";
    cin>>vertex;

    distance[vertex] = 0;
    

    for(int i= 1;i<=v-1;i++){

        int u = minimum(visit,distance,v);
        visit[u] = 1;

        for(int j=1;j<=v;j++){
            
          if(visit[j]==0 && graph[u][j] != 0 && distance[u] != INT16_MAX 
                && distance[u]+graph[u][j]< distance[j]){
             
             distance[j] = distance[u] + graph[u][j];
             parent[j] = u;
            

            }
        }
    }

    for(int i=1;i<=v;i++){
      
        cout<<"\nDistance of "<<i<<" from source : "<<distance[i];
    }


}

int main(){

    int graph[N][N]={0},v,edge;
     
    cout<<"Enter the no. of vertices : ";
    cin>>v;
  
    cout<<"Enter the no. of edges : ";
    cin>>edge;
    
    cout<<"Enter "<<edge<<" edges and their weight :\n ex :->edge weight : 1 2 5  \n";
    
    int e1,e2,w;
    for(int i=1;i<=edge;i++){
        cout<<"Edge Weight : ";
        cin>>e1>>e2>>w;
        graph[e1][e2]=w;
        graph[e2][e1]=w;
    }

 
  dijkstra(graph,v);

    return 0;
}