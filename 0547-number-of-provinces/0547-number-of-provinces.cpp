class Solution {
    void bfs(int i, vector<vector<int>>& adjList, vector<int>& vis){
        vis[i] = 1;
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neigh : adjList[node]){
                if(!vis[neigh]){
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
    }
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjList(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                // bfs(i, adjList, vis);
                dfs(i, adjList, vis);
            }
        }
        return cnt;
    }
};