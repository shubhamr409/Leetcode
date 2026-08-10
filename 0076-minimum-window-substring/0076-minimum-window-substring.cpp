class Solution {
public:
    string minWindow(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (n < m || n == 0 || m == 0) return "";

        vector<int> freq_p(128, 0);
        int req_unique = 0;

        for (char c : p) {
            if (freq_p[c] == 0) req_unique++;
            freq_p[c]++;
        }

        vector<int> freq_s(128, 0);
        int matched_unique = 0;
        int left = 0;
        int min_len = INT_MAX;
        int start_idx = -1;

        for (int right = 0; right < n; right++) {
            char curr = s[right];
            freq_s[curr]++;

            if (freq_p[curr] > 0 && freq_s[curr] == freq_p[curr]) {
                matched_unique++;
            }

            while (matched_unique == req_unique) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                char left_char = s[left];
                freq_s[left_char]--;

                if (freq_p[left_char] > 0 && freq_s[left_char] < freq_p[left_char]) {
                    matched_unique--;
                }

                left++;
            }
        }

        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};