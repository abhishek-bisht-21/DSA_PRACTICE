class Solution {
    public:

   pair<int, int> LargestTwoEle(vector<int> &nums){
        int firstLar = INT_MIN;
        int secondLar = INT_MIN;

        for(int ele: nums){
            if(ele > firstLar){
                secondLar = firstLar;
                firstLar = ele; 
            }else if(ele > secondLar){
                secondLar = ele;
            }
        }

        pair<int,int> p = make_pair(firstLar,secondLar);
        return p;
    }

        pair<int, int> smallestTwoEle(vector<int> &nums){
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int ele: nums){
            if(ele < smallest){
                secondSmallest = smallest;
                smallest = ele; 
            }else if(ele < secondSmallest){
                secondSmallest = ele;
            }
        }
        pair<int,int> p = make_pair(smallest,secondSmallest);
        return p;
    } 

   int maxProductDifference(vector<int>& nums) {
       pair<int,int> p1 = LargestTwoEle(nums);
       pair<int,int> p2 = smallestTwoEle(nums);
       int prod1 = p1.first * p1.second;
       int prod2 = p2.first * p2.second;

        return abs(prod1 - prod2);

   }
};