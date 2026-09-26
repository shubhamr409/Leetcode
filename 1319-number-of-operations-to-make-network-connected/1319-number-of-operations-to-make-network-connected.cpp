class Solution {
public:
        vector<int> parent, size;

        int find(int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b){
            int rootA = find(a);
            int rootB = find(b);

            if(rootA == rootB) return;

            if(size[rootA] < size[rootB]) swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int extraEdges = 0;

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)) extraEdges++;
            else{
                unite(u, v);
            }
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(find(i) == i) components++;
        }
        if(extraEdges >= components-1) return components-1;
        return -1;
    }
};