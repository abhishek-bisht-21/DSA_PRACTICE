// TC-> O(N) SC -> O(N)
#include <iostream>
#include <stack>

using namespace std;


void RemoveAtBottom(stack<int> &st){

	stack<int> temp;
	while(st.size() != 1){
		int curr = st.top();
		st.pop();
		temp.push(curr);
	}

	st.pop(); // x got removed at bottom

	while(not temp.empty()){
		int curr = temp.top();
		temp.pop();
		st.push(curr);
	}
}

void RemoveAtBottomRecursively(stack<int> &st){
	if(st.size() == 1){
		st.pop();
		return;
	}

	int curr = st.top();
	st.pop();
	RemoveAtBottomRecursively(st);
	st.push(curr);
}

void RemoveAtIndexRecursively(stack<int> &st, int idx){

	if(st.size() == idx){
		st.pop();
		return;
	}

	int curr = st.top();
	st.pop();
	RemoveAtIndexRecursively(st,idx);
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
	//RemoveAtBottom(st);
	//RemoveAtBottomRecursively(st);
	RemoveAtIndexRecursively(st,1);
	cout << "Stack after inserting at bottom: " << endl;
	printStack(st);

	return 0;
}