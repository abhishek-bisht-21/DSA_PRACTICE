// 83. Remove Duplicates from Sorted List

//  Approach 1: Using Temp/Dummy Node
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


//  Approach 2: Using addLast temp head and Temp tail.

class Solution {
public:
    
    
    ListNode* th = nullptr;
    ListNode* tt = nullptr;
    
    void addLast(ListNode* node){
        if(th == nullptr){
            th = tt = node;
        }else{
            tt->next = node;
            tt = node;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr){
            return head;
        }
        
        ListNode* curr = head;
        
        while(curr){
            ListNode* forw = curr->next;
            curr->next = nullptr;
            if(tt == nullptr or tt->val != curr->val){
                addLast(curr);
            }
            
            curr = forw;
        }
        
        return th;
    }
};