#include <bits/stdc++.h>
using namespace std;



vector<int> AllIndices(vector<int> &arr, int idx, int key, int count){
	if(idx == arr.size()){
		vector<int> base(count,0);
		return base;
	}

	if(arr[idx] == key){
		count++;
	}

	vector<int> ans = AllIndices(arr,idx+1,key,count);
	if(arr[idx] == key){
		ans[count-1] = idx;
	}

	return ans;
}


int main(){

	vector<int> v{20,10,30,50,40,10,30,40};
	int key = 10;
	vector<int> ans = AllIndices(v,0,key,0);

	for(int val: ans){
		cout << val << " ";
	}
	return 1;
}