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

Node* segregate(Node *head) {
    
    // Add code here
    int count[3]={0,0,0};
    
    Node *temp=head;
    while(temp!=NULL){
        count[temp->data]+=1;
        temp=temp->next;
    }
    
    temp=head;
    int i=0;
    while(i<3 && temp!=NULL){
        while(count[i]>0){
            temp->data=i;
            count[i]-=1;
            temp=temp->next;
        }
        i++;
    }
    return head;
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
	head=segregate(head);
	printlist(head);
	return 0;
}


