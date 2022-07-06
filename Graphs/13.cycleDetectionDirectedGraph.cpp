
// Approach 1
class Solution{

	public:

	bool checkCycle(int node,  vector<int> adj[], vector<int> &vis, vector<int> &dfsVis){

		vis[node] = true;
		dfsVis[node] = true;

		for(auto it : adj[node]){
			if(!vis[it]){
				if(checkCycle(it,adj,vis,dfsVis)) return true;
			}else if(dfsVis[it]){
				return true;
			}
		}

		dfsVis[node] = false;
		return false;
	}


	bool isCyclic(int N, vector<int> adj[]){

		vector<int> vis(N,0);
		vector<int> dfsVis(N,0);
		

		for(int i=0;i<N;i++){
			if(!vis[i]){
				if(checkCycle(i,adj,vis,dfsVis))
					return true;
			}
		}
	}

	return false;
}

// Approach 2

#include<bits/stdc++.h>
bool checkCycle(int node, unordered_map<int,list<int>> &adj,
               unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis){
    
    vis[node] = true;
    dfsvis[node] = true;
    
    for(auto nbr: adj[node]){
        if(vis[nbr] && dfsvis[nbr]){
            return true;
        }
        if(!vis[nbr]){
            bool cycleDectected = checkCycle(nbr,adj,vis,dfsvis);
            if(cycleDectected){
                return true;
            }
        }
    }
    
    dfsvis[node]  = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    
    unordered_map<int,list<int>> adj;
    // Create Adj List
    for(int i=0;i<edges.size();i++){
        
        int u =  edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfsvis;
    
    
    // Call Dfs for call components.
    for(int i=1;i<=n;i++){
        bool cycfound = checkCycle(i,adj,vis,dfsvis);
        if(cycfound){
            return true;
        }
    }
    
    return false;
}