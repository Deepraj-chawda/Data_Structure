#include<iostream>
using namespace std;
#define N 26

class Node {
    public:
    char data;
    int freq;
    Node *left;
    Node *right;
    
    void set(char d, int f) {
      
        this->data = d;
        this->freq = f;
        
        left = right = NULL;
        
    }
};


 void min_heapify(Node *newnode[],int n,int i){
     int smallest=i;
     int left=(2*i)+1;
     int right=(2*i)+2;

     if(left<n && newnode[left]->freq < newnode[smallest]->freq)
        smallest = left;
     if(right<n && newnode[right]->freq < newnode[smallest]->freq)
        smallest = right;

     if(smallest != i){
         Node *temp=newnode[i];
         newnode[i] = newnode[smallest];
         newnode[smallest] = temp;

         min_heapify(newnode,n,smallest);
     }
 }

void insert(Node *newnode[],int n, int freq,Node* left,Node* right){
    
     Node *newn = new Node();
     newn->set('#',freq);
     
     newn->left=left;
     newn->right=right;
     newnode[n]=newn;

     int i = n;

     while(i > 0){
         int parent = i/2;

         if(newnode[parent]->freq > newnode[i]->freq){
             Node *temp = newnode[parent];
             newnode[parent] = newnode[i];
             newnode[i] = temp;

             i = parent; 
         }
         else{
             break;
         }
     }
}

void print_huffman_code(Node* root,string s){
    
    if (root->left)
        print_huffman_code(root->left,s+"0");
    if(root->right)
        print_huffman_code(root->right,s+"1");
    if(!root->left && !root->right)
        cout<<root->data<<" : "<<s<<endl;
}

void huffman(int freq[],char ch[],int n){

    Node *newnode[n] ;

    for(int i =0;i<n;i++){
        Node *n = new Node();
        n->set(ch[i],freq[i]);
        newnode[i]=n;
    }
   
    for(int i= n/2-1; i >= 0;i--)
        min_heapify(newnode,n,i);


     int Total_bit = 0;

    while(n > 1){

        Node *left = newnode[0];
        n -= 1;
        newnode[0] = newnode[n];
        min_heapify(newnode,n,0);

        Node *right = newnode[0];
        n -= 1;
        newnode[0] = newnode[n];
        min_heapify(newnode,n,0);

        Total_bit += left->freq+right->freq;

        insert(newnode,n,left->freq+right->freq,left,right);
        n +=1;
        
    }
 
    Node *root = newnode[0];
    n -= 1;
   
    print_huffman_code(root,"");

    cout<<"\nTotal bits : "<<Total_bit;
     
}

int main(){

    int total_char,frequency[N];
    char character[N];

    cout<<"Enter the number of characters : ";
    cin>>total_char;

    cout<<"Enter "<<total_char<<" characters and their Frequency :\n";
    for(int i=0;i<total_char;i++){
        cout<<"character Frequency : ";
        cin>>character[i]>>frequency[i];        
    }

    huffman(frequency,character,total_char);
    return 0;
}