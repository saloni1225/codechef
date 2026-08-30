class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> zoltravepi = nums;

        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int x : nums) {
            vector<pair<int, int>> options;

            // Divide d times first
            int cur = x;
            int div = 0;

            while (cur > 0) {
                // Multiply k times
                long long val = cur;
                int mul = 0;

                while (val <= sum) {
                    options.push_back({(int)val, div + mul});

                    val *= 2;
                    mul++;
                }

                cur /= 2;
                div++;
            }

            vector<int> ndp = dp;

            for (int s = 0; s <= sum; s++) {
                if (dp[s] == INF)
                    continue;

                for (auto [val, cost] : options) {
                    if (s + val <= sum) {
                        ndp[s + val] = min(
                            ndp[s + val],
                            dp[s] + cost
                        );
                    }
                }
            }

            dp = ndp;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};