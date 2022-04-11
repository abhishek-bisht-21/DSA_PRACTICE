
#include <bits/stdc++.h>
using namespace std;

// Space Complexity -> O(n)
// Time Complexity -> O(m+n)

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        
        unordered_map<int,int> umap;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(umap.find(a[i]) == umap.end()){
                umap[a[i]]++;
                cnt++;
            }
        }
        
        for(int i=0;i<m;i++){
            if(umap.find(b[i]) == umap.end()){
                umap[b[i]]++;
                cnt++;
            }
        }
        
        return cnt;
    }
};