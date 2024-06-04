// https://leetcode.com/problems/maximum-product-subarray/description/


// Brute Force Generate All SubArrays

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


// Better Approach: 

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


// Optimal Apporach:
/**
 * Observations:

 If the given array only contains positive numbers: If this is the case, we can confidently say that 
 the maximum product subarray will be the entire array itself.
 If the given also array contains an even number of negative numbers:
 As we know, an even number of negative numbers always results in a positive number. 
 So, also, in this case, the answer will be the entire array itself.

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int cprod = 1;
        int ans = INT_MIN;
        
        for(int i=0;i<nums.size()-1;i++){
            
            cprod*=nums[i];
            ans = max(ans,cprod);
            if(nums[i] == 0){
                cprod = 1;
            }
        }
        
        cprod = 1;
         for(int i=nums.size()-1;i>=0;i--){
            
            cprod*=nums[i];
            ans = max(ans,cprod);
            if(nums[i] == 0){
                cprod = 1;
            }
        }
        
        return ans;
    }
};