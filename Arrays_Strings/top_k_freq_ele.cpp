

// _________________________347. Top K Frequent Elements____________________

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        priority_queue<pair<int,int>> pq;
        
        for(int ele : nums){
            m[ele]++;
        }
        
        for(auto ele : m){
            pq.push(make_pair(ele.second,ele.first));
        }
        
        vector<int> ans;
        int i = 0;
        
        while(i < k){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return ans;
    }
};