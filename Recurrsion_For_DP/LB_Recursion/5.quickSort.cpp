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



// ALTERNATE APPROACH

int partition( vector<int> &arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}   

void solve(vector<int> &arr, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenge
    int p = partition(arr, s, e);

    //left part sort karo
    solve(arr, s, p-1);

    //right wala part sort karo
    solve(arr, p+1, e);

}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    solve(arr,0,arr.size()-1);
    return arr;
}
