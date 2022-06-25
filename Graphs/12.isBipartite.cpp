// 785. Is Graph Bipartite?


// BFS SOLution

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


// is BIPARTITE DFS


class Solution{

	public:

 bool BipartiteDFS(int src,vector<int> adj[], int color, vector<int> &vis){
        
        vis[src] = color;
        
        for(auto it : adj[src]){
            if(vis[it] == -1){
                if(!BipartiteDFS(it,adj,!color,vis)) return false;
            } else if(vis[it] == color){
                return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int n = adj->size();
	    vector<int> vis(V,-1);
	   // int color = 1;
	    
	    for(int i=0;i<V;i++){
	        if(vis[i] == -1){
	            if(!BipartiteDFS(i,adj,0,vis)){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};