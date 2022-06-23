
#include<bits/stdc++.h>

void prepareAdjList(unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> adjList,vector<int> &ans,unordered_map<int,bool> &visited,int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        // Store frontNode in the ans
        ans.push_back(frontNode);
        
        // Traverse all the neighbors of front node
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    
    prepareAdjList(adjList,edges);
    
    // Traverse all components of the Graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,ans,visited,i);
        }
    }
    
    return ans;
}