
// 875. Koko Eating Bananas

/*

We know the range in which our answer would lie

*/
// Appraoch 1
class Solution {
public:
    
    
     bool isfeasible(vector<int>& piles, int totalHours,int bananaEatenPerHour)
    {
        double hoursTaken = 0;
        for(auto p : piles)
            hoursTaken += ceil(p*1.0/bananaEatenPerHour);
        
        return ans <= totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1; // Low
        int maxSpeed = *max_element(piles.begin(),piles.end()); // High
        int ans = -1;
        while(minSpeed <= maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed)/2;
            if(isfeasible(piles,h,mid)){
                ans = mid;
                maxSpeed = mid - 1; // We got our answer but we are trying to find the minimum possible hours in which koko can eat entire piles
            }
            else{
                minSpeed = mid + 1;
            }
        }
        
        return ans;
    }
};