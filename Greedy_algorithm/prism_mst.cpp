#include<iostream>
using namespace std;
#define N 10


int minimum(int visit[],int path_weight[],int v){
    int min_vertex, min = INT16_MAX;

    for(int i = 1;i<=v;i++){
        
        if( visit[i] == 0 && path_weight[i] < min){
            min_vertex = i;
            min = path_weight[i];
        }
    }

    return min_vertex;

}
void prism(int graph[][N],int v){

    int MST[v+1][v+1] = {0};
    int visit[v+1] = {0};
    int path_weight[v+1];
    int parent[v+1] ={0};

    //set all values to infinite
    for(int i=1;i<=v;i++)
        path_weight[i] = INT16_MAX;

    int vertex, mst = 0;
    cout<<"\nEnter initial vertex : ";
    cin>>vertex;

    path_weight[vertex] = 0;
    

    for(int i= 1;i<=v-1;i++){

        int u = minimum(visit,path_weight,v);
        visit[u] = 1;

        for(int j=1;j<=v;j++){
            
          if(visit[j]==0 && graph[u][j] != 0 && graph[u][j]<path_weight[j]){
             cout<<graph[u][j]<<" "<<path_weight[j]<<" "<<j<<endl;
             path_weight[j] = graph[u][j];
             parent[j] = u;
            

            }
        }
    }

    for(int i=1;i<=v;i++){
        MST[parent[i]][i] = graph[parent[i]][i];
        mst += graph[parent[i]][i];
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

 
    prism(graph,v);

    return 0;
}