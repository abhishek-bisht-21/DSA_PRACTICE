
// Number of Excellent Pairs
class Solution {
public:
    typedef long long ll;
    int setbits(int n){
        int cnt = 0;
        while(n){
            cnt += (n%2);
            n /= 2;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
		// Removing Duplicates
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v;
		// Storing set bits in vector v
        for(auto& i: s){
            int x = setbits(i);
            v.push_back(x);
        }

		// Sorting the vector so that we can apply BinarySearch or Lower_bound
        sort(v.begin(),v.end());
        
        	//Now for each set bit x find a corresponding set bit y such that x + y >= k
		// if x = v[i] then y = v[i] - k
		//since the vector is sorted so for each x find y using binary search
		//now x and y will form a pair but each element after y will also form a pair with x because vector is sorted in ascending order 
		//so if x + y >= k then for each z > y     x +z >= k 
		//so in ans add v.size() - index of y
        ll ans = 0;
        for(int i=0;i<v.size();i++){
            auto it = lower_bound(v.begin(),v.end(),k-v[i]);
            ans += (v.end()-it);
        }
        return ans;
        
    }
};