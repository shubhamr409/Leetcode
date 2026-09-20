class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        long long count = 0;
        
        vector<int> starts(n);
        for(int i = 0; i < n; i++){
            starts[i] = intervals[i][0];
        }

        for(int i = 0; i < n; i++){
            int curr_end = intervals[i][1];
            auto it = upper_bound(starts.begin() + i + 1, starts.end(), curr_end);

            count += (it - (starts.begin() + i+1));
        }
        return count;
    }
};