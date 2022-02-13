class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node*  two = new Node(-1);
        
        Node* curr = head;
        
        Node* p0 = zero;
        Node* p1 = one;
        Node* p2 = two;
        
        while(curr != NULL){
            if(curr->data == 0){
                p0->next = curr;
                p0 = p0->next;
            }
            else if(curr->data == 1){
                p1->next = curr;
                p1 = p1->next;
            }else{
                p2->next = curr;
                p2 = p2->next;
            }
            
            curr = curr->next;
        }
        
        p2->next = NULL;
        p1->next = two->next;
        p0->next = one->next;
        
        return zero->next;
    }
};