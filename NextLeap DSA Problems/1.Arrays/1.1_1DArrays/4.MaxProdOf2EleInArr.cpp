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


    int maxProduct(vector<int>& nums) {

        pair<int, int> largestElePair = LargestTwoEle(nums);
        pair <int, int> smallestElePair = smallestTwoEle(nums);

        int prod1 = (largestElePair.first-1) * (largestElePair.second-1);
        int prod2 = (smallestElePair.first-1) * (smallestElePair.second-1);

        return prod1 > prod2 ? prod1 : prod2;      
    }
};