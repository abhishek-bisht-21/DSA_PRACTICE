class Solution {
public:
    
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int ele : arr){
            
            int val = abs(ele - x);
            pq.push(make_pair(val,ele));
        }
        
        vector<int> ans;
        int i = 0;
        while(i < k){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};