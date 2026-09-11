class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i == j || j == k || k == i) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num < 1000 && num % 2 == 0) st.insert(num);
                }
            }
        }
        vector<int> res(st.begin(), st.end());
        sort(res.begin(), res.end());
        return res;
    }
};