# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zero=100;

void read_input(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

struct Node{
	int data;
	struct Node *next;

	Node(int x){
		data=x;
		next=NULL;
	}
};

void printlist(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

Node* reverse(Node *head){
    Node *current=head;
    Node *previous=NULL;
    Node *next=NULL;
    
    while(current!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    return previous;
}

int get_size(Node *head){
    Node *temp=head;
    int sz=0;
    while(temp!=NULL){
        temp=temp->next;
        sz++;
    }
    return sz;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    int n=get_size(first);
    int m=get_size(second);
    Node *temp1=first;
    // first will be always be greatest
    if (n<=m){
        first=second;
        second=temp1;
    }
    
    first=reverse(first);
    second=reverse(second);
    
    temp1=first;
    Node *temp2=second;
    int carry=0;
    Node *prev=NULL;
    while(temp2!=NULL){
        int x=(temp1->data+temp2->data+carry);
        temp1->data=x%10;
        carry=x/10;
        prev=temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    while(temp1!=NULL){
        int x=(temp1->data+carry);
        temp1->data=x%10;
        carry=x/10;
        prev=temp1;
        temp1=temp1->next;
    }
    
    if (carry!=0){
        prev->next=new Node(carry);
    }
    first=reverse(first);
    return first;
    
}