/*

Low -> Max Weight Package cause if the capacity will be less than that, it will be impossible to ship all the packages.
High -> Sum of all Package Weights, Cause if the Capacity will be the sum of all the package weight then we can 
        definitely ship them.

We will have a daysRequired function which will give us the Number of days required if the Capacity of ship is 'M'.

*/


class Solution {
public:
    
    bool feasible(vector<int> &weights, int days, int mid){
        int daysRequired = 1;
        int wt = 0;
        
        for(int i=0;i<weights.size();i++){
            
            if(weights[i] > mid){
                return false;
            }
            
            if(weights[i] + wt > mid){
                daysRequired++;
                wt = weights[i];
                
                if(daysRequired > days){
                    return false;
                }
            }
            else{
                wt+=weights[i];
            }
        }
        
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int si = *max_element(weights.begin(), weights.end());
        int ei = accumulate(weights.begin(), weights.end(),0);
        int capacity = -1;
        
        while(si <= ei){
            int mid = si + (ei-si)/2;
            
            if(feasible(weights,days,mid)){
                capacity = mid;
                ei = mid - 1;
            }else{
                si = mid+1;
            }
        }
        
        return capacity;
    }
};