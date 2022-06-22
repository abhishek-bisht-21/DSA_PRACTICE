#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class graph{

public:
	unordered_map<int,list<int>> adj; // Adjacency List

	void addEdge(int u, int v,bool direction){
		// Direction = 0 -> Undirected
		// Direction = 1 -> Directed Graph

		// Create an edge from u to v
		adj[u].push_back(v);

		if(direction == 0){
			adj[v].push_back(u);
		}
	}

	void printAdjList(){
		for(auto i:adj){
			cout << i.first << "-> ";
			for(auto j:i.second){
				cout<<j<<", ";
			}

			cout << endl;
		}
	}


};

int main(){


	int n;
	cout << "Enter the number of Nodes: ";
	cin >> n;
	int m;
	cout << "Enter the number of Edges: ";
	cin>> m;

	graph g;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		g.addEdge(u,v,0);
	}

	g.printAdjList();

	return 0;
}