
// 841. Keys and Rooms

// Is there a single component in the Graph or not.

// Approach 1:
class Solution {
public:

    void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

// Approach 2:

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> seen;
        dfs(rooms, 0, seen);
        return seen.size() == rooms.size();
    }
    void dfs(vector<vector<int>>& rooms, int src, unordered_set<int>& seen) {
        if (seen.count(src)) return;
        seen.insert(src);
        for (int room : rooms[src]) {
            dfs(rooms, room, seen);
        }
    }
};