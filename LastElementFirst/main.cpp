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
}

bool last_to_first(Node *head){
	
	Node *tail=head;
	Node *secondlast=NULL;
	Node *prevhead=head;
	int flag=1;
	while(tail->next!=NULL){
		flag=0;
		secondlast=tail;
		tail=tail->next;
	}
	if (!flag){
		secondlast->next=NULL;
		head=tail;
		head->next=prevhead;
	}
	printlist(head);
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
	cout<<"\n";

	last_to_first(head);
	return 0;
}


