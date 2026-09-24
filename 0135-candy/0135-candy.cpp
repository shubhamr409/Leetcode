class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int count = n;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                count += peak;
                i++;
                if(i == n) return count;
            }
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                count += dip;
                i++;
            }
            count -= min(dip, peak);
        }
        return count;
    }
};