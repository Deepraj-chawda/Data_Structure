#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define N 26

class Node {
    public:
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

class Compare{
    public:
    bool operator()(Node *a,Node *b){
        return a->freq > b->freq;
    }

};


void print_huffman_code(Node* root,string s){

    if (root->left)
        print_huffman_code(root->left,s+"0");
    if(root->right)
        print_huffman_code(root->right,s+"1");
    if(!root->left && !root->right)
        cout<<root->data<<" : "<<s<<endl;
}

void huffman(int freq[],char ch[],int n){

    priority_queue<Node*,vector<Node*>,Compare> p_q;
    //make priority queue
    for(int i =0;i<n;i++){
        Node *newnode = new Node(ch[i],freq[i]);
        p_q.push(newnode);
    }
    
    int Total_bit = 0;

    while(p_q.size() > 1){

        Node *l = p_q.top();
        p_q.pop();

        Node *r = p_q.top();
        p_q.pop();

        Total_bit += l->freq+r->freq;

        Node *root = new Node('#',l->freq+r->freq);
        root->left = l;
        root->right = r;
        p_q.push(root);
    }

    Node *root = p_q.top();
    p_q.pop();
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