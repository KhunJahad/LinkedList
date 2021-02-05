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
	Node *next;
	Node (int x){
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

Node *reverselist(Node *head,int k){
	Node *current=head;
	Node *previous=NULL;
	Node *next=NULL;
	int count=0;
	while (count<k && current!=NULL){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;
		count++;
	}

	if (current!=NULL) head->next=reverselist(current,k);
	return previous;

}

int main(){
	read_input();
	int n,k;
	cin>>n>>k;
	ll l;
	cin>>l;
	Node *head=NULL,*tail=NULL;
	head= new Node(l);
	tail=head;

	for (int i=1;i<n;i++){
		cin>>l;
		tail->next=new Node(l);
		tail=tail->next;
	}
	printlist(head);
	head=reverselist(head,k);
	printlist(head);
	return 0;
}


