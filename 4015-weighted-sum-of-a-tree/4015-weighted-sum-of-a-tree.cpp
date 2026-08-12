class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> depth(n, 0);
        queue<int> q;
        q.push(0);
        depth[0] = 1;
        int max_h = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                depth[v] = depth[u] + 1;
                max_h = max(max_h, depth[v]);
                q.push(v);
            }
        }
        long long totalWeight = 0;
        for(int i = 0; i < n; i++){
            totalWeight += (long long)nums[i] * (max_h-depth[i]+1);
        }
        return totalWeight;
    }
};