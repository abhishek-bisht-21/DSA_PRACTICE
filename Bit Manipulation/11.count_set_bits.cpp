class Solution {
public:
    vector<int> countBits(int N) {
               
        vector<int> ans;
        for(int i=0;i<=N;i++){
        int n = i;
        int cnt = 0;    
        while(n != 0){
            cnt++;
            n = (n & (n-1));
        }
            
            ans.push_back(cnt);
    }    
        return ans;
    }
};