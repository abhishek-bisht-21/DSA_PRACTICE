// 785. Is Graph Bipartite?
class Solution {
public:
    
    
    bool BipartiteBFS(int src, vector<vector<int>>& graph,vector<int> &color){
        
        queue<int> q;
        q.push(src);
        color[src] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size(),-1);
        
        int n = graph.size();
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!BipartiteBFS(i,graph,color)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};