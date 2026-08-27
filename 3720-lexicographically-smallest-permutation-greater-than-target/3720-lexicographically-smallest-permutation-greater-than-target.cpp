class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int matched_len = 0;
        while (matched_len < n && count[target[matched_len] - 'a'] > 0) {
            count[target[matched_len] - 'a']--;
            matched_len++;
        }

        for (int i = min(matched_len, n-1); i >= 0; i--) {
            if(i < matched_len) count[target[i] - 'a']++;

            for (char ch = target[i] + 1; ch <= 'z'; ch++) {
                if (count[ch - 'a'] > 0) {
                    count[ch - 'a']--;

                    string result = target.substr(0, i);
                    result.push_back(ch);

                    for (char rem = 'a'; rem <= 'z'; rem++) {
                        while (count[rem - 'a'] > 0) {
                            result.push_back(rem);
                            count[rem - 'a']--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};