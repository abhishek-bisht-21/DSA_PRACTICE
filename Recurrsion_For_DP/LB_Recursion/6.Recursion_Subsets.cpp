#include<bits/stdc++.h>
using namespace std;


// 78. Subsets

class Solution {
public:
    
    
    
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int idx = 0;
        solve(nums,output,idx,ans);
        return ans;
    }
};



int main(){

	return 0;
}