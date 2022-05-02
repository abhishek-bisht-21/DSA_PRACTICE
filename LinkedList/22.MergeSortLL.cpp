
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    
    Node* midNode(Node* head){
        
        if(head != NULL || head -> next == NULL){
            return head;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* mergeTwoLL(Node* l1, Node* l2){
        
        
        
        if(l1 == NULL){
            return l2;
        }
        
        if(l2 == NULL){
            return l1;
        }
        
        Node* c1 = l1;
        Node* c2 = l2;
        Node* res = new Node(-1);
        Node* dummy = res;
        
        while(c1 and c2){
            if(c1->data < c2->data){
                dummy->next = c1;
                c1 = c1->next;
            }else{
                dummy->next = c2;
                c2 = c2->next;
            }
            
            dummy = dummy->next;
        }
        
        if(c1){
            dummy->next = c1;
        }
        
        if(c2){
            dummy->next = c2;
        }
        
        return res->next;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        Node* mid = midNode(head);
        Node* nhead = mid->next;
        mid->next = NULL;
        
        Node* l1 = mergeSort(head);
        Node* l2 = mergeSort(nhead);
        
       return mergeTwoLL(l1,l2);
    }
};
