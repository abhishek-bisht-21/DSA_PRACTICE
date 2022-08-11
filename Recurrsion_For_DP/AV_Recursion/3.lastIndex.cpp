#include <bits/stdc++.h>
using namespace std;

int lastIndex(vector<int> &arr,int key, int idx){

	if(idx == arr.size()){
		return -1;
	}

	
    int a = lastIndex(arr, key, idx+1);

    if (a != -1)
        return a;

    if (arr[idx] == key)
        return idx;
    else
        return -1;
}


int main(){

	vector<int> v{20,10,30,50,40,10,30,40};
	int key = 10;
	cout << "Last Index of "<< key << " is " << lastIndex(v,key,0);
	return 1;
}