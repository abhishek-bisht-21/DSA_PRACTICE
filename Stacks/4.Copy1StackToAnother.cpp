#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
        
	stack<int> temp;
	while(not input.empty()){
		// do the process till the input stack doesn't become empty
		int currTop = input.top();
		input.pop();
		temp.push(currTop);
	}

	stack<int> result;

	while(not temp.empty()){
		int curr = temp.top();
		temp.pop();
		result.push(curr);
	}

	return result;
}

void printStack(stack<int> st){

	while(!st.empty()){
		cout << st.top() << endl;
		st.pop();
	}
}

// Using Call Stack in recursion as Temporary Stack
void copyStackRec(stack<int> &input, stack<int> &result){
	if(input.empty()){
		return;
	}

	int curr = input.top();
	input.pop();
	copyStackRec(input,result);
	result.push(curr);
}

int main(){

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	cout << "Original Stack content: " << endl;
	printStack(st);

	//stack<int> res = copyStack(st);
	stack<int> res;
	copyStackRec(st,res);
	cout << "Copied Stack content: " << endl;
	printStack(res);

	return 0;
}