class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        
        int mask = (1 << k);
        
        int ans = (mask & n);
        
        if(ans == 0){
            return false;
        }else{
            return true;
        }
    }
};
