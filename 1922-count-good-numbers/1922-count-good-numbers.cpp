class Solution {
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = modPow(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 != 0) {
            result = (result * (base % MOD)) % MOD;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long ways_even = modPow(5, even_positions);
        long long ways_odd = modPow(4, odd_positions);

        return (ways_even * ways_odd) % MOD;
    }
};