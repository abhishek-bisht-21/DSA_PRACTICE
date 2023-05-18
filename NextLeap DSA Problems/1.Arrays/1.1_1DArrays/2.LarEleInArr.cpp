class Solution {
    public:
   int findLargestElement(vector<int>& nums) {
       int larEle = nums[0];

       for(int i=1;i<nums.size();i++){
           if(nums[i] > larEle){
               larEle = nums[i];
           }
       }

       return larEle;
   }
};