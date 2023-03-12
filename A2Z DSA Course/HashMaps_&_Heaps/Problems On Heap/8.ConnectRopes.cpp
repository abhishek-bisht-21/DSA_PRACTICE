
// Connect Ropes to Minimise the Cost
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
        
        long long cost = 0;
        while(pq.size() != 1){
            long long rope1 = pq.top(); 
            pq.pop();
            long long rope2 = pq.top(); 
            pq.pop();
            
            auto newRope = rope1 + rope2;
            
            pq.push(newRope);
            cost+=newRope;
        }
        
        return cost;
    }
};