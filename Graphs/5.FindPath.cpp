// 1971. Find if Path Exists in Graph

class Solution {
public:
    
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        unordered_map<int,list<int>> adjList;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<int> q;
        unordered_map<int,bool> visited;
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            if(frontNode == destination){
                return true;
            }
            
            for(auto node: adjList[frontNode]){
                if(!visited[node]){
                    q.push(node);
                    visited[node]  = true;
                }
            }
        }
        
        return false;
    }
};