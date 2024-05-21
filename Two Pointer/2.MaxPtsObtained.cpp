
// 1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        
        vector<int> cummulativeSumFromFront(n+1, 0);
        vector<int> cummulativeSumFromBehind(n+1, 0);
        
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            cummulativeSumFromFront[i+1] = sum;
        }
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += cardPoints[i];
            cummulativeSumFromBehind[i] = sum;
        }
        
        // Reversing is optional. I reversed it so that it would be easy
        // to access sum of last (k-i) elements by just indexing at [k-i]
        // Otherwise, I would have had to index it at [n-k+i] which would
        // have made it difficult to read.
        reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
        
        int answer = 0;
        for(int i=0; i<=k; i++) {      
            answer = max(answer, 
                           cummulativeSumFromFront[i] // Sum of first 'i' cards.
                         + cummulativeSumFromBehind[k-i]); // Sum of last 'k-i' cards.
        }
        return answer;
    }
};

// Approach 2: Using 2 Pointers (Acquire and Release)
/**
 * Time Complexity: 
 * 
*/


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;

        int maxSum = INT_MIN;
        int sum = 0;

        for(int i=0;i<k;i++){
            leftSum += cardPoints[i];
        }

        maxSum = leftSum;

        int n = cardPoints.size();
        int rightIdx = n-1;

        for(int i=k-1;i>= 0;i--){
            leftSum-=cardPoints[i];
            rightSum += cardPoints[rightIdx--]; 
            maxSum = max(maxSum, leftSum+rightSum);
        }

        return maxSum;
        
    }
};