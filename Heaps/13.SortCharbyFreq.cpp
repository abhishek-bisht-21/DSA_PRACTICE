// 451. Sort Characters By Frequency

typedef pair<int,char> p;
class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> m;
        priority_queue<p> pq;
        
        for(auto str:s){
            m[str]++;
        }
        string ans;
        
        for(auto p:m){
            pq.push({p.second,p.first});
        }
        
        while(!pq.empty()){
            int size = abs(pq.top().first);
            while(size-- > 0){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        
        return ans;
    }
};