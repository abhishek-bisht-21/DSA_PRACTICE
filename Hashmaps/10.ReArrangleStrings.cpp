// 767. Reorganize String

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int,char>> maxPQ;
        
        for(char str:s){
            m[str]++;
        }
        
        for(auto it:m){
            maxPQ.push({it.second,it.first});
        }
        
        string str = "";
        while(maxPQ.size() > 1){
            
            auto top1 = maxPQ.top();
            maxPQ.pop();
            auto top2 = maxPQ.top();
            maxPQ.pop();
            
            str += top1.second;
            str += top2.second;
            
            if(--top1.first > 0)
                maxPQ.push(top1);
            if(--top2.first > 0)
                maxPQ.push(top2);
        }
        
        if(maxPQ.size()){
            if(maxPQ.top().first == 1){
                str += maxPQ.top().second;
            }else{
                return "";
            }
        }
        
        return str;
    }
};