

// Largest subarray with 0 sum

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int maxLen = 0;
        unordered_map<int, int> m; // sum,index
        m[0] = -1; // It is neccessary when we will encounter Sum=0 for 1st time.
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }else{
                auto it = m.find(sum);
                int len = i-it->second;
                maxLen = max(maxLen,len);
            }
            
        }
        
        return maxLen;
    }
};
