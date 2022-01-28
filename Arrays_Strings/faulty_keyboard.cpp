//__________________________ Leetcode 925__________________________

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i=0;
        int j=0;
        
        while(j < typed.length()){
            
            if(i < name.size() and name[i] == typed[j]){
                i++;
                j++;
            }
            else if(j > 0 and typed[j-1] == typed[j]){
                    j++;
                }
            else{
                return false;
            }
            
            
        }
        
       return i == name.size();
        
        
    }
};