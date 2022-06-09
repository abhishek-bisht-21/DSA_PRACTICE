// Frequency Sort

typedef pair<int,int> p;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        priority_queue<p> pq;
        map<int,int> m;
        
        for(int val:nums){
            m[val]++;
        }
        
        for(auto p: m){
            pq.push({-p.second,p.first});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            int size = abs(pq.top().first);
            while(size-- > 0){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        
        return ans;
    }
};