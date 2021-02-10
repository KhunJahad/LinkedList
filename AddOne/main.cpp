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
	head=previous;
	return head;
}

void add_one(Node *head){
	head=reverse(head);
	Node *temp=head;
	int carry=1;
	while(temp!=NULL){
		int x=temp->data;
		if (temp->next!=NULL){
			temp->data=(x+carry)%10;
			carry=(x+carry)/10;
		} 
		else{
			temp->data=x+carry;
		} 
		temp=temp->next;
	}
	
	head=reverse(head);
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

	add_one(head);
	return 0;
}


