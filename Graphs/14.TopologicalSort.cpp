// Linear Ordering of vertices such that if there is an Edge
//  u -> v , u appears before v	in that ordering.
//  There can be multiple Topological Sort for a graph.
// Topological Sort is applicable on Directed Acyclic Graphs.(DAG)

// DFS APPROACH

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void findTopoSort(int node,vector<int> &vis, stack<int> &s,vector<int> adj[]){
	    
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            findTopoSort(it,vis,s,adj);
	        }
	    }
	    
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> s;
	    
	    for(int i=0;i<V;i++){
	        if(vis[i] == 0){
	            findTopoSort(i,vis,s,adj);
	        }
	    }
	    
	    vector<int> topoSort;
	    while(!s.empty()){
	        topoSort.push_back(s.top());
	        s.pop();
	    }
	    
	    return topoSort;
	}
};


#include<bits/stdc++.h>
void topoSortDFS(int node,unordered_map<int,list<int>> &adj,stack<int> &st,vector<int> &vis){
    
    vis[node] = 1;

    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            topoSortDFS(nbr,adj,st,vis);
        }
    }
    st.push(node);
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
     vector<int> vis(v,0);
      stack<int> st;
      vector<int> ans;
      unordered_map<int,list<int>> adj;  
     // Create Adjacency List
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    for(int i=0;i<v;i++){
        if(vis[i] == 0){
            topoSortDFS(i,adj,st,vis);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}



// BFS APPROACH -> Kahn's Algorithm

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    queue<int> q;
	    vector<int> inDegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int frontNode = q.front();
	        q.pop();
	        topo.push_back(frontNode);
	        
	        for(auto it: adj[frontNode]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo;
	}
};