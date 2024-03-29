// 206. Reverse Linked List

// Recurrsive solution
class Solution {
public:
    
    ListNode* revList(ListNode* head){
        
        if(head->next == nullptr){
            return head;
        }
        
        ListNode* revHead = revList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return revHead;
    }
    ListNode* reverseList(ListNode* head) {
        
        if(head  == nullptr){
            return head;
        }
        return revList(head);
    }
};


// Iterative Solution
// TC-> O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next_next;
        ListNode* prev = NULL;


        while(curr != NULL){
            next_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_next;
        }

        return prev;
    }
};