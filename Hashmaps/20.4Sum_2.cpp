
// 454. 4Sum II
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
    unordered_map<int, int> map;
    for (int e1 : A)
        for (int e2 : B)
            map[e1 + e2]++;

    int count = 0;
    for (int e1 : C)
        for (int e2 : D)
            count += map.find(-(e1 + e2)) != map.end() ? map[-(e1 + e2)] : 0;

    return count;
    }
};