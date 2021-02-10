Node *copyList(Node *head) {
    // Your code here
    
    if (head==NULL) return head;
    
    Node *current=head;
    Node *temp;
    
    while(current!=NULL){
        temp=current->next;
        current->next=new Node(current->data);
        current->next->next=temp;
        current=temp;
    }
    
    current=head;
    while(current!=NULL){
        if (current->next) current->next->arb=current->arb ? current->arb->next : current->arb;
        current=current->next?current->next->next : current->next;
    }
    
    Node *start=head,*copy=head->next;
    temp=copy;
    while(start!=NULL && copy!=NULL){
        start->next=start->next?start->next->next:start->next;
        copy->next=copy->next ? copy->next->next:copy->next;
        start=start->next;
        copy=copy->next;
    }
    return temp;
}