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

int main(){

}