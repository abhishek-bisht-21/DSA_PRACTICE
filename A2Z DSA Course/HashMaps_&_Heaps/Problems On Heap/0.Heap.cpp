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

		void print(){
			for(int i=1;i<=size;i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main(){

	int size = 0;
	cout << "Enter the size of Heap " << endl;
	cin >> size;
	heap h;
	for(int i=0;i<size;i++){
		int x;
		cin>> x;
		h.insert(x);
	}

	h.print();

	return 0;
}