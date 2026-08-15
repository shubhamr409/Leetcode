class Solution {
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        long long res = (modPow(5, even_positions) * modPow(4, odd_positions)) % MOD;
        return res;
    }
};