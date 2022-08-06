#include <iostream>
using namespace std;


void sortArray(int *arr, int idx,int n){

	if(idx == n-1){
		return; 
	}

	sortArray(arr,idx+1,n);
	if(arr[idx] > arr[idx+1]){
		swap(arr[idx],arr[idx+1]);
	}
}


int main()
{	
	int arr[] = {1,3,4,5,2};
	int n = 5;
	cout << "Array Before Sorting: " << endl;

	for(int	i=0;i<n;i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	int idx = 0;
	sortArray(arr,idx,n);

	cout << "Array After Sorting: " << endl;

	for(int	i=0;i<n;i++){
		cout << arr[i] << " ";
	}

	
	cout << endl;

	return 1;
}
