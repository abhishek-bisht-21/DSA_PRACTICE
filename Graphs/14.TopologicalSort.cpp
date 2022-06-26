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



// BFS APPROACH