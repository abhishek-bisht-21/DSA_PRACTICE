// 1290. Convert Binary Number in a Linked List to Integer

// Approach 1
class Solution {
public:
    
    int len(ListNode* head){
        int len = 0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = head;
        int l = len(curr);
        
        int ans = 0;
        
        int cnt = 1;
        while(curr){
            ans+=curr->val * pow(2,l-cnt);
            curr = curr->next;
            cnt++;
        }
        
        return ans;
    }
};

// Approach 2
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int ans = 0;
        ListNode* curr = head;
        
        while(curr){
            
            ans*=2;
            ans+=curr->val;
            curr = curr->next;
        }
        return ans;
    }
};