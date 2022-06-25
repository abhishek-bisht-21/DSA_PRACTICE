

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