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

Node *reverse(Node *head){
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

int getNthFromLast(Node *head, int n)
{
       // Your code here
       head=reverse(head);
       int i=1;
       while (i<n && head!=NULL){
           head=head->next;
           i++;
       }
       if (head==NULL) return -1;
       else return head->data;
}


int main(){
	read_input();
	int n,k;
	cin>>n>>k;
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
	cout<<getNthFromLast(head,k);
	
	return 0;
}


