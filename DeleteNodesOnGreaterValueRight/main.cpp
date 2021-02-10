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
    Node *prev=NULL,*next=NULL;
    
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
Node *compute(Node *head)
{
    // your code goes here
    head=reverse(head);
    Node *temp=head;
    int max_element=head->data;
    Node *prev=NULL;
    while(temp!=NULL){
        if (temp->data>=max_element){
            max_element=temp->data;
            prev=temp;
            temp=temp->next;
        }
        else{
            prev->next=temp->next;
            temp->next=NULL;
            temp=prev->next;
        }
        
    }
    return reverse(head);
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
    head=compute(head);
    printlist(head);
    return 0;
}

