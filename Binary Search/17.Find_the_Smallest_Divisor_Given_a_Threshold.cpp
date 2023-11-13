// 1283. Find the Smallest Divisor Given a Threshold

class Solution {
public:
    
    
    int divisorSum(vector<int> &nums,int divisor){
        int sum = 0;
        
        for(int ele:nums){
            int x = ceil(ele*1.0/divisor);
            sum+=x;
        }
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high =  *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int ans = -1;
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            int sum = divisorSum(nums,mid); 
            
            if(sum <= threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};