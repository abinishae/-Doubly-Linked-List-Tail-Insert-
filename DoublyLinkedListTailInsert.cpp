// Given a doubly linked list of size n, you need to insert an element data after the tail.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}
void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    cout<<endl;
    
    //Tail to Head
    while(head->prev)
    {
        cout<<head->data<<" ";
        head=head->prev;
    }
    cout<<head->data;
    
 }
Node *insertInTail(Node * h, int d)
{
   Node * t = new Node(d);
   if(! h->next)  { h->next = t; t->prev = h; return h;}
   Node * g = h;
   while(h->next){
       h = h->next;
   }
   h->next = t;
   t->prev = h;
   return g;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    int data;
	    cin>>data;
	    
	    head=insertInTail(head,data);
	    
	    displayList(head);
 
	    cout<<endl;
	}
	return 0;
}  
