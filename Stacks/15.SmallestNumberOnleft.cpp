
// Previous Smaller Element
class Solution {
public:

	vector<int> pse(vector<int> &arr){
		int n = arr.size();
		reverse(arr.begin(),arr.end());

		vector<int> output(n,-1);
		stack<int> st;
		st.push(0);
		for(int i=1;i<n;i++){
			while(!st.empty() && arr[i] < arr[st.top()]){
				output[st.top()] = arr[i];
				st.pop();
			}

			st.push(i);
		}

	reverse(output.begin(), output.end());
	reverse(arr.begin(), arr.end());
	return output; // Previous smaller Element

	}

	vector<int> previousSmallerElement(vector<int>& arr) {
		// Your code goes here

		vector<int> res = pse(arr);
		return res;
	}
};