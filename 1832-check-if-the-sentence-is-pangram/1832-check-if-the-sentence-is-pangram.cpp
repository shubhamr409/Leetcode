class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if(n < 26) return false;
        vector<int> alphabets(26, 0);
        for(int i = 0; i < n; i++){
            alphabets[sentence[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(alphabets[i] == 0) return false;
        }
        return true;
    }
};