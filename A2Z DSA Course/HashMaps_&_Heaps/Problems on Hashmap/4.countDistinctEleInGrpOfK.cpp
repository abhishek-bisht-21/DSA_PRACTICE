// Acquire and Release
// Count distinct elements in every window
class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        
        unordered_map<int,int> m;
        
        for(int i=0;i<k;i++){
            m[arr[i]]++;
        }
        
        vector<int> res;
        res.push_back(m.size());
        
        for(int i=k;i<n;i++){
            
            m[arr[i-k]]--;
            
            if(m[arr[i-k]] == 0){
                m.erase(arr[i-k]);
            }
            
            m[arr[i]]++;
            
            res.push_back(m.size());
        }
        
        return res;
    }
};