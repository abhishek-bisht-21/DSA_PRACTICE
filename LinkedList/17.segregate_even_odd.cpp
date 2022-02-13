
class Solution{
public:
    Node* divide(int N, Node *head){
        
         Node* ehead = new Node(0);
        Node* etail = ehead;        
        Node* ohead = new Node(0);
        Node* otail = ohead;
        
        while(head!=NULL){
            
            if(head->data % 2 == 1){
                otail->next = head;
                otail = otail->next;
            }else{
                etail->next = head;
                etail = etail->next;
            }
            
            head = head->next;
        }
        
       
            etail->next = ohead->next;
        
            otail->next = NULL;
        
        
        return ehead->next;
    }
};