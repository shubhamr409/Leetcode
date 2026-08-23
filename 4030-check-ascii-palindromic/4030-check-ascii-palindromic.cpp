class Solution {
public:
    bool isPalindromic(string s) {
        string concatenated = "";
        for(char c : s){
            bitset<8> binary(c);
            string binaryString = binary.to_string();
            concatenated += binaryString;
        }
        string reverseConcatenated = concatenated;
        reverse(concatenated.begin(), concatenated.end());
        if(concatenated == reverseConcatenated) return true;
        return false;
    }
};