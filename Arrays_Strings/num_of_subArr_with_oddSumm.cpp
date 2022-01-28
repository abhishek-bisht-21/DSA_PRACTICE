// ________________________1524. Number of Sub-arrays With Odd Sum_____________________

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long ans = 0;
        
        int even = 0;
        int odd = 0;
        int sum = 0;
        
        for(int ele: arr){
            sum+=ele;
            if(sum % 2 == 0){
                ans+=odd;
                even++;
            }else{
                ans+=even+1;
                odd++;
            }
        }
        
        return (int)(ans%1000000007);
    }
};