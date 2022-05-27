// Longest Distinct characters in string 

int longestSubstrDistinctChars (string S)
{
    // your code here
    int l = 0;
    int r = 0;
    set<char> s;
    int mLen = 0;
    
    while(r < S.length()){
        
        if(s.find(S.at(r)) == s.end()){
             s.insert(S.at(r));
            int len = r - l + 1;
            mLen = max(mLen,len);
            r++;
           
        }else{
            s.erase(S.at(l));
            l++;
        }
    
        
    }
    
    return mLen;
}