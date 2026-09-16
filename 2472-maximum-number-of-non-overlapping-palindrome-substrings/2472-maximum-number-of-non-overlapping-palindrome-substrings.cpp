class Solution {
public:
int n;
vector<vector<bool>> isPalindrome;
    
    int maxPalindromes(string s, int k) {
        n = s.size();
        if(k == 1) return n;
        isPalindrome.assign(n+1, vector<bool>(n+1, false));
        for(int L = 1; L <= n; L++){
            for(int i = 0; i + L <= n; i++){
                int j = i + L - 1;
                if(i == j) isPalindrome[i][j] = true;
                else if(i+1 == j) isPalindrome[i][j] = (s[i] == s[j]);
                else{
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }
        vector<vector<int>> t(n+1, vector<int>(n+1));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(isPalindrome[i][j]){
                    int take = 1 + (j+k <=n ? t[j+1][j+k] : 0);
                    int grow = t[i][j+1];
                    int slide = t[i+1][j+1];
                    t[i][j] = max({take, grow, slide});
                }
                int grow = t[i][j+1];
                int slide = t[i+1][j+1];
                t[i][j] = max({t[i][j], grow, slide});
            }
        }
        return t[0][k-1];
    }
};