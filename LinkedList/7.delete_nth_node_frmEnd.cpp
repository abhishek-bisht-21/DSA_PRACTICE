// 19. Remove Nth Node From End of List

// Approach 1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         //Counting the number of nodes in the linked list.       
      ListNode *temp=head;
      int countNodes=0;
      while(temp!=NULL)
      {
          countNodes++;
          temp=temp->next;
      }
        
      //Checking the edge case when the 'n' i.e. node to be deleted
      //from end of the list is equal to the number of nodes in the 
      //linked list.
      /*For Example :- 
                       Input : [7,4] , n=2
                       Output: [4]
      */
      if(countNodes==n)
      {
          ListNode *node=head;
          head=head->next;
          delete node;
          return head;
      }
        
      //If the node to be deleted is not the head of the list then we have 
      //to reach one node before it.         
      int difference = countNodes - n;
      int counter=1;
      temp=head;
      while(counter!=difference)
      {
          counter++;
          temp=temp->next;
      }
        
      //The main logic to delete the nth node from the end.       
      ListNode *node=temp->next;
      temp->next=node->next;
      delete node;
        
      return head;
    }
};


// Approach 2

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast = head, *slow = head;
        
        for (int i = 0; i < n; i++) 
            fast = fast->next;
        
        if (!fast) return head->next;
        
        while (fast->next) fast = fast->next, slow = slow->next;
        
        slow->next = slow->next->next;
        
        return head;
    }
};