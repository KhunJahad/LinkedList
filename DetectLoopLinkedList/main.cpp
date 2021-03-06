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

bool loop_detection(Node *head){
	Node *slow=head;
	Node *fast=head;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if (slow==fast) return true;
	}
	return false;
}

int main(){
	read_input();
	int n;
	cin>>n;
	int temp;
	cin>>temp;
	Node *head,*tail;
	head=tail=new Node(temp);
    // don't run this i havent used any loop
	for(int i=1;i<n;i++){
		cin>>temp;
		tail->next=new Node(temp);
		tail=tail->next;
	}
	cout<<loop_detection(head);
	return 0;
}


