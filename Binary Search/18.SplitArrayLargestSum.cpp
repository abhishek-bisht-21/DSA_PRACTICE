// 410. Split Array Largest Sum

class Solution {
public:
    
    bool num_Sub_Arr_Keeping_limit(vector<int> arr,int sumLimit,int m){
        int cnt = 1;
        int sum = 0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] > sumLimit) return false;
            
            if(sum+arr[i] > sumLimit){
                cnt++;
                sum = arr[i];
            }else{
                sum+=arr[i];
            }
        }
        
        return cnt <= m;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        
        int sum = 0;
        for(int ele: nums){
            sum+=ele;
        }
        int high = sum;
        int ans = 0;
        
        while(low<=high){
		
	// Mid will be the sum limit which we will pass. 
            int mid = (low+high)/2;
            
            if(num_Sub_Arr_Keeping_limit(nums,mid,m) == false){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        
        return ans;
    }
};