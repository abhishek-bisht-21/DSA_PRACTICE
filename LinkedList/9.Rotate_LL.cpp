
// Approach 1 . TC-> O(N*K)
class Solution {
public:
    
    ListNode* addFirst(ListNode* root,int val){
        
        ListNode* newNode = new ListNode(val);
        
        if(root == nullptr){
            
            return newNode;
        }
        
        
        newNode->next = root;
        root = newNode;
        return root;
        
    }
    
    int len(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        int l = len(head);
        if(head == nullptr){
            return nullptr;
        }
        
        if(l == 1){
            return head;
        }
        
        if(k > l){
            k = k%l;
        }
        
        while(k--){
            ListNode* curr = head;
            ListNode* prev = curr;
            while(curr->next){
                prev = curr;   
                curr = curr->next;
            }
            
            prev->next = nullptr;
            head = addFirst(head,curr->val);
        }
        
        return head;
    }
};


// Approach 2 TC-> O(N)

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        
        if(!head || !head->next || k == 0) return head;
        
        //Compute Length
        int len=1;
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
            len++;
        }
        
        // go till that node
        curr->next = head;
        k = k  % len;
        k = len - k;
        while(k--) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};
    