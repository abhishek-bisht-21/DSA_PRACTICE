// Zero Sum Subarrays

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<int, int> m; // Sum,Count
        m[0] = 1;
        int pSum = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            pSum+=arr[i];
            
            if(m.find(pSum) != m.end()){
                count+=m[pSum];
            }
            
            m[pSum]++;
        }
        
        return count;
    }
};