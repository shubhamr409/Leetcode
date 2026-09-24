class Solution {
public:
int n;
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int noOfB = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                noOfB += cnt/k;
                cnt = 0;
            }
        }
        noOfB += cnt/k;
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL * m * 1LL * k;
        n = bloomDay.size();
        if(val > n) return -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low <= high){
            int mid = (low + high) /2;
            if(possible(bloomDay, mid, m, k)){
                high = mid-1;
            }
            else low = mid + 1;
        }
        return low;
    }
};