#include <iostream>
using namespace std;


class heap{
	public:
		int arr[100];
		int size;

		heap(){
			arr[0] = -1;
			size = 0;
		}

		// Insrtion Time Complexity -> O(logn)
		void insert(int val){

			// Step 1: Insert the Element at the last position.
			size = size+1;
			int index = size;
			arr[index] = val;

			// Step 2: Swap till the inserted element reaches its correct position.
			while(index > 1){

				int parent = index/2;
				if(arr[parent] < arr[index]){
					swap(arr[parent], arr[index]);
					index = parent;
				}else{
					return;
				}
			}
		}

		// Popping Out the root node. Time Complexity of Deletion -> O(logn)
		void deletion(){
			if(size == 0){
				cout << "Nothing to delete" << endl;
				return;
			}
			// Step 1: Swap root node and Last Node.
			arr[1] = arr[size];	
			// Step 2: Remove the Last Node. 
			size--;
			// Step 3: Propogate the root node to its correct position.
			int i = 1;
			while(i < size){
				int lci = 2*i; // Left child Index
				int rci = 2*i+1; // Right child Index

				if(lci < size && arr[i] < arr[lci] && arr[lci] > arr[rci]){
					swap(arr[i], arr[lci]);
					i = 2*i;
				}else if(rci < size && arr[i] < arr[rci] && arr[rci] > arr[lci]){
					swap(arr[i],arr[rci]);
					i = 2*i+1;
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

// Time Complexity is O(logn)
void heapify(int arr[], int n, int i){
	int largest = i;
	int lci = 2*i;
	int rci = 2*i+1;

	if(lci < n && arr[largest] < arr[lci]){
		largest = lci;
	}

	if(rci < n && arr[largest] < arr[rci]){
		largest = rci;
	}

	if(largest != i){
		swap(arr[largest], arr[i]); 
		heapify(arr,n,largest);
	}

}

int main(){

	int size = 0;
	// cout << "Enter the size of Heap " << endl;
	// cin >> size;
	// heap h;
	// for(int i=0;i<size;i++){
	// 	int x;
	// 	cin>> x;
	// 	h.insert(x);
	// }
	
	//h.deletion();
	//h.print();

	int a[6] = {-1,54,53,55,52,50};
	int n = 5;
	
	// We will only work for Internal Nodes.
	// Internal Nodes are in the range: (0 to n/2)
	// Leave Nodes are in the Range: (n/2 + 1 to n)
	for(int i = n/2; i > 0; i--){
	  heapify(a,n,i); 
	}

	cout << "Printing the Array after heapify"<<endl; 
	for(int i = 1; i<=n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}