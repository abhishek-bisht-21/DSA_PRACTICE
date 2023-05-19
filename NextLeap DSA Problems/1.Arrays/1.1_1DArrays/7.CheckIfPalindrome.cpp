class Solution {
public:
    bool isPalindrome(vector<int>& nums) {

        int n = nums.size();
        int i=0;
        int j = n-1;

        while(i <= j){
            if(nums[i++] != nums[j--]){
                return false;
            }
        }

        return true;
    }
};