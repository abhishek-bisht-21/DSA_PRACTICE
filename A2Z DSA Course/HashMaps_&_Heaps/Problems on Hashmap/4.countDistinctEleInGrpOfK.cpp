// Acquire and Release
// Count distinct elements in every window

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        unordered_map<int, int> umap;
        
        // 1st Acquire ele till k 
        for(int i=0;i<k;i++){
            umap[arr[i]]++;
        }
        
        vector<int> res;
        res.push_back(umap.size());
        
        for(int i=k;i<n;i++){
            
            // Release
            umap[arr[i-k]]--;
            
            if(umap[arr[i-k]] == 0){
                umap.erase(arr[i-k]);    
            }
            
            // Acquire
            umap[arr[i]]++;
            
            res.push_back(umap.size());
        }
        
        return res;
    }
};