
// Nearly sorted
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> mheap;
        
        for(int i=0;i<num;i++){
            mheap.push(arr[i]);
            if(mheap.size() > K){
                ans.push_back(mheap.top());
                mheap.pop();
            }
        }
        
        while(!mheap.empty()){
            ans.push_back(mheap.top());
            mheap.pop();
        }
        
        return ans;
    }
};