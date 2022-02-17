class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long int x = 0;
        for(int ele: nums){
            x^=ele;
        }
        
        int rsbm = (x & (-x));
        
        int p = 0;
        int q = 0;
        
        for(int ele: nums){
            
            if((ele & rsbm) == 0){
                p^=ele;
            }else{
                q^=ele;
            }
        }
        
        if(p < q){
            return {p,q};
        }else{
            return {q,p};
        }
    }
};