// Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int> ans;
        stack<int> st;
        
        st.push(arr[0]);
        
        for(int i=1;i<N;i++){
            if(st.top() > arr[i]){
                st.push(arr[i]);
            }else{
                int temp = st.top();
                st.pop();
                if(!st.empty() && st.top() < arr[i]){
                while(!st.empty() && st.top() < arr[i]){
                    st.pop();
                }
                ans.push_back(temp);
                }
                st.push(arr[i]);
            }
        }
        ans.push_back(arr[N-1]);
        return ans;
    }
};