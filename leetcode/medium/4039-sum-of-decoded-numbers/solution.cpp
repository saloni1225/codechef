class Solution {
public:
    long long power(long long x, long long y) {
        long long ans = 1;
        long long MOD = 1e9 + 7;

        while (y > 0) {
            if (y % 2)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        vector<long long> vornelqati = nums;

        long long ans = 0;
        long long MOD = 1e9 + 7;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;

            string s = to_string(d);

            long long x = stoll(s.substr(0, width));
            long long y = stoll(s.substr(width));

            ans = (ans + power(x, y)) % MOD;
        }

        return ans;
    }
};