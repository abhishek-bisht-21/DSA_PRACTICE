
// 278. First Bad Version
class Solution {
public:
    int firstBadVersion(int n) {
        
        int si = 0;
        int ei = n;
        
        while(si < ei){
            int mid = si+(ei-si)/2;
            if(isBadVersion(mid)){
                ei = mid;
            }else{
                si = mid+1;
            }
        }
        
        return   si;
    }
};