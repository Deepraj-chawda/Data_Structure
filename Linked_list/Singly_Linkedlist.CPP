#include<iostream.h>
#include<conio.h>

class Node{
  public:
  int data;
  class Node* next;
    };

 class Linkedlist{
  public :
     class Node* head;
     class Node* ptr;
	    Linkedlist(){  head=NULL;
	    }
    void add(int n){
 class Node* mynode=new Node();
 mynode->data=n;
 if(head==NULL){
 mynode->next=NULL;
 head=mynode;
 ptr=mynode;

 }
 else{
     ptr->next=mynode;
     ptr=mynode;
     mynode->next=NULL;
 }
    }
    void display(){
      class Node* temp=head;
       if(head==NULL){
       cout<<"\nList is Empty\n"; }
       else{
       cout<<"\nlinklist is : \n\t";
      while(temp!=NULL){
       cout<<temp->data<<"\t";
       temp=temp->next;
      }
     }
    }
     ~Linkedlist(){
     class Node* del=head;
      for(Node* tem=head->next;tem!=NULL;tem=tem->next){
     delete del;
     del=tem;
     }
     delete del;
    }
    void addbeg(int n){

      class Node* mynode=new Node();
       mynode->data=n;

      mynode->next=head;
      head=mynode;
      }

      void addend(int n){

       class Node* mynode=new Node();
       mynode->data=n;
       mynode->next=NULL;
	class Node* tp=head;
       if(head==NULL)
       head=mynode;
       else {

      while(tp->next!=NULL){
       tp=tp->next;
      }
	 tp->next=mynode;
    }
      }

      int addatpos(int p,int d){

       class Node* prev;
       prev=head;
       for(int i=1;i<p-1;i++){
	prev=prev->next;
	if(prev==NULL){
       cout<<"\nNode in the list less than the Position "<<p;
       return(0);      }
       }
      class Node* mynode =new Node();
      mynode->data=d;
      mynode->next=prev->next;
      prev->next=mynode;

      }

      int del(int d){
       class Node* tm=head,*q;
       if(tm->data==d){
	head=tm->next;
	delete tm;
	cout<<"\ndeleted \n";
	return (0);
       }
       q=tm->next;
       while(tm->next!=NULL){
	     if(q->data==d){
	     tm->next=q->next;
	     delete q;
	     cout<<"\ndeleted \n";
	     return(0);
	     }
	tm=tm->next;
	q=tm->next;
	}
	cout<<"\nElement "<<d<<" is not found !! ";
      }
      int search(int d){

       int p=1;

       class Node* st=head;
       while(st!=NULL){
	if(st->data==d){
	 cout<<"\nElement "<<d<<" found at "<<p<<" position";
	 return (0);
	}
	st=st->next;
	p++;
       }
       if(st==NULL){
	cout<<"\nElement "<<d<<" is not found in list ";
       }
      }

};

void main()
{      clrscr();
int n,c,d;
	Linkedlist obj;
	 cout<<"create a list  \n enter no. of nodes : ";
	 cin>>n;
	 for(int i=0;i<n;i++){
	 cout<<"\nenter data ";
	 cin>>d;
	 obj.add(d);
	 }
	 cout<<"linklist created \n";
      g: cout<<"\t1. Insert element at begging\n";
	 cout<<"\t2. Insert element at end\n";
	 cout<<"\t3. Insert element at any position\n";
	 cout<<"\t4. delete element \n";
	 cout<<"\t5. Searching element \n";
	 cout<<"\t6. Display linklist \n";
	 cout<<"\n\tEnter your choice : ";
	 cin>>c;
	switch(c){
	 case 1:
	 cout<<"\nenter data :";
      int b;
      cin>>b;
	 obj.addbeg(b);
	 break;
	 case 2:
	 cout<<"\nenter data : ";
       int e;
       cin>>e;
	 obj.addend(e);
	 break;
	  case 3:
	  int pos,da;
       cout<<"\nEnter position : ";
       cin>>pos;
       cout<<"\nEnter data : ";
       cin>>da;
	  obj.addatpos(pos,da);
	  break;
	  case 4:
	    int de;
       cout<<"\nEnter data which you want to delete :";
       cin>>de;

	  obj.del(de);
	  break;
	  case 5:
	  int s;
	    cout<<"\nEnter the element to be search : ";
	  cin>>s;
	  obj.search(s);
	  break;
	  case 6:
	  obj.display();
	  break;
	  default :
	  cout<<"Invalid choice ";

	}
	char ch;
	   cout<<"\nDo you want to continue ? (y or n) : ";
	   cin>>ch;
	   if(ch=='Y' ||ch=='y'){
	   clrscr();
	   goto g;
	   }
       getch();
}