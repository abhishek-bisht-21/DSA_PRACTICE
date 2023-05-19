class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> pow2;
        pow2.push_back(1);
        for(int i=1;i<=21;i++){
            // creating an array which will contain pow of 2 till 2^21
            pow2.push_back(pow2.back()*2); 
        }

        unordered_map<int, int> m; // ele, freq;
        long long int ans = 0;

        for(int x: deliciousness){
            for(int i: pow2){
                // x + y = 2^p
                // y = 2^p - x
                if(m.find(i-x) != m.end()){ // finding that y in the map
                    ans += m[i-x];
                }
            }
            // There can be duplicates in the map as well 
            // And so that we don't double count it, so we are not updating the map
            // initially
            m[x]++;
        }


        return ans % (int)(1e9+7);
    }
};