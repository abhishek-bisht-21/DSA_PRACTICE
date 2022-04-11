/*

Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    
	    unordered_map<int,int> umap;
	    bool ans = false;
	    
	    for(int i=0;i<n;i++){
	        umap[arr[i]]++;
	    }
	    
	    for(int i=0;i<n;i++){
	        
	        int ele = x - arr[i];
	        
	        if(ele == arr[i]){
	            if(umap[arr[i]] > 1){
	                ans = true;
	                break;
	            }else{
	                return ans;
	            }
	        }
	        
	        if(umap.find(ele) != umap.end()){
	            ans = true;
	            break;
	        }
	        
	       
	    }
	    
	    
	    return ans;
    	    
	}
};