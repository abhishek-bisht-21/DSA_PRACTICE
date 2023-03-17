
// Merge k Sorted Arrays
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        
               vector<int>res;
        //min heap
        priority_queue<int, vector<int>, greater<int>>queue;
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                queue.push(arr[i][j]);
            }
        }
        
        while(queue.size()>0){
            res.push_back(queue.top());
            queue.pop();
        }
        return res;
    
    }
};