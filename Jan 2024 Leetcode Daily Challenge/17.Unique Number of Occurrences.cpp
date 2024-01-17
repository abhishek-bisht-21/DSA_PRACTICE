// 1207. Unique Number of Occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        unordered_set<int> s;


        for(int ele: arr){
            umap[ele]++;
        }

        for(auto ele: umap){
            s.insert(ele.second);
        }

        return umap.size() == s.size();
    }
};