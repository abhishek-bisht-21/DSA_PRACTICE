// Insert at head and remove from head. 

#include <bits/stdc++.h>
using namespace std;


class Node{
	public:
	int data;
	Node* next;

	Node(int d){
		this->data = d;
		this->next = NULL;
	}
};

class Stack{

       public:	
       Node* head;
       int capacity;
       int currSize;

       Stack(int c){
	       this->capacity = c;
	       this->currSize=0;
	       this->head = NULL;
       }

       bool isEmpty(){
	       return this->head == NULL;
       }

       bool isFull(){
	       return this->currSize == this->capacity;
       }

       void push(int data){
	       if(isFull()){
	         cout << "Stack Overflow\n";
		 return; 	
	       }
	       Node* newNode = new Node(data);
	       newNode->next = this->head;
	       this->head = newNode;
	       this->currSize++;
       }

       int pop(){
	       if(isEmpty()){
		cout << "Stack underflow\n";
		return INT_MIN;
	       }
	       Node* temp = this->head;
	       this->head = this->head->next;
	       int rmData = temp->data;
	       delete(temp);
	       this->currSize--;
	       return rmData;
       }

       int size(){
	       return this->currSize;
       }

       int peek(){
	       if(this->head == NULL){
		       cout << "Underflow\n";
		       return INT_MIN;
	       }
	       int topData = this->head->data;
	       return topData;
       }
};



int main(){
	Stack st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(8);
	st.push(5);

	cout << "Element removed: " << st.pop() <<endl;
	cout << "Size of Stack: " << st.size() << endl;
	cout << "Top Element: " << st.peek() << endl;	
}