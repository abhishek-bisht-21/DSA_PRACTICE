class Solution {
public:
    
    int firstOccurence(vector<int> &nums, int x){
        int n = nums.size(); 
        int si = 0;
        int ei = n-1;
        
        while(si <= ei){
            int mid = (si+ei)/2;
            if(nums[mid] < x){
                si = mid+1;
            }else{
                ei = mid-1;
            }
        }
        
        return si<n && nums[si] == x ? si:-1;
    }
    
    
    int lastOccurence(vector<int> &nums, int x){
        
        int n = nums.size(); 
        int si = 0;
        int ei = n-1;
        
        while(si <= ei){
            int mid = (si+ei)/2;
            if(nums[mid] <= x){
                si = mid+1;
            }else{
                ei = mid-1;
            }
        }
        
        si--;
        return si>=0 && nums[si] == x ? si:-1;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurence(nums,target), lastOccurence(nums,target)};
    }
};