
// Maximum Difference of zeros and ones in a Binary String
class Solution {
public:
	int getMaxDifference(string s) {
		// Your code goes here

		int n = s.length();
		int bag = 0;
		int ans = INT_MIN;

		for(int i=0;i<n;i++){
			if(s[i] == '1'){
				bag -= 1;
			}else {
				bag += 1;
			}
			ans = max(ans,bag);
			if(bag < 0 ) bag = 0;
		}
		return ans;
	}
};