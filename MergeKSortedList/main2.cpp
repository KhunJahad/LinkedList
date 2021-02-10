Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
 
// The main function that takes an array of lists
// arr[0..last] and generates the sorted output


Node* flatten(Node* arr[],int i,int n){
    
    if (i==n) return NULL;
    return SortedMerge(arr[i],flatten(arr,i+1,n));
}

Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    return flatten(arr,0,last);
}