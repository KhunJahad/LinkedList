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

int get_size(Node *head){
    Node *temp=head;
    int sz=0;
    while(temp!=NULL){
        temp=temp->next;
        sz++;
    }
    return sz;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    int n=get_size(head1);
    int m=get_size(head2);
    
    int d=abs(n-m);
    Node *temp1=head1;
    if (n<m){
        head1=head2;
        head2=temp1;
    }
    temp1=head1; // bigger one
    while(d--){
        temp1=temp1->next;
    }
    Node *temp2=head2;
    // now just loop untill we get a match 
    while(temp1!=NULL && temp2!=NULL){
        if (temp1==temp2) return temp1->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}