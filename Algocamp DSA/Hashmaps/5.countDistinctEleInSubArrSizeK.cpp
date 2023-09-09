class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> m;
        
        // 1st acquiring first K elements
        for(int i=0;i<k;i++){
            m[A[i]]++;
        }
        
        vector<int> res;
        res.push_back(m.size()); // Storing the unique elements in that window
        
        for(int i=k;i<n;i++){
            
            // Release
            m[A[i-k]]--;
            
            if(m[A[i-k]] == 0){
                m.erase(A[i-k]);
            }
            
            // Acquire
            m[A[i]]++;
            
            res.push_back(m.size()); // Storing the unique elements of next window
        }
        
        return res;
    }
};