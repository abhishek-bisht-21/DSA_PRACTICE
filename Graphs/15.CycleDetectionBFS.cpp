/* 
Check if there is a cycle in a Directed Graph.

We are gonna use the reverse logic. Topological Sort is possible only for DAG (Directed Acyclic Graph)
If we are able to prove that we cannot find the topolical sort for a Directed graph we can say that graph is Cyclic.

We are gonna use Kahn's Algo (BFS Topological Sort).

*/

bool isCyclic(int N,vector<int> adj[]){

	queue<int> q;
	vector<int> inDegree(N,0);

	for(int i=0;i<N;i++){
		for(auto it : adj[i]){
			inDegree[it]++;
		}
	}

	for(int i=0;i<N;i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}

	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;

		for(auto it: adj[node]){
			inDegree[it]--;
			if(inDegree[it] == 0){
				q.push(it);
			}
		}
	}

	if(cnt == N) retun false; // We were able to create a linear ordering of vertices hence topoSort possible. Hence no cycle.

	return true;
}