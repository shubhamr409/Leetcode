class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        events.reserve(intervals.size() * 2);

        for(const auto& iv : intervals){
            events.push_back({iv[0], -1});
            events.push_back({iv[1], 1});
        }
        sort(events.begin(), events.end());
        long long count = 0;
        long long active_intervals = 0;
        
        for(const auto& event : events){
            if(event.second == -1){
                count += active_intervals;
                active_intervals++;
            }
            else{
                active_intervals--;
            }
        }
        return count;
    }
};