#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    void Heapify(vector<int> &arr, int n, int index){
        int largest = index;
        int lci = 2*index+1;
        int rci = 2*index+2;
        
        if(lci < n and arr[largest] < arr[lci]){
            largest = lci;
        }
        
        if(rci < n and arr[largest] < arr[rci]){
            largest = rci;
        }
        
        if(largest != index){
            swap(arr[largest], arr[index]);
            Heapify(arr,n,largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> arr;
        //Step1: Merge two arrays. TC -> O(m+n)
        for(int i:a){
            arr.push_back(i);
        }
        
        for(int i:b){
            arr.push_back(i);
        }
        
        int size = arr.size();
        
        // Step2: buildHeap. Call Heapify on merged vector
        for(int i=size/2+1;i>=0;i--){
            Heapify(arr,size,i);
        }
        
        return arr;
    }
};
