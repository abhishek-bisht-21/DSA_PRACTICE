// 1464. Maximum Product of Two Elements in an Array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        
        for(int ele:nums){
            pq.push(ele);
        }
        
        int ans = 1;
        int p1 = pq.top(); pq.pop();
        int p2 = pq.top(); pq.pop();
        
        ans = ((p1-1) * (p2-1));
        
        return ans;
    }
};