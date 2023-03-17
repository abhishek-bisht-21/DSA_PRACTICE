
// K-th Largest Sum Contiguous Subarray
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        vector<int> sumArr;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=i;j<N;j++){
                sum = sum+Arr[j];
            
            
            pq.push(sum);
            
            if(pq.size()>K){
                pq.pop();
            }
        }

    }
        return pq.top();
    }
    

};