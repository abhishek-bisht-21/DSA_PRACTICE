// TC ->  O(N* log(max-min+1))

class Solution {
public:

    bool isFeasible(vector<int> &bloomDay, int m , int k, int mid){
        int nobouquet = 0;
        int cnt = 0;

        for(int b: bloomDay){
            if(b <= mid){
                cnt++; // Count of Consecutive flowers which have bloomed.
            }else{
                nobouquet += cnt/k;   // 1 Bouquets must contain k flowers.
                cnt=0;
            }
        }

        nobouquet += cnt/k; // There can be possibility we have traversed the entire array and last few flowers have bloomed and are with in mid range.
        return nobouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int minDay = *min_element(bloomDay.begin(), bloomDay.end()); // Low 
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end()); // High
        int ans = -1;
       
        while(minDay <= maxDay){
            int mid = minDay + (maxDay - minDay) / 2;

            if(isFeasible(bloomDay, m, k, mid)){
                ans = mid;
                maxDay = mid-1;
            }else{
                minDay = mid+1;
            }
        }

        return ans;
    }
};