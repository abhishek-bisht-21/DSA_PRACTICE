class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr or head->next == nullptr){
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        itr->next = head;
        ListNode* curr = head->next;
        
        while(curr){
            bool flag = false;
            while(curr && itr->next->val == curr->val){
                flag = true;
                curr = curr->next;
            }
            
            if(flag){
                itr->next = curr;
            }else{
                itr = itr->next;
            }
            
            if(curr != NULL){
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};