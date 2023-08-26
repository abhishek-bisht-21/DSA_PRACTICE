#include <iostream>
using namespace std;

class heap{
	public:
	  int arr[100];
	  int size = 0;

	  heap(){
		arr[0] = -1;
		size = 0;  
	  }
	  
	//   TC-> O(logn)
	  void insert(int val){
		size = size+1;
		int index = size;
		arr[index] = val;

		while(index > 1){
			int parent = index/2;
			// Comparing with it's parent and this comparison will continue
			// till we reach the root element in some case, to find the correct position for newly 
			// added element.
			if(arr[parent] < arr[index]){
				swap(arr[parent], arr[index]);
				index = parent;	
			}else{
				return;
			}
		}  
	  }

	  // Deleting teh root node. TC-> O(logn)
	  // 1. Swap the root node with last node.
	  // 2. Remove last element 
	  // 3. Maintain the heap-order property. Propogate root node to its correct position		
	  void deleteFromHeap(){
		if(size == 0){
			cout << "Nothing to delete from the heap" << endl;
			return;
		}

		// Step1: Put last element to the first index;
		arr[1] = arr[size];

		// Step2: remove last element
		size--;

		// Step3: Propogate root node to its coorect position
		int i = 1;
		while(i < size){
			int leftChildIndex = i*2;
			int rightChildIndex = 2*i+1;

			if(leftChildIndex < size && arr[leftChildIndex] > arr[i]){
				swap(arr[leftChildIndex], arr[i]);
			}

			else if(rightChildIndex < size && arr[rightChildIndex] > arr[i]){
				swap(arr[rightChildIndex], arr[i]);
			}else{
				return;
			}
		}
	  }


	  void print(){
		for(int i=1;i<=size;i++){
			cout << arr[i] << " ";
		}

		cout << endl;  	
	  }	

};


int main(){

	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();

	h.deleteFromHeap();
	h.print();

	return 0;
}