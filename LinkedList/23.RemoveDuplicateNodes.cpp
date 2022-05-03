// 83. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1e8);
        ListNode* itr = dummy;
        
        ListNode* curr = head;
        
        while(curr){
            if(itr->val != curr->val){
                itr->next = curr;
                itr = itr->next;
                curr = curr->next;
            }else{
                curr = curr->next;
            }
        }
        
        itr->next = NULL;
        return dummy->next;
    }
};