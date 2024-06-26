// 424. Longest Repeating Character Replacement

// Time Complexity :  O(n)
// Space Complexity : O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        // Base case...
        if (s.size() == 0) return 0;
        // Max length
        int maxLength = INT_MIN;
        // Make an array...
        vector <int> arr(128);
        // Initialize largestCount & beg pointer...
        int beg = 0, largestCount = 0;
        // Traverse all characters through the loop...
        for (int end = 0; end < s.size(); end++) {
            // Get the largest count of a single, unique character in the current window...
            largestCount = max(largestCount, ++arr[s[end]]);
            // We are allowed to have at most k replacements in the window...
            // So, if max character frequency + distance between beg and end is greater than k...
            // That means we have met a largest possible sequence, we can move the window to right...
            if (end - beg + 1 - largestCount > k)       // The main equation is: end - beg + 1 - largestCount...
                arr[s[beg++]]--;
            
            maxLength = max(maxLength,end-beg+1);
        }
        
        return maxLength;
    }
};