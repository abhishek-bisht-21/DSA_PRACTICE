// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size() - 1;
        int omax = 0;
        
        while(i < j){
            
            int w = j - i;
            
            omax = height[i] < height[j] ? max(omax,height[i++] * w) : max(omax,height[j--] * w);
            
        }
        return omax;
        
    }
};