
// APPROACH 1 : BFS
#include<bits/stdc++.h>
bool isCyclicBFS(int src, unordered_map<int,bool> &visited,unordered_map<int, list<int>> &adj){
    
    unordered_map<int,int> parent;
    
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto nbr: adj[frontNode]){
            if(visited[nbr] && nbr != parent[frontNode]){
                return true;
            }
            
            else if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = frontNode;
            }
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    // Creating Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);      
    }
    
    unordered_map<int,bool> visited;
    
    // To handle disconnected Component
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i,visited,adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    
    return "No";
}


// APPROACH 2 : DFS

bool isCyclicDFS(int src,int parent,unordered_map<int,bool> &visited,unordered_map<int, list<int>> &adj){
    
    visited[src] = true;
    
    for(auto nbr: adj[src]){
        if(!visited[nbr]){
            bool cycleDetected = isCyclicDFS(nbr,src,visited,adj);
            if(cycleDetected)
                return true;
        }else if(nbr != parent){
            // Cycle parent
            return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    // Creating Adjacency List
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);      
    }
    
    unordered_map<int,bool> visited;
    
    // To handle disconnected Component
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    
    return "No";
}
