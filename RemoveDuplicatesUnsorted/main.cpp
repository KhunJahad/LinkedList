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

bool remove_duplicate(Node *head){
	map <int,int> s;
	Node *prev=head;
	Node *temp=head->next;
	
	s[head->data]=1;
	while(temp!=NULL){
		if (s[temp->data]==0){
			s[temp->data]=1;
			prev=temp;
			temp=temp->next;
		}
		else{
			while(temp !=NULL && s[temp->data]!=0){
				temp=temp->next;
			}
			prev->next=temp;
		}
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
    // don't run this i havent used any loop
	for(int i=1;i<n;i++){
		cin>>temp;
		tail->next=new Node(temp);
		tail=tail->next;
	}
	printlist(head);
	cout<<"\n";

	remove_duplicate(head);
	return 0;
}


