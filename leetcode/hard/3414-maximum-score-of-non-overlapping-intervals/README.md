# Maximum Score of Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array `intervals`, where `intervals[i] = [li, ri, weighti]`. Interval `i` starts at position `li` and ends at `ri`, and has a weight of `weighti`. You can choose  *up to*  4  **non-overlapping**  intervals. The  **score**  of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from `intervals` with  **maximum**  score, representing your choice of non-overlapping intervals.

Two intervals are said to be  **non-overlapping**  if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 

 **Example 1:** 

 **Input:**  intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

 **Output:**  [2,3]

 **Explanation:** 

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.

 **Example 2:** 

 **Input:**  intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

 **Output:**  [1,3,5,6]

 **Explanation:** 

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.

 

 **Constraints:** 

- 1 <= intevals.length <= 5 * 104
- intervals[i].length == 3
- intervals[i] = [li, ri, weighti]
- 1 <= li <= ri <= 109
- 1 <= weighti <= 109

## Solution

**Language:** C++  
**Runtime:** 897 ms (beats 51.09%)  
**Memory:** 328.5 MB (beats 40.22%)  
**Submitted:** 2026-09-12T10:24:13.484Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)