class Solution {
public:
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) {
                factors.push_back(d);
                while (n % d == 0) {
                    n /= d;
                }
            }
        }
        if (n > 1) {
            factors.push_back(n);
        }
        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> factors(n);
        for (int i = 0; i < n; ++i) {
            factors[i] = getPrimeFactors(nums[i]);
        }

        unordered_map<int, int> prime_count;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            for (int p : factors[right]) {
                prime_count[p]++;
            }
            while (prime_count.size() > k) {
                for (int p : factors[left]) {
                    prime_count[p]--;
                    if (prime_count[p] == 0) {
                        prime_count.erase(p);
                    }
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};