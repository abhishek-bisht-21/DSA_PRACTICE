//724. Find Pivot Index

/*
1) Calculate the Sum of the Array
2) Keep Decrementing arr[i] from right sum 
3) Keep Incrementing arr[i] to left sum

*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        for(int ele:nums){
            sum+=ele;
        }
        
        int ls = 0;
        int rs = sum;
        
        for(int i=0;i<nums.size();i++){
            
            rs = rs - nums[i];
            
            if(ls == rs){
                return i;
            }
            
            ls = ls+nums[i];
        }
        
        return -1;
    }
};