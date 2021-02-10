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

Node* divide(Node *head){
        // code here
        Node *end=head;
        while(end->next!=NULL){
            end=end->next;
        }
        
        Node *newend=end;
        Node *current=head;
        Node *prev=NULL;
        while (current->data%2!=0 && current!=end){
            newend->next=current;
            current=current->next;
            newend->next->next=NULL;
            newend=newend->next;
        }
        
        if (current->data%2==0){
            head=current;
            while (current!=end){
                if (current->data%2==0){
                    prev=current;
                    current=current->next;
                }
                else{
                    prev->next=current->next;
                    current->next=NULL;
                    newend->next=current;
                    newend=current;
                    current=prev->next;
                }
            }
        }
        else prev=current;
        if (newend != end && (end->data) % 2 != 0){  
            prev->next = end->next;  
            end->next = NULL;  
            newend->next = end;  
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
    head=divide(head);
    printlist(head);
    return 0;
}



