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

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    vector <int> commonpoints;
    Node *temp1=head1;
    Node *temp2=head2;
    
    while(temp1!=NULL  && temp2!=NULL){
        if (temp1->data<temp2->data){
            temp1=temp1->next;
        }
        else if (temp1->data>temp2->data){
            temp2=temp2->next;
        }
        else{
            commonpoints.push_back(temp1->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    
    if (commonpoints.size()==0) return NULL;
    Node *head,*tail;
    head=tail=new Node(commonpoints[0]);
    
    
    for(int i=1;i<commonpoints.size();i++){
        tail->next=new Node(commonpoints[i]);
        tail=tail->next;
    }
    
    return head;
    
}