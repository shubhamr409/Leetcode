class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total_sum = 0;
        int neg_count = 0;
        int min_abs_value = INT_MAX;

        for(const auto& row : matrix){
            for(int val : row){
                total_sum += abs(val);
                if(val < 0) neg_count++;
                min_abs_value = min(min_abs_value, abs(val));
            }
        }

        if(neg_count % 2 == 0) return total_sum;
        else return total_sum - 2LL * min_abs_value;
    }
};