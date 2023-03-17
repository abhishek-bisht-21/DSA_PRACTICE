
// Approach 1: Merge Randomly and Then Call Heapify on Internal Nodes.
class Solution{
    public:
    
    // 0 based indexing.
    void Heapify(vector<int> &arr, int n, int index){
        int largest = index;
        int lci = 2*index+1;
        int rci = 2*index+2;
        
        if(lci < n and arr[largest] < arr[lci]){
            largest = lci;
        }
        
        if(rci < n and arr[largest] < arr[rci]){
            largest = rci;
        }
        
        if(largest != index){
            swap(arr[largest], arr[index]);
            Heapify(arr,n,largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int> arr;
        // Step1: Merge both the Vector. TC-> O(m+n)
        for(int ele:a){
            arr.push_back(ele);
        }
        
        for(int ele:b){
            arr.push_back(ele);
        }
        
        int size = arr.size();
        
        // Step2: Call Heapify on merged Vector.
        for(int i = size/2-1; i>=0; i--){
            Heapify(arr, size, i);
        }
        
        return arr;
    }
};

// Approach 2: Use Priority queue

 vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int> q;
        for(int i:a){
            q.push(i);
        }
        for(int i: b){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }