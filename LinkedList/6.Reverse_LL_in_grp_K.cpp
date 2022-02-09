// 25. Reverse Nodes in k-Group

class Solution {
public:
    
    
int length(ListNode *head)
{
    int len = 0;
    while (head != nullptr)
    {
        head = head->next;
        len++;
    }
    return len;
}

ListNode *th = nullptr, *tt = nullptr;

void addFirstNode(ListNode *node)
{
    if (th == nullptr)
        th = tt = node;
    else
    {
        node->next = th;
        th = node;
    }
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k <= 1)
        return head;

    int len = length(head);
    ListNode *curr = head, *oh = nullptr, *ot = nullptr;
    while (curr != nullptr && len >= k)
    {
        int tempK = k;
        while (tempK-- > 0)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
        }

        if (oh == nullptr)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }

        th = tt = nullptr;
        len -= k;
    }

    ot->next = curr;

    return oh;
}
};