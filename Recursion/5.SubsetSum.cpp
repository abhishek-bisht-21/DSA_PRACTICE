
// Subset Sums

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr or head->next == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        
        return false;
    }
};