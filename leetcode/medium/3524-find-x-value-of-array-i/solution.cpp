class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for (int x : nums) {

            vector<long long> newDp(k, 0);

            // Subarray containing only x
            newDp[x % k]++;

            // Extend previous subarrays with x
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * (x % k)) % k;
                    newDp[newRemainder] += dp[r];
                }
            }

            // Add subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};