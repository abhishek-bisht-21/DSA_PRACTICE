#include<iostream>
#include<vector>

using namespace std;

bool isMaxHeap = true;

void defaultValue(bool isMaxHeap){
 vector<int> arr;
 this.isMaxHeap = isMaxHeap;
}

// By Default Max Heap. Will be adding values 1 by 1
void heap(){
 defaultValue(true);
}

// Can be a Min or Max Heap. Will be adding values 1 by 1
void heap(bool isMaxHeap){
 defaultValue(isMaxHeap);
}

// Already there will be an array and also we will mention What Heap we want.
void heap(vector<int> arr, bool isMaxHeap){
	defaultValue(isMaxHeap);
	for(int ele: arr){
		this.arr.push_back(ele);
	}
}

class heap{

	int size(){

	}

	bool isEmpty(){

	}

	void push(){

	}

	int pop(){

	}

	int top(){

	}
}