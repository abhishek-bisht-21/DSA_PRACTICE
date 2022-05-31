// Check if two arrays are equal or not 


class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        bool ans = true;
        unordered_map<int,int> s;
        for(auto val:A){
            s[val]++;
        }
        
        for(auto val:B){
            if(s.find(val) == s.end()){
               return false;
            }
            
            s[val]--;
        }
        
        for(auto it:s) if(it.second > 0) return false;
        
        return true;
    }
};