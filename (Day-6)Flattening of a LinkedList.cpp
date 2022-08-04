//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Node *mergeTwoList(Node *a , Node *b){
    Node *temp = new Node(0) ;
    Node *mergedList = temp ;
    
    while(a != NULL and b != NULL){
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a != NULL) temp->bottom = a;
    else temp->bottom = b;
    
    return mergedList->bottom ;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root == NULL or root->next == NULL) return root;
   
   root->next = flatten(root->next) ;
   root = mergeTwoList(root, root->next) ;
   
   return root;
}
