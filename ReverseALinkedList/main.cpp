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

// declaring a node structure
struct Node {
	int data;
	struct Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}	
};
// declaring prototype
void reverseList(struct Node *head);

// function from printing
void printlist(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

void reverseList(struct Node *head){
	struct Node *current=head;
	struct Node *previous=NULL;
	struct Node *next=NULL;

	while (current!=NULL){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;
	}
	head=previous;
	printlist(head);
}

int main(){
	read_input();
	int n;
	cin>>n;
	struct Node *head=NULL,*tail=NULL; 
	int firstdata;
	cin>>firstdata;
	head=new Node(firstdata);
	tail=head;

	for (int i=1;i<n;i++){
		int temp;
		cin>>temp;
		tail->next=new Node(temp);
		tail=tail->next;
	}

	printlist(head);
	reverseList(head);
	//printlist(head);
	
	return 0;
}


