#include <bits/stdc++.h>
using namespace std;


class Stack{
	
	private:
		int top;
		int capacity;
		int *arr;

	public:
		Stack(int c){
		    this->capacity = c;
		    arr = new int[this->capacity];
		    this->top = -1;
		}

		bool isFull(){
			if(this->top == this->capacity-1){
				return true;
			}
			return false;
		}

		bool isEmpty(){
			if(this->top == -1){
				return true;
			}

			return false;
		}

		void push(int data){
			if(isFull()){
				cout << "Stack Overflow\n";
				return;
			}
			this->top++;
			this->arr[this->top] = data;
		}

		int pop(){
			if(isEmpty()){
				cout << "Stack Underflow\n";
				return INT_MIN;
			}
			return this->arr[this->top--];
		}

		int peek(){
			return arr[this->top];
		}

		int size(){
			return this->top+1;
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
	

	return 0;
}