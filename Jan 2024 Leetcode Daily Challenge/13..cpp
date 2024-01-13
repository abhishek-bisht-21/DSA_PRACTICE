// 1347. Minimum Number of Steps to Make Two Strings Anagram
#include <bits/stdc++.h>

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> umap;

        for(auto x: s){
            umap[x]++;
        }

        int ans = 0;

        for(auto x: t){
            if(umap.find(x) == umap.end()){
                ans++;
            }else{
                umap[x]--;
                if(umap[x] == 0){
                    umap.erase(x);
                }
            }
        }

        return ans;
    }
};