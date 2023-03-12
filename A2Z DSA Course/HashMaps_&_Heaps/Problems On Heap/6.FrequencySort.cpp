// 1636. Sort Array by Increasing Frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        priority_queue<pair<int,int>> pq;

        for(int ele:nums){
            m[ele]++;
        }

        for(auto p:m){
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