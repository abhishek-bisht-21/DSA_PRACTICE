// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(int val:nums){
            m[val]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto p: m){
            pq.push({p.second,p.first});
        }
        
        while(k-- > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
	
    }
};