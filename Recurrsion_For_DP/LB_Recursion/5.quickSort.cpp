#include<bits/stdc++.h>
using namespace std;



void quickSort(int *arr, int low, int high)
    {
        // code here
        if(low >= high){
            return;
        }

        int partitionIdx = partition(arr,low,high);
        quickSort(arr,low,partitionIdx-1);
        quickSort(arr,partitionIdx+1,high);
    }
    
    
    int partition (int *arr, int low, int high)
    {
       // Your code here
       int pivot = arr[high];
       int i=0;
       int j=0;
       
       while(i <= high){
           if(arr[i]  > pivot){
               i++;
           }else{
               swap(arr[j],arr[i]);
               i++;
               j++;
           }
       }
       
       return j-1;
    }


int main(){

	int arr[] = { 4, 1, 3, 9, 7};
	int n = sizeof(arr)/sizeof(int);

	cout << "Before Quicksort: ";
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	quickSort(arr,0,n-1);

	cout << "After Quicksort: ";
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}


	return 1;
}