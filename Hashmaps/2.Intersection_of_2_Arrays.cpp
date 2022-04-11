#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> uset;
        
        for(int ele:nums1){
            uset.insert(ele);
        }
        
        vector<int> ans;
        
        for(int ele:nums2){
            if(uset.find(ele) != uset.end()){
                ans.push_back(ele);
                uset.erase(ele);
            }
        }
        
        return ans;
    }
};

