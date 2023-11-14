/*  

    /       /
   /       / 
  /       /
 /       /

Ans lie in the second line only.

*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

	// We will stop when only one element is left in search space.
        while(s < e){
            int mid = s + (e-s)/2;

            // 1st Line -> First Sorted Half Ans will never lie here.
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }else{
                // 2nd Line
                e = mid;
            }
        }

        return s;
    }
};