class Solution {
    bool dfs(int node, const vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &pathVisited,vector<int>& check) {        
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(dfs(it, adj, visited, pathVisited, check)){
                    return true;
                }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<int> safeNodes;
        vector<int> check(V, 0);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, pathVisited, check);
            }
        }

        for(int i = 0; i < V; i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};