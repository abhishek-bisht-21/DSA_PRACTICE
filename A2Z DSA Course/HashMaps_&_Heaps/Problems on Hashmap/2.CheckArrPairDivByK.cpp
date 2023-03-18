class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int, int> m;
        
        for(int ele: arr){
            int rem  = ele % k;
            if(rem<0){
                rem+=k;
            }
            m[rem]++;
        }
        
        
        for(int val: arr){
            
            int rem = val % k;
            
            if(rem == 0){
                int freq = m[rem];
                if(freq % 2 == 1){
                    return false;
                }
            }
            
            else if(2*rem == 0){
                int freq = m[rem];
                if(freq % 2 == 1){
                    return false;
                }
            }else{
                int fq = m[rem];
                int ofq = m[k-rem];
                
                if(fq != ofq){
                    return false;
                }
            }
        }
        
        return true;
    }
};