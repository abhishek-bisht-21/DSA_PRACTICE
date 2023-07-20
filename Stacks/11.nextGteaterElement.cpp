/*
It is always easy to find the nge for increasing curve cause the answer is the next element only,
But for decreasing curve we have to wait till we find the increasing curve again, We have to
wait and park the elements which we encountered in the decreasing curve somewhere.

Whenever such a suitation arise when we have to wait for a elements, then stack is the best
option.	After every decreasing curve when we get a increasing curve then we will surely have 
answer for the last element that we encounter and we can get the last element with help of stack.

In the stack we will store then index of the elements, cause using index we can get the value of
element but vice-versa is not true. Another reason of doing so is that we have to maintain a
output array, by storing index we would know at what index in output array what value we have to store.
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


vector<int> nge(vector<int> &arr){
	int n = arr.size();
	vector<int> output(n,-1);
	stack<int> st;
	st.push(0);

	for(int i=1;i<n;i++){
		while(!st.empty() and arr[i] > arr[st.top()]){
			output[st.top()] = arr[i];
			st.pop();			
		}

		st.push(i);
	}

	while(not st.empty()){ // not mandatory while loop
		output[st.top()] = -1;
		st.pop();
	}

	return output;
}

int main(){
	int n;
	cin >> n;
	vector<int> v;

	while(n--){
		int x;
		cin>> x;
		v.push_back(x);
	}

	vector<int> res = nge(v);
	for(int ele:res){
		cout << ele << endl;
	}
	return 0;
}