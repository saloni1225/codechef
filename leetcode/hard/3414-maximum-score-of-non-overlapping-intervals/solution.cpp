class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: left, right, weight, original index
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // next[i] = first interval whose left > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            int ans = n;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (a[mid][0] > a[i][1]) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            next[i] = ans;
        }

        // dp[i][k] = best answer from i onward using at most k intervals
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(5)
        );

        vector<vector<long long>> score(
            n + 1,
            vector<long long>(5, 0)
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                dp[i][k] = dp[i + 1][k];
                score[i][k] = score[i + 1][k];

                // Option 2: take current interval
                vector<int> take = dp[next[i]][k - 1];
                take.push_back(a[i][3]);

                long long takeScore =
                    a[i][2] + score[next[i]][k - 1];

                sort(take.begin(), take.end());

                // Choose better score.
                // If equal, choose lexicographically smaller indices.
                if (takeScore > score[i][k] ||
                    (takeScore == score[i][k] &&
                     take < dp[i][k])) {

                    score[i][k] = takeScore;
                    dp[i][k] = take;
                }
            }
        }

        return dp[0][4];
    }
};