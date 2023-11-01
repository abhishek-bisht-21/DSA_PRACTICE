class Solution {
public:
    
         ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr)
            return l1 != nullptr ? l1 : l2;

        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy, *c1 = l1, *c2 = l2;

        while (c1 != nullptr && c2 != nullptr) {
            if (c1->val <= c2->val) {
                prev->next = c1;
                c1 = c1->next;
            } else {
                prev->next = c2;
                c2 = c2->next;
            }
            prev = prev->next
        }

        prev->next = c1 != nullptr ? c1 : c2;
        ListNode* head = dummy->next;
        dummy->next = nullptr; // delete dummy;
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int si, int ei){
        
        if(si == ei){
            return lists[si];
        }
        
        int mid = (si+ei)/2;
        return mergeTwoLists(mergeKLists(lists,si,mid), mergeKLists(lists,mid+1,ei));
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
           if (lists.size() == 0)
            return nullptr;
        
        int n = lists.size();
        int ei = n-1;
        return mergeKLists(lists,0,ei);
    }
};