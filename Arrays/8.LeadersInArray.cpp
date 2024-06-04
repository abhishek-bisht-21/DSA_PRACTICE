// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
        vector<int> ans;
        int maxi = INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            if(a[i] >= maxi){
                ans.push_back(a[i]);
            }
            maxi = max(maxi,a[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};