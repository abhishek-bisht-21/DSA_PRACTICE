// 21. Merge Two Sorted Lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
          if(l1 == NULL or l2 == NULL)
            return l1 != NULL ? l1 : l2;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        
        while(t1 != NULL and t2 != NULL){
            if(t1->val < t2->val){
                dummy -> next = t1;
                t1 = t1->next;
            }
            else{
                
                dummy -> next = t2;
                t2 = t2->next;
            }
            
            dummy = dummy->next;
        }   
        
        
        
        dummy -> next = t1 != NULL ? t1:t2;
        
        return res -> next;
            
    }
};