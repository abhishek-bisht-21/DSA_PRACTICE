
// 1488. Avoid Flood in The City
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> m; // val, index
        set<int> zeros;
        vector<int> ans;
        
        for(int i=0;i<rains.size();i++){
            if(rains[i] == 0){
                zeros.insert(i);
                ans.push_back(1);
            }else{
                if(m.find(rains[i]) != m.end()){
                    auto next = zeros.lower_bound(m[rains[i]]);
                    if(next == zeros.end()){
                        return {};
                    }
                        ans[*next] = rains[i];
                        zeros.erase(*next);
                }
                
                ans.push_back(-1);
                m[rains[i]] = i;
                
            }
        }
        
        return ans;
    }
};