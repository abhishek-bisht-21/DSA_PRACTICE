// 904. Fruit Into Baskets -> Max len Subarray with at most 2 typpes of numbers
// TC -> O(2*N), SC -> O(2). Map size is small so Log(2) ~ Log(3) == 1
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Initialising a map for keeping count of distinct fruits
        map<int,int> fruit_count;

        // i is front pointer of sliding window
        // j is rear pointer of sliding window
        // ans will store the maximum subarray length
        int i=0,j=0,ans=0;
        while (i<fruits.size())
        {
            // picking up the fruit
            fruit_count[fruits[i]]++;
            // if no. of distinct fruits is more than two
            // we will move our rear pointer and unpick the fruits
            while (fruit_count.size()>2)
            {
                fruit_count[fruits[j]]--;
                // if fuit of a particular type are exhausted
                // clearing the index of that fruit
                if (fruit_count[fruits[j]]==0) {
                    fruit_count.erase(fruits[j]);
                }
                // moving rear pointer
                j++;
            }
            // Storing maximum subarray length with at most 2 distinct fruits
            ans=max(ans,i-j+1);
            // moving front pointer
            i++;
        }
        // returning the maximum subarray length
        return ans;
    }
};



// Optimal Solution
// TC -> O(N)
// Once we get a maxLength We are not allowing it go further than that till we have valid condition.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int left = 0;
        int right = 0;

        int n = fruits.size();
        int maxLen = 0;

        while(right < n){
            mpp[fruits[right]]++;

            if(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }

            if(mpp.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }


        return maxLen;
    }
};