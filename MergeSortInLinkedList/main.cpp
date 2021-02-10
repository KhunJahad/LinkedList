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


void splitList(Node *head,Node **ll1,Node **ll2){

	Node *slow=head;
	Node *fast=head->next;
	// find the split similar to floyd's tortoise 
	while(fast!=NULL){
		fast=fast->next;
		if (fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}

	*ll1=head; // head of the first
	*ll2=slow->next; // head of the second
	slow->next=NULL; // splitting first from the second
}

Node *mergeList(Node *ll1,Node *ll2){
	Node *newhead=NULL;

	if (ll1==NULL) return ll2;
	if (ll2==NULL) return ll1;

	if (ll1->data<=ll2->data){
		newhead=ll1;
		newhead->next=mergeList(ll1->next,ll2);
	}
	else{
		newhead=ll2;
		newhead->next=mergeList(ll1,ll2->next);
	}
	return newhead;
}

Node* mergesort(Node **head){
	Node *ll1,*ll2;
	Node *temp=*head;
	if (temp==NULL || temp->next==NULL) return *head;
	// base case when 0 or 1 elements
	splitList(temp,&ll1,&ll2);
	mergesort(&ll1);
	mergesort(&ll2);
	*head=mergeList(ll1,ll2);
	return *head;
}

int main(){
	read_input();
	int n;
	cin>>n;
	int temp;
	cin>>temp;
	Node *head,*tail;
	head=tail=new Node(temp);
    
	for(int i=1;i<n;i++){
		cin>>temp;
		tail->next=new Node(temp);
		tail=tail->next;
	}
	printlist(head);
	head=mergesort(&head);
	printlist(head);
	return 0;
}


