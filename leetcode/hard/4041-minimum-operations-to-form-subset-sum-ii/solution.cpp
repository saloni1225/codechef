class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> zoltravepi = nums;

        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int x : nums) {
            vector<int> dist(sum + 1, INF);
            queue<pair<int, int>> q;

            q.push({x, 0});

            unordered_set<int> visited;
            visited.insert(x);

            while (!q.empty()) {
                auto [cur, cost] = q.front();
                q.pop();

                if (cur <= sum) {
                    dist[cur] = cost;
                }

                // x -> 2x
                long long twice = 2LL * cur;

                if (twice <= sum && !visited.count(twice)) {
                    visited.insert(twice);
                    q.push({(int)twice, cost + 1});
                }

                // x -> floor(x/2)
                int half = cur / 2;

                if (half > 0 && !visited.count(half)) {
                    visited.insert(half);
                    q.push({half, cost + 1});
                }
            }

            vector<int> ndp = dp;

            for (int s = 0; s <= sum; s++) {
                if (dp[s] == INF)
                    continue;

                for (int value = 1; value + s <= sum; value++) {
                    if (dist[value] != INF) {
                        ndp[s + value] = min(
                            ndp[s + value],
                            dp[s] + dist[value]
                        );
                    }
                }
            }

            dp = ndp;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};