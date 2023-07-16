/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* midNode(ListNode* head){
    
    if(head==NULL or head->next == NULL){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next != NULL and fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

ListNode* reverseList(ListNode* head){
    
     if(head==NULL or head->next == NULL){
        return head;
    }
    
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next_next = NULL;
    
    while(curr != NULL){
        
        
        next_next = curr->next;
        curr->next = prev;
        prev = curr;
        
        curr = next_next;
    }
    
    return prev;
}


void reorderList(ListNode* head) {
    
    
    if(head==NULL or head->next == NULL){
        return;
    }
    
    ListNode* mid = midNode(head);
    ListNode* nhead = mid->next;
    
    mid->next = NULL;
    
    nhead = reverseList(nhead);
    
    
    ListNode* c1 = head;
    ListNode* c2 = nhead;
    
    ListNode* f1 = NULL;
    ListNode* f2 = NULL;
    
      while(c1!=NULL and c2!=NULL)
     {
        // backup
        f1 = c1->next;
        f2 = c2->next;
          
          
        c1->next = c2;
        c2->next = f1;
          
         c1 = f1;
         c2 = f2;
        
    }
    return ;
    
  
    }
};