#include <iostream>
using namespace std;

//  WE ARE FOLLOWING 1-BASED INDEXING IN THE FOLLOWING IMPLEMENTATION

class heap{
	public:
	int arr[100];
	int size;

	heap(){
		arr[0] = -1;
		size = 0;
	}
	// INSERTION
	void insert(int val){
		size += 1;
		int index = size;
		arr[index] = val;

		while(index > 1){
			int parent = index/2;
			if(arr[parent] < arr[index]){
				swap(arr[parent],arr[index]);
				index = parent;
			}else{
				return;
			}
		}
	}

	// DELETION -> Root Node will be Deleted.
	// STEP 1 -> Swap root node with the last node.
	// STEP 2 -> Delete the last node now .
	// STEP 3 -> Call the Heapify property, to propogate root node to its correct position.

	void delteFromHeap(){
		if(size == 0){
			cout << "Nothing to delete" << endl;
			return ;
		}

		// STEP1 and STEP2
		arr[1] = arr[size];
		size--;

		// STEP 3: Take root node to its correct position
		int i = 1;
		while(i < size){
			int leftIndex = 2 * i; 
			int rightIndex = 2 * i + 1;

			if(leftIndex < size && arr[i] < arr[leftIndex]){
				swap(arr[i],arr[leftIndex]);
				i = leftIndex;
			}
			else if(rightIndex < size && arr[i] < arr[rightIndex]){
				swap(arr[i],arr[rightIndex]);
				i = rightIndex;
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

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if(left <= n && arr[largest] < arr[left]){
		largest = left;
	}

	if(right <= n && arr[largest] < arr[right]){
		largest = right;
	}

	if(largest != i){
		swap(arr[largest], arr[i]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[], int n){
	int size = n;

	while(size > 1){
		// STEP1 : SWAP
		swap(arr[size], arr[1]);
		
		size--;
		// STEP 2
		heapify(arr,size,1);
	}
}


// HEAP IS A COMPLETE BINARY TREE. CBT IS A BINARY TREE WHOSE ALL LEVELS ARE COMPLETELY FILLED EXCEPT THE 
// LAST LEVEL AND LAST LEVEL IS FILLED FROM LEFT TO RIGHT.
// IN A CBT NODES IN RANGE (N/2+1 TO N) ARE LEAF NODES.	

int main(){

	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);

	h.print();

	h.delteFromHeap();
	h.print();

	// BUILDING HEAP
	int arr[6] = {-1,54,53,55,52,50};
	int n = 5;
	// IN A CBT INTERNAL NODES ARE 0 to N/2. THEREFORE WE NEED TO OPERATE ON THEM ONLY.
	// IN A CBT N/2 to N are LEAF NODES AND LEAF NODES SATISFIES HEAP ORDER PROPERTY.
	for(int i=n/2;i>0;i--){
		heapify(arr,n,i);
	}

	cout << "PRINT THE ARRAY NOW"<< endl;
	for(int i=1;i<=n;i++){
		cout << arr[i] << " ";
	}

	cout << endl;


	//  HEAP SORT
	heapSort(arr,n);
		cout << "PRINT THE ARRAY AFTER SORTING"<< endl;
	for(int i=1;i<=n;i++){
		cout << arr[i] << " ";
	}

	cout << endl;


	return 0; 
}