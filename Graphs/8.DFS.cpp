
void dfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited, vector<int> &component){
    
    component.push_back(node);
    visited[node] = true;
    
    // Recurrsive Call for every connected node
    for(auto nodeNbr: adjList[node]){
        if(!visited[nodeNbr]){
            dfs(nodeNbr,adjList,visited,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,bool> visited;
    
    // Prepare Adjacencylist
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      
        
    }
    
      vector<vector<int>> ans;
        
      for(int i=0;i<V;i++){
          if(!visited[i]){
              vector<int> component;
              dfs(i,adjList,visited,component);
              ans.push_back(component);
          }
       }
    
    return ans;
    
}