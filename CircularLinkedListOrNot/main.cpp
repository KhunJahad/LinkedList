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
bool isCircular(Node *head)
{
   // Your code here
   Node *slow=head;
   Node *fast=head;
   while(fast!=NULL && slow!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
       if (fast==slow) return true;
   }
   return false;
}