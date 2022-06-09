// 506. Relative Ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<size(score);i++)
            pq.push({score[i],i});
        
        int i=0;
        
        vector<string> ans(size(pq));
        
        while(!pq.empty()){
            
            ans[pq.top().second] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ?
                "Bronze Medal":to_string(i+1);
            i++;
            pq.pop();
        }
        
        return ans;
    }
};