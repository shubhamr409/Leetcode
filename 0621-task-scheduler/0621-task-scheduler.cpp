class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        vector<int> mp(26, 0);
        for(char& ch: tasks){
            mp[ch-'A']++;
        }
        sort(mp.begin(), mp.end());
        int maxFreq = mp[25];
        int gaddhe = maxFreq - 1;
        int idleSlots = n * gaddhe;

        for(int i = 24; i >= 0; i--){
            idleSlots -= min(mp[i], gaddhe);
        }
        if(idleSlots > 0) return tasks.size() + idleSlots;
        return tasks.size();
    }
};