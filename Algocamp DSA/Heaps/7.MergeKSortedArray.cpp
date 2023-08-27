/* 

Approach 1: 
Merge All the k Arrays in one single array TC-> O(n*k)
Sort the array TC -> n*kO(n*k)

*/


// Approach 2 
//TC -> O(n*klogk) + O(klogk) => O(n*klogk)
// SC -> o(k)

    class Node{
        public: 
        int data;
        int row;
        int col;
        
        Node(int data, int row,int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    
    class compare{
        public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        
        // Step1: Sare arrays k first element insert krne h
        // TC -> O(klogk)
        for(int i=0;i<K;i++){
            Node* temp = new Node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        
        // Step2: Pop the smallest element and push next element in that row in the heap.
	// Remaining array elements n*k-k => n*k
	// Assumming n elements in the every array and k arrays are there.
        // TC -> O(n*klogk)
        while(!minHeap.empty()){
            
            Node* node = minHeap.top();
            ans.push_back(node->data);
            minHeap.pop();
            
            int row = node->row;
            int col = node->col;
            
            if(col+1 < arr[row].size()){
                Node* next = new Node(arr[row][col+1], row, col+1);
                minHeap.push(next);
            }
        }
        
        return ans;
    }
};