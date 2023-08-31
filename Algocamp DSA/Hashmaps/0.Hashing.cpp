#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>
using namespace std;


class Hashing{
	public:

	vector<list<int>> hashTable;
	int buckets;

	Hashing(int size){
		buckets = size;
		hashTable.resize(size);
	}

	int hashValue(int key){
		return key%buckets; // Devision Medthod 
	}

	void addKey(int key){
		int idx = hashValue(key);
		hashTable[idx].push_back(key);
	}

	list<int>:: iterator searchKey(int key){
		int idx = hashValue(key);
		return find(hashTable[idx].begin(), hashTable[idx].end(), key);
	}

	void deleteKey(int key){

		int idx = hashValue(key);
		if(searchKey(key) != hashTable[idx].end()){ // Check for key is present
			hashTable[idx].erase(searchKey(key));
			cout << key <<" is deleted" << endl;
		}else{
			cout << "Key is not present in hashTable" << endl;
		}
	}
};


int main(){

	Hashing h(10);
	h.addKey(5);
	h.addKey(9);
	h.addKey(3);

	h.deleteKey(3);
	h.deleteKey(9);
	return 0;
}
