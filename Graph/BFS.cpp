#include<iostream>
using namespace  std;
#define N 10


class Queue{
  int front,rear,q[N];
  public :
  Queue(){
   front=rear=-1;
  }
  void enqueue(int n){
  if(rear==N-1){  //if(rear==max-1)
  cout<<"OVERFLOW";
  }
  else{
  rear=rear+1;
  q[rear]=n;
  if(front==-1)
  front=front+1;
  }

  }

  int dequeue(){
  if(front<0){
  cout<<"underflow";
  return 0;

  }
  else {
   int a=q[front];
   if(rear==front)
   front=rear=-1;
   else
   front=front+1;
   return a;
  }
  }
  int isEmpty(){
      if(front<0&&rear<0)
       return 1;
       else
         return 0;
       
  }
};


void graph(int adj_matrix[][N],int visit[],int v,int edge){
    int x,y;
   
    cout<<"Enter "<<edge<<" edges : ex :-> 1 2  \n";
    
    for(int i=1;i<=edge;i++){
          cout<<"Edge : ";
          cin>>x>>y;
          adj_matrix[x][y] = 1;
    }

}
void bfs(int adj_matrix[][N],int visit[],int v){
    int n;
    cout<<"Enter the initial vertex to start the BFS traversal with : ";
    cin>>n;
  Queue q;
  q.enqueue(n);
  visit[n]=1;    
  cout<<"\n The BFS traversal is : ";

      while(!q.isEmpty()){
          int a=q.dequeue();
        
          cout<<a<<"  ";

              for(int j=1;j<=v;j++){
                if(adj_matrix[a][j]==1 && visit[j]==0){
                    q.enqueue(j);
                    visit[j]=1;
                }     
                }
            

      }
}
int main(){

    int adj_matrix[N][N]={ {0} }, visit[N]={0},v,edge;

    cout<<"Enter the no. of vertices : ";
    cin>>v;
    
    cout<<"Enter the no. of edges : ";
    cin>>edge;
    
    graph(adj_matrix,visit,v,edge);
    
    bfs(adj_matrix,visit,v);
    
    return 0;
}