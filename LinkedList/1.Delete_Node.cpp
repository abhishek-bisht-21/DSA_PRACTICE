// 237. Delete Node in a Linked List

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if(node->next == NULL){
            delete node;
        }
        
        swap(node->val,node->next->val);
        ListNode* temp = node->next; // the node we want to delete
        node->next = temp->next;
        delete(temp);
        
    }
};