#include <bits/stdc++.h>
using namespace std;



bool find(vector<int> &arr,int key, int idx){

	if(idx == arr.size()){
		return false;
	}

	return (arr[idx] == key || find(arr,key,idx+1));
}

int main(){

	int key = 10;
	vector<int> v{10,20,30,40,50};
	cout << "Is Element " << key<< " present in the array " << boolalpha << find(v,key,0);;

	return 1;
}