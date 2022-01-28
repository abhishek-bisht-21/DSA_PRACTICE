class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int csum = 0;
        int osum = INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            
            csum+=arr[i];
            
            if(csum < arr[i]){
                csum = arr[i];
            }
            
            osum = max(osum,csum);
        }
        
        return osum;
    }
};