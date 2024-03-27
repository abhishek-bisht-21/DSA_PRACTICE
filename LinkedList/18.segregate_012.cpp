class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node*  two = new Node(-1);
        
        Node* curr = head;
        
        Node* p0 = zero;
        Node* p1 = one;
        Node* p2 = two;
        
        while(curr != NULL){
            if(curr->data == 0){
                p0->next = curr;
                p0 = p0->next;
            }
            else if(curr->data == 1){
                p1->next = curr;
                p1 = p1->next;
            }else{
                p2->next = curr;
                p2 = p2->next;
            }
            
            curr = curr->next;
        }
        
        p2->next = NULL;
        p1->next = two->next;
        p0->next = one->next;
        
        return zero->next;
    }
};


// Approach 2: Count 0,1,2 and replace them in LL

Node* sortList(Node *head){
    // Write your code here.

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;

    while(temp){
        if(temp->data == 0){
            count0++;
        }else if(temp->data == 1){
            count1++;
        }else{
            count2++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp){
        if(count0){
            temp->data = 0;
            count0--;
        }else if(count1){
            temp->data = 1;
            count1--;
        }else{
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}