class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL and fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};