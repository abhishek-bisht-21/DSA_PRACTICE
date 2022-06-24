#include <iostream>
#include <vector>

using namespace std;


class Edge{

	public:
	  
	  int v = 0;
	  int w = 0;

	  Edge(int v, int w){
		this->v = v;
		this->w = w;  
	  }

};

const int N = 7;
vector<vector<Edge>> graph(N);

void addEdge(int u, int v, int w){
	graph[u].push_back(Edge(v,w));
	graph[v].push_back(Edge(u,w));
}


void constructGraph(){
	addEdge(0,1,10);
	addEdge(0,3,10);
	addEdge(1,2,10);
	addEdge(3,4,40);
	addEdge(4,5,2);
	addEdge(4,6,8);
	addEdge(5,6,3);

}

void displayGraph(){

	for(int i=0;i<N;i++){
		cout << i << " -> "

		for(Edge e: graph[i]){
			cout << "(" + to_string(e.v) + ',' + to_string(e.w) + ") ";
		}

		cout << endl;	
	}
}


int findEdge(int u, int v){
	int idx = -1;
	for(int i=0;i<graph[u].size();i++){

		if(graph[u][i].v == v){
			idx = i;
			break;
		}
	}

	return idx;
}

void removeEdge(int u, int v){
	int idx1 = findEdge(u,v);
	int idx2 = findEdge(v,u);

	graph[u].erase(graph[u].begin()+idx1);
	graph[v].erase(graph[v].begin()+idx2);
}

void removeVertex(int u){

	for(int i = graph[u].size()-1; i >=0; i--){
		int v = graph[v][i].v;
		removeEdge(u,v);
	}
}


bool hasPath(int src, int dest, vector<bool> &vis){

	if(src == dest){
		return true;
	}

	// 1. Mark yourself visited. 
	vis[src] = true;
	bool res = false;
	// 2. For all the Unvisited Neighbours call DFS
	for(Edge e: graph[src]){
		if(!vis[e.v]){
		   res = res || hasPath(e.v,dest,vis);	
		}
		
	}

	return true;
}

int printAllPaths(int src, int dest, vector<bool> &vis, string psf){

	if(src == dest){
		cout << "Path from src to dest :" << psf << dest << endl;
		return 1;
	}

	vis[src] = true;
	int count = 0;
	for(Edge e: graph[src]){
		if(!vis[e.v]){
			count+= printAllPaths(e.v,dest,vis,psf + to_string(src) + " ");
		}
	}
	vis[src] = false;

	return count;
}

// Heavy Path / Costly Path -> Print Path and Its Weight

int main(){

	return 0;
}