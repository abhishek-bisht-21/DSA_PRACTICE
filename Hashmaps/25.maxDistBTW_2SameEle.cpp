// Max distance between same elements 


class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    //Code here
    
        unordered_map<int,int> m; // Value, Index
        int mLen = 0;
        
        for(int i=0;i<n;i++){
            if(m.find(arr[i]) == m.end())
                m[arr[i]] = i;
            else
                {
                    int len = i - m[arr[i]];
                    mLen = max(mLen,len);
                }
        }
        
        return mLen;
    }
};
