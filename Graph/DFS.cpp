#include<iostream>
using namespace  std;
#define N 10

class Stack{
  int top;
  int s[5];
  public :
  Stack(){
   top=-1;
    }
  void push(int n){
	  if(top==4)
	  cout<<"overflow";
	  else{
	  top=top+1;
	  s[top]=n;
	  }
  }
  int pop(){
	 if(top==-1) {//IF(TOP<0)
	 cout<<"underflow";
	      return 0;
	      }
	      else{
	      int n=s[top];
	      top=top-1;
	      return n;}
  }
  int isEmpty(){
      if(top<0)
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
  void dfs(int adj_matrix[][N],int visit[],int v){
      int n;
    cout<<"Enter the initial vertex to start the DFS traversal with : ";
    cin>>n;
    Stack s;
    s.push(n);
    visit[n]=1;
     cout<<"\n The DFS traversal is : ";

         while(!s.isEmpty()){
          int a=s.pop();
        
          cout<<a<<"  ";

              for(int j=1;j<=v;j++){
                if(adj_matrix[a][j]==1 && visit[j]==0){
                    s.push(j);
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
    
    dfs(adj_matrix,visit,v);
    
    return 0;
}