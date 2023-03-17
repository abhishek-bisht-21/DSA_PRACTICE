// Approach 1 TC-> (n*k)log(n*k)
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


// Approach 2: Optimised TC-> (n*k)logk

class Solution
{
    public:
    //Function to merge k sorted arrays.
    #include <bits/stdc++.h> 


class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row, int col){
        this->data = data;
        this->i = row;
        this->j = col;
    }
};


class compare{
    public:

    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> pq;

    // Step1: Insert all the 1st Element of All the Arrays
    for(int i=0;i<k;i++){
        node* tmp = new node(kArrays[i][0], i, 0);
        pq.push(tmp);
    }

    vector<int> ans;

    //Step2: 
    while(!pq.empty()){

        node* topVal = pq.top();
        ans.push_back(topVal->data);
        pq.pop();

        int row = topVal->i;
        int col = topVal->j;

        if(col+1 < kArrays[row].size()){
            node* next = new node(kArrays[row][col+1],row,col+1);
            pq.push(next);
        }
    }

    return ans;
}

};
