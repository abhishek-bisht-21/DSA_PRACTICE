#include <bits/stdc++.h>
using namespace std;

class node
{
public :
  int data;
  node* next;
};

class linked_list
{
public:
  node* head, *tail;
  int size = 0;

public:
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }


// ____________________________________________________ADDLAST In LL___________________________________________________________________

void addLast(int n)
  {
    // Write your code here
    
        node* newNode = new node;
        newNode->data = n;
        newNode->next = nullptr;
        
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        
        size++;


  }



//   ________________________________________________Display A Linkedlist_______________________________________________

  void display() {
    // write your code here
    node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

  }



// __________________________________________________ REMOVE FIRST IN LL__________________________________________________

void removeFirst() {
   //write your code here
   if(size == 0){
     cout << "List is empty" <<  endl;
     return;
   }
     
     node* temp = head;
     head = head->next;
     temp->next = nullptr;
     size--;

  }

// ______________________________________GET A VALUE IN A LL____________________________________________________________

void getFirst(){
    cout<<head->val<<endl;
}

void getLast(){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout << temp->val << endl;
}

node* getAt(int p){
    int cnt=0;
    node* temp=head;
    while(cnt < p){
        cnt++;
        temp=temp->next;
    }
    cout << temp->val << endl;
    return temp;
}



// ____________________________________________ADD FIRST_____________________________________________________

void addFirst(int val){
    //write your code here

    node *temp = new node;
    temp->val = val;
    temp->next = head;
    head = temp;
}




// __________________________________________Add At Index In Linked List____________________________________________________



void addAt(int pos,int data){
    if(pos==0){
        addFirst(data);
        return;
    }
    node* newnode=new node;
    newnode->val=data;
    int cnt=0;
    node* temp=head;
    while(cnt<pos-1){
        cnt++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}


// ___________________________________________ REMOVE LAST IN LL ________________________________________________________

void removeLast(){
    if(head==NULL) return;
    node* previous=NULL;
    node* temp=head;
    while(temp->next!=NULL){
        previous=temp;
        temp=temp->next;
    }
    previous->next=NULL;
    delete temp;
}

//____________________________________________REMOVE AT A POSITION ______________________________________________

void removeAt(int pos){ 
    if(pos==0){
        deletion_at_head();
        return;
    }
    int cnt=0;
    node* temp=head;
    while(cnt<pos-1){
        cnt++;
        temp=temp->next;
    }
    temp->next = temp->next->next;
}


// _____________________________________________REVERSE A LL____________________________________________________________

  ListNode* reverse(ListNode* head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next_next = NULL;
        
        while(curr != NULL){
            
            next_next = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = next_next;
        }
        
        return prev;
    }


// _____________________________________________________KTH FROM END_____________________________________________________________

int kthFromEnd(int k){
    if(head==nullptr)
    {
        cout<<"List is empty";
        return -1;
    }
    node *temp1=head;
    node *temp2=head;
    // Maintaining a gap of 3 btw temp1 and temp2
    for(int i=0;i<k;i++){
        temp2=temp2->next;
    }
    
    while(temp2->next!=nullptr){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    
    return temp1->val;
}

//   ______________________________________________________MIDDLE OF LL______________________________________________

/*

Based on slow and fast pointer approach. Handled for even and odd numbers

*/

void mid(){
     if(head==nullptr){
        return;
    }
    else{
        node*temp1=head;
        node*temp2=head;
        while(temp2->next!=nullptr && temp2->next->next!=nullptr){
            temp2=temp2->next->next;
            temp1=temp1->next;
        }
        
        cout << temp1->val << endl;
    }
   
}

// ________________________________________ IS LL A PALINDROME______________________________________________________________

class Solution {
public: 
        ListNode* midNode(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL and fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next_next = NULL;
        
        while(curr != NULL){
            
            next_next = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = next_next;
        }
        
        return prev;
    }
    
   
    
    bool isPalindrome(ListNode* head)
    {
        ListNode* front = head;
        ListNode* mid = midNode(head);
        
        ListNode *nhead = mid->next;
        mid->next = nullptr;
        
        nhead = reverse(nhead);
        
      
        while(nhead){
            
            if(front->val != nhead->val){
                return 0;
            }
            
            front = front -> next;
            nhead = nhead->next;
            
        
        }
        
        return 1;
        
    }
   
};




//_____________________________________________________MERGE TWO SORTED LIST_______________________________________________________

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
          if(l1 == NULL or l2 == NULL)
            return l1 != NULL ? l1 : l2;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        
        while(t1 != NULL and t2 != NULL){
            if(t1->val < t2->val){
                dummy -> next = t1;
                t1 = t1->next;
            }
            else{
                
                dummy -> next = t2;
                t2 = t2->next;
            }
            
            dummy = dummy->next;
        }   
        
        
        
        dummy -> next = t1 != NULL ? t1:t2;
        
        return res -> next;
            
    }
};


// ______________________________________________________MERGE SORT IN LL_______________________________________________


int main(){

}