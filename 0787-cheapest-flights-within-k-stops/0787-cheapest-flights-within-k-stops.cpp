class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> t = res;
            for(int j = 0; j < edges.size(); j++){
                int s = edges[j][0];
                int d = edges[j][1];
                int wt = edges[j][2];
                if(res[s] != 1e8 && t[d] > res[s] + wt){
                    t[d] = res[s] + wt;
                }
            }
            res = t;
        }
        return res[dst] == 1e8 ? -1 : res[dst];
    }
};