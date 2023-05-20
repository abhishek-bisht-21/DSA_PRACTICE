
// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0,totalAcceptableSum= threshold*k;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(i < k-1) continue;
            if(i > k-1){
                sum -= arr[i-k];
            }

            if(sum >= totalAcceptableSum){
                cnt++;
            }
        }

        return cnt;
    }
};