
// 1684. Count the Number of Consistent Strings
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> uset;
        for(char s: allowed){
            uset.insert(s);
        }
        int count = 0;
        bool flag = true;
        for(string s: words){
            string str = s;
            int len = str.length();
                        flag = true;

            for(int i=0;i<len;i++){
                if(uset.find(str[i]) == uset.end()){
                    flag = false;
                    break;
                }
                
               
            }
             if(flag){
                    count++;
                }
        }
        
        return count;
    }
};