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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_next = nullptr;
        
        while(curr){
            next_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_next;
        }
        
        return prev;
    }
};