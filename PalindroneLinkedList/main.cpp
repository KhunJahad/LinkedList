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

bool isPalindrome(Node *head)
{
    //Your code here
    stack <int> s;
    Node *temp =head;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL){
        if (temp->data!=s.top()) return false;
        temp=temp->next;
        s.pop();
    }
    return true;
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
	cout<<isPalindrome(head);
	return 0;
}


