// 525. Contiguous Array

// Treat 0 as -1 and 1 as 1 only.
//  And Find out the sum. If Sum repeats itself then it means, meanwhile all the values which have appeared
// have equal number of 0s and 1s. So Find out the Length

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m; // sum,index
        
        m[0] = -1;
        int mLen = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                sum+=-1;
            }else{
                sum+=1;
            }
            
            if(m.find(sum) != m.end()){
                int len = i - m[sum];
                mLen = max(mLen,len);
            }else{
                m[sum] = i;
            }
        }
        
        return mLen;
    }
};