class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        vector<bool> isValid(26, true);

        vector<string> result;

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if(first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        for(int c = 0; c < 26; c++){
            if(first[c] == -1) continue;

            for(int i = first[c]; i <= last[c]; i++){
                if(first[s[i] - 'a'] < first[c]){
                    isValid[c] = false;
                    break;
                }
                last[c] = max(last[c], last[s[i]-'a']);
            }
        }
        int lastTakenStart = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            int c = s[i] - 'a';
            if(!isValid[c]) continue;

            if(i == first[c] && last[c] < lastTakenStart){
                result.push_back(s.substr(i, last[c]-i+1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};