class Solution {
public:
    int reverse(int x) {
        stack<int>s;
        long int ans=0;
        while(x)
        {
            s.push(x%10);
            x=x/10;
        }
        long int i=1;
        while(!s.empty())
        {
            ans=ans+s.top()*i;
            s.pop();
            i=i*10;
        }
        if(ans <= INT_MIN or ans >= INT_MAX) return 0;
        return ans;
    }
};