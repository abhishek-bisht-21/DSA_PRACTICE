
// 290. Word Pattern
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        istringstream strcin(str);
        string s;
        vector<string> vs; 
        // Storing word in the vector
        while(strcin >> s) vs.push_back(s);
        
        if (pattern.size() != vs.size()) return false;
        
        map<char, string> c2s;
        map<string, bool> used;
        
        for(int i=0;i<pattern.length();i++){
            
            char ch = pattern.at(i);
            // Char is coming for the first time
            if(c2s.find(ch) == c2s.end()){
                // Char is coming for first time and string is already used.
                if(used[vs[i]] == true){
                    return false;
                }
                // Char and string both are seen for the first time.
                else{
                    used[vs[i]] = true;
                    c2s[ch] = vs[i];
                }
            }
            // char already present
            else{
                string mwith = c2s[ch];
                // Mismatch of string. 
                // char associated with different string earlier.
                if(mwith != vs[i]){
                    return false;
                }
            }
        }
       
        return true;
    }
};