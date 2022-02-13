// Approach 1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr = head;
        
    
    if(curr == NULL or curr->next == nullptr){
        return head;
    }
    
        
    ListNode* dummy = new ListNode(1e8);
    ListNode* itr = dummy;
    
    while(curr != NULL){
        
        if(curr -> val != itr ->val){
            
            itr->next = curr;
            itr = itr->next;
        }
       
            curr = curr -> next;
        
    }
    
    itr->next = nullptr;
    return dummy->next;
    }
};



// Approach 2

class Solution {
public:
    
    ListNode *th = nullptr, *tt = nullptr;
    void addLast(ListNode* node){
        if(tt == nullptr){
            th = tt = node;
        }else{
            tt->next = node;
            tt = tt->next;
        }
        
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr){
            return head;
        }
        
        ListNode* curr = head;
        while(curr != nullptr){
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