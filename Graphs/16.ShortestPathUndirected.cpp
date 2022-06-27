/*

No visited Array will be used in this BFS, cause in this BFS we will Update the Already existing
Value in the Distance Array only when the current value we are proposing is less than the already
stored value.

*/

void BFS(vector<int> adj[],int N, int src){

	int dist[N];

	for(int i=0;i<N;i++){
		dist[i] = INT_MAX;
	}

	queue<int> q;

	dist[src] = 0;
	q.push(src);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto it : adj[node]){
			if(dist[it] > dist[node] + 1){
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}

	for(int i=0;i<N;i++){
		cout << dist[i] << " ";
	}


}