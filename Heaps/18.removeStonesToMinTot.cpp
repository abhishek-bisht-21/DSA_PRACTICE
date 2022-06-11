

// 1962. Remove Stones to Minimize the Total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int ele : piles){
            pq.push(ele);
        }
        
        while(k-- > 0){
            int val = pq.top();
            pq.pop();
            val = val - val/2;
            if(val > 0)
                pq.push(val);
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
        
    }
};