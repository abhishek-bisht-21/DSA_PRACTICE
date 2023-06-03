// TC-> O(N) SC -> O(N)
#include <iostream>
#include <stack>

using namespace std;


void insertAtBottom(stack<int> &st, int x){

	stack<int> temp;
	while(not st.empty()){
		int curr = st.top();
		st.pop();
		temp.push(curr);
	}

	st.push(x); // x got inserted at bottom

	while(not temp.empty()){
		int curr = temp.top();
		temp.pop();
		st.push(curr);
	}
}

void insertAtBottomRecursively(stack<int> &st, int x){
	if(st.empty()){
		st.push(x);
		return;
	}

	int curr = st.top();
	st.pop();
	insertAtBottomRecursively(st,x);
	st.push(curr);
}

void printStack(stack<int> st){

	while(!st.empty()){
		cout << st.top() << endl;
		st.pop();
	}
}

int main(){

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	cout << "Stack Before Inserting at bottom: "<< endl;
	printStack(st);
	//insertAtBottom(st,10);
	insertAtBottomRecursively(st,10);
	cout << "Stack after inserting at bottom: " << endl;
	printStack(st);

	return 0;
}