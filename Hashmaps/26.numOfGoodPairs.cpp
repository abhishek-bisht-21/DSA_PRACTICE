// 1512. Number of Good Pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> umap;
        for(int val : nums){
            umap[val]++;
        }
        
        for(auto p: umap){
            if(p.second > 1){
                int val = (p.second * (p.second - 1))/2;
                ans += val;
            }
        }
        
        return ans;
    }
};