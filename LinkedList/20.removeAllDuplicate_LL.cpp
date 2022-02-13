class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
     
   
    if(head == NULL or head -> next == NULL){
        return head;
    }
        
        
        
    ListNode* curr = head->next;
        
        
    ListNode* dummy = new ListNode(-1);
    ListNode* itr = dummy;
    itr->next = head; // Potential unique element    
    
    while(curr != NULL){
        
        bool isLoopRun = false;
        
        while(curr != NULL && itr->next-> val == curr ->val){
            isLoopRun = true;
            curr = curr->next;
        }
        
        if(isLoopRun){
            itr->next = curr;
        }else{
            itr = itr->next;
        }
        
        if(curr != nullptr){
            curr = curr->next;
        }
       
    }
    
    return dummy->next; 
    }
};