class Solution {
public:
int n;
unordered_map<int, int> mpp;
int t[2001][2001];
    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump){
        if(curr_stone_idx == n-1) return true;
        if(t[curr_stone_idx][prevJump] != -1) return t[curr_stone_idx][prevJump];

        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump + 1; nextJump++){
            if(nextJump > 0){
                int next_stone = stones[curr_stone_idx] + nextJump;
                if(mpp.find(next_stone) != mpp.end()){
                    result = result || solve(stones, mpp[next_stone], nextJump);
                }
            }
        }
        return t[curr_stone_idx][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        n = stones.size();
        memset(t, -1, sizeof(t));
        for(int i = 0; i < n; i++){
            mpp[stones[i]] = i;
        }

        return solve(stones, mpp[0], 0);
    }
};