class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
        vector<int> maxRL(n,0);
        maxRL[n-1] = a[n-1];
        
        for(int i=n-2;i>=0;i--){
            if(a[i] > maxRL[i+1]){
                maxRL[i] = a[i];
            }else{
                maxRL[i] = maxRL[i+1];
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(a[i] >= maxRL[i]){
                ans.push_back(a[i]);
            }
        }
        
        return ans;
        
    }
};
