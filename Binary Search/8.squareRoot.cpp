/*

 We will Create a Hypothetical array. And Apply BS on that.
 We want to find the biggest i, whose multiplication with itself 
 becomes equals or less than n.

 n -> Number whose square root we want to find.


*/


class Solution {
public:
    int mySqrt(int x) {
        
        long long int ans = -1;
        
        long long int low = 0;
        long long int high = x;
        
        while(low <= high){
            long long int mid = (low+high)/2;
            
            if(mid*mid <= x ){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};