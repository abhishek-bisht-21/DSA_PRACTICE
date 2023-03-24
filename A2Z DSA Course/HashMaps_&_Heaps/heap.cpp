#include<iostream>
#include<vector>

using namespace std;


class heap{

	public:

	bool isMaxHeap = true;

	vector<int> arr;
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

	constructHeap();
}

	// TC-> O(N)
	void constructHeap(){
		for(int i=arr.size()/2-1;i>=0;i--){
			downHeapify(i){

			}
		}
	}


	int size(){
		return this->arr.size();
	}

	bool isEmpty(){
		return this->arr.size() == 0;
	}

	// TC -> O(logN)
	void push(int data){
		this->arr.push_back(data);
		int n = this->arr.size();
		upHeapify(n-1);
	}

	// TC-> O(Logn)
	int pop(){ 
		int rEle = arr[0];
		// Step1: Swap Root Element and Last Element
		swap(this->arr[0],this->arr[arr.size()-1]);
		// Step2: Remove Last Element Now
		this->arr.pop_back();
		// Call Down Heapify till it becomes a valid Heap.
		downHeapify(0);
		return rEle;
	}

	// TC -> O(1)
	int top(){
		return this->arr[0];
	}

	// TC-> Logn
	private void downHeapify(int pi){ // pi -> parentIdx
		int maxIdx = pi;
		int lci = 2*i+1;
		int rci = 2*i+2;

		if(lci < this->arr.size() && arr[lci] > arr[maxIdx]){
			maxIdx = lci;
		}

		if(rci < this->arr.size() &&  arr[rci] > arr[maxIdx]){
			maxIdx = rci;
		}

		if(maxIdx != pi){
			swap(this->arr[maxIdx], this->arr[pi]);
			pi = maxIdx;
			downHeapify(pi);
		}
	}

	// TC -> O(logN)
	private void upHeapify(int ci){
		int pi = (ci-1)/2;

		if(pi >= 0 and this->arr[ci] > this->arr[pi]){
			swap(pi,ci);
			upHeapify(pi);
		}
	}
}