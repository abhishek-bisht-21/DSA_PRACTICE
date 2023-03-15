// 2357. Make Array Zero by Subtracting Equal Amounts
class Solution {
public:
int minimumOperations(vector<int>& nums) {
    priority_queue<int , vector<int> , greater<int>> minH(nums.begin() , nums.end());
    int curr_min = 0;
    int ans = 0;
    while(!minH.empty()){
        if(minH.top() == 0) minH.pop();
        else{
            int tp = minH.top() - curr_min;
            if(tp != 0){
                curr_min += tp;
                ans++;
            }
            minH.pop();  
        }
    }
    return ans;
}
};