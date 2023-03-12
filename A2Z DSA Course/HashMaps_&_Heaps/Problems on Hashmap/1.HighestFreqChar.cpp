// Maximum Occuring Character

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        map<char,int> m;
        // Your code here
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            m[ch]++;
        }
        
        int maxFreq = 0;
        pair<char,int> p;
        for(auto x:m){
            // n = x - '0';
            if(maxFreq < x.second){
                maxFreq = x.second;
                p = {x.first,maxFreq};
            }
        }
        
        return p.first;
    }

};