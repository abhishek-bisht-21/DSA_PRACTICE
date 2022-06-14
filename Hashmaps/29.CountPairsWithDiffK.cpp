
// 2006. Count Number of Pairs With Absolute Difference K
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]+k]) count+=map[nums[i]+k]; 
            if(map[nums[i]-k]) count+=map[nums[i]-k]; 
            map[nums[i]]++;
        }
        return count;
    }
};
