
// Approach 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
int length(ListNode* head){
    ListNode* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        ListNode* t1 = head1;
        ListNode* t2 = head2;
    
    int delta = abs(length(head1) - length(head2));
    
    if(length(head1) > length(head2)){
        for(int i=0;i<delta;i++){
            t1 = t1->next;
        }
    }else{
        for(int i=0;i<delta;i++){
            t2 = t2->next;
        }
    }
    
    while(t1 != t2){
        t1  = t1->next;
        t2 = t2->next;
    }
    
    return t1;
    }
};

// Approach 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA or !headB) return nullptr;
        
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        while(currA != currB){
            currA = currA == nullptr ? headB:currA->next;
            currB = currB == nullptr ? headA:currB->next;
        }
        
        return currA;
    }
};