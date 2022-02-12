class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head or !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        
        return nullptr;
    }
};