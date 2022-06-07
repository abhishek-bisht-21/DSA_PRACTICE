// 1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq; // maxHeap
        
        for(int ele:stones){
            pq.push(ele);
        }
        
        while(pq.size() > 1){
            int w1 = pq.top();
            pq.pop();
            int w2 = pq.top();
            pq.pop();
            
            int newWeight = abs(w1-w2);
            if(newWeight > 0){
                pq.push(newWeight);
            }
        }
        
        return (pq.size() == 0 ? 0:pq.top());
    }
};