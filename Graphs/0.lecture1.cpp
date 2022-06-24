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
	addEdge(0,1,10);
	addEdge(0,1,10);
	addEdge(0,1,10);
	addEdge(0,1,10);
	addEdge(0,1,10);
	addEdge(0,1,10);

}


int main(){

	return 0;
}