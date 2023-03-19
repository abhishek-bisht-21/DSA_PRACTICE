
// Zero Sum Subarrays
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        int count = 0;
        int pSum = 0;
        unordered_map<int,int> m; // sum, count
        m[0] = 1;
        
        
        
        for(int val:arr){
            pSum += val;
            
            if(m.find(pSum) != m.end()){
                count += m[pSum];
            }
            
            m[pSum]++;
        }
        
        return count;
    }
};