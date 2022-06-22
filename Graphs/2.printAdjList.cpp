class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        
      vector<vector<int>> v;
      vector<int> row;
      
      row.reserve(10000+1);
      for(int i=0;i<V;i++)
      {
          row.push_back(i);
          for(int j=0;j<adj[i].size();j++)
          {
              row.push_back(adj[i][j]);
          }
          
          v.push_back(row);
          row.clear();
      }
      
      return v;
    }
};