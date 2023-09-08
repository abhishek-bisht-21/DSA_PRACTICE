

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int maxLen = 0;
        unordered_map<int, int> m; // sum,index
        m[0] = -1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum) != m.end()){
                auto it = m.find(sum);
                int len = i-it->second;
                maxLen = max(maxLen,len);
            }else{
                m[sum] = i;
            }
            
        }
        
        return maxLen;
    }
};
