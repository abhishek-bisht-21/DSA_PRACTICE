class Solution {
public: 
        ListNode* midNode(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL and fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next_next = NULL;
        
        while(curr != NULL){
            
            next_next = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = next_next;
        }
        
        return prev;
    }
    
   
    
    bool isPalindrome(ListNode* head)
    {
        ListNode* front = head;
        ListNode* mid = midNode(head);
        
        ListNode *nhead = mid->next;
        mid->next = nullptr;
        
        nhead = reverse(nhead);
        
      
        while(nhead){
            
            if(front->val != nhead->val){
                return 0;
            }
            
            front = front -> next;
            nhead = nhead->next;
            
        
        }
        
        return 1;
        
    }
   
};
