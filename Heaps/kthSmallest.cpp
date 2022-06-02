// Kth smallest element 


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int>pq;
        int n = r - l + 1;
        
        for(int i=0;i<n;i++){
            
            if(pq.size() > k-1){
                if(pq.top() > arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }else{
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};