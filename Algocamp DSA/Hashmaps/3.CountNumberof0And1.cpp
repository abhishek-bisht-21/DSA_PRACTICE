// Subarrays with equal 1s and 0s
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
        int sum = 0;
        long long int ans = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                sum-=1;
            }else{
                sum+=1;
            }
            
            if(umap.find(sum) != umap.end()){
                ans += umap[sum];
                umap[sum]++;
            }else{
                umap[sum] = 1;    
            }
        }
        
        return ans;
    }
};