// Count of Equivalent Subarrays

class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>mp;
        unordered_set<int>st;
        
        for(int i=0;i<n;i++)
            st.insert(arr[i]);
        
        int distinctEleCount = st.size();
        int count=0;
        int i=0,j=0;
        
        while(j<n){
        
        // Keep Acquiring till map size is equal to distinctEleCount
        while(i<n && mp.size()<distinctEleCount){
             mp[arr[i]]++;
             i++;
        } 
        
        // Count SubArrays   
        if(mp.size()==distinctEleCount)
            count+=(n-i+1);
        
        // Release
        mp[arr[j]]--;
        if(mp[arr[j]]==0){
            mp.erase(arr[j]);
        }
        j++;
            
        }
        
        return count;
    }

};