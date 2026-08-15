class Solution {
    bool isPrime(int x){
        if(x < 2) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;

        for(int d = 3; d*d <= x; d += 2){
            if(x % d == 0) return false;
        }
        return true;
    }
    int makePalindrome(int root){
        string str = to_string(root);
        string part = str.substr(0, str.length()-1);
        reverse(part.begin(), part.end());
        str += part;
        int num = stoi(str);
        return num;
    }
public:
    int primePalindrome(int n) {
        if(n == 2 || n == 3 || n== 5 || n == 7) return n;
        else if(n > 7 && n <= 11) return 11;
        else{
            for(int i = 1; i <= 20000; i++){
                int candidate = makePalindrome(i);
                if(candidate >= n && isPrime(candidate)){
                    return candidate;
                }
            }
        }
        return -1;
    }
};