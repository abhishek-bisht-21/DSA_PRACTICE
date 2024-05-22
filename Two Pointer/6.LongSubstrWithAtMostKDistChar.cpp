
// total chars = 256
// TC -> O(N) + O(N) + O(Log(256)), SC -> O(256)
 class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int maxLen = 0;
        int right = 0;
        int left = 0;
        
        unordered_map<char, int> mpp;
        
        while(right < s.length()){
            
            mpp[s[right]]++;
            
            while(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            
            if(mpp.size() <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            
            right++;
        }
        
        return maxLen;
    }
}; 



// Approach 2: TC(O(n))

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int maxLen = 0;
        int right = 0;
        int left = 0;
        
        unordered_map<char, int> mpp;
        
        while(right < s.length()){
            
            mpp[s[right]]++;
            
            if(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            
            if(mpp.size() <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            
            right++;
        }
        
        return maxLen;
    }
};