typedef long long int ll;
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  ll mod=1e9+7;
  ll num1=0;
  ll num2=0;
  
  while (l1!=NULL || l2!=NULL){
      
      if (l1!=NULL){
          num1= ((num1*10)%mod+l1->data)%mod;
          l1=l1->next;
      }
      if (l2!=NULL){
          num2=((num2*10)%mod+l2->data)%mod;
          l2=l2->next;
      }
  }
  
  return ((num1%mod)*(num2%mod))%mod;
  
  
  
}