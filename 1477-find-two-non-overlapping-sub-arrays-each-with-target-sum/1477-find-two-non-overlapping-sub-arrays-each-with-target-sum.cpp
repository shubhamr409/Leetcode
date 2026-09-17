class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        vector<int> prefix(n, INF);
        vector<int> suffix(n, INF);

        int sum = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target && left <= right) {
                sum -= arr[left++];
            }
            if (right > 0) prefix[right] = prefix[right - 1];
            if (sum == target) {
                prefix[right] = min(prefix[right], right - left + 1);
            }
        }

        sum = 0;
        int right = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            sum += arr[i];
            while (sum > target && right >= i) {
                sum -= arr[right--];
            }
            if (i + 1 < n) suffix[i] = suffix[i + 1];
            if (sum == target) {
                suffix[i] = min(suffix[i], right - i + 1);
            }
        }

        int ans = INF;
        for (int i = 0; i < n - 1; ++i) {
            if (prefix[i] != INF && suffix[i + 1] != INF) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans >= INF ? -1 : ans;
    }
};