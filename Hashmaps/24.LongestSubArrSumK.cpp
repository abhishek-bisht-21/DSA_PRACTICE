// Longest Sub-Array with Sum K 

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        
        unordered_map<int,int> m; //sum, index
        int sum = 0;
        m[0] = -1;
        int maxLen = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(m.find(sum - k) != m.end()){
                int len = i - m[sum-k];
                maxLen = max(maxLen,len);   
            }
            if(m.find(sum)==m.end())
                m[sum]=i;
            
            
        }
        
        return maxLen;
    } 

};