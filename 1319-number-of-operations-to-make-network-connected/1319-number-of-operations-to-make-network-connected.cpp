class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
        vis[u] = true;
        for(int neigh : adj[u]){
            if(!vis[neigh]) dfs(neigh, adj, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        vector<bool> vis(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int x = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                x++;
            } 
        }
        return x-1;
    }
};