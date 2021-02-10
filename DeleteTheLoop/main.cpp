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
    struct *Node next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow=head;
    Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL && slow!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast){
            break;
        }
    }
    // if we have a match 
    
    if (slow==fast){
        slow=head;
        
        if (slow==fast){
            //  if we have the fast pointing at the head 
            // we have to check which node has the head as it's next pointer
            // and then just NULL it -- this is an edge case
            while(fast->next!=slow){
                fast=fast->next;
            }
            
        }
        else{
            // if the fast is not NULL
            // then we try to find slow starting with head
            // loop through the start and fast pointer untill we find the fast node yeilding
            // the same as next -- which is the cause of loop and then NULL it
            while (slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
}