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


void removeEdge(int u, int v){

}

void removeVertex(int u){

}


int main(){

	return 0;
}