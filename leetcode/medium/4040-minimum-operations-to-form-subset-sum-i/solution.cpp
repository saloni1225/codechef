class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> merviqunax = nums;

        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int x : nums) {
            vector<pair<int, int>> options;

            // x, 2x, 4x, 8x...
            long long val = x;
            int cost = 0;

            while (val <= sum) {
                options.push_back({val, cost});
                val *= 2;
                cost++;
            }

            // floor(x/2), floor(x/4), ...
            val = x / 2;
            cost = 1;

            while (val > 0) {
                options.push_back({val, cost});
                val /= 2;
                cost++;
            }

            // Don't use this element OR use it once
            vector<int> ndp = dp;

            for (int s = 0; s <= sum; s++) {
                if (dp[s] == INF)
                    continue;

                for (auto [value, operations] : options) {
                    if (s + value <= sum) {
                        ndp[s + value] = min(
                            ndp[s + value],
                            dp[s] + operations
                        );
                    }
                }
            }

            dp = ndp;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};