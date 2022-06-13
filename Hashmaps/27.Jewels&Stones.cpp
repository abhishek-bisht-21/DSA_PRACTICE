
// 771. Jewels and Stones
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> uset;
        
        for(char s: jewels){
            uset.insert(s);
        }
        
        int count = 0;
        
        for(char s: stones){
            if(uset.find(s) != uset.end()){
                count++;
            }
        }
        
        return count;
    }
};