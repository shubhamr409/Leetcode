class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int start_i = intervals[i][0];
            int end_i = intervals[i][1];
            for(int j = i+1; j < n; j++){
                int start_j = intervals[j][0];
                int end_j = intervals[j][1];
                if(max(start_i, start_j) <= min(end_i, end_j)) count++;
            }
        }
        return count;
    }
};