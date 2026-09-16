# Number of Sets of K Non-Overlapping Line Segments

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` points on a 1-D plane, where the `ith` point (from `0` to `n-1`) is at `x = i`, find the number of ways we can draw  **exactly**  `k`  **non-overlapping**  line segments such that each segment covers two or more points. The endpoints of each segment must have  **integral coordinates**. The `k` line segments  **do not**  have to cover all `n` points, and they are  **allowed**  to share endpoints.

Return  *the number of ways we can draw* `k` *non-overlapping line segments **.*  Since this number can be huge, return it** modulo** `109 + 7`.

 

 **Example 1:** 

```
Input: n = 4, k = 2
Output: 5
Explanation: The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.

```

 **Example 2:** 

```
Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.

```

 **Example 3:** 

```
Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

```

 

 **Constraints:** 

- 2 <= n <= 1000
- 1 <= k <= n-1

## Solution

**Language:** C++  
**Runtime:** 72 ms (beats 43.46%)  
**Memory:** 145 MB (beats 18.22%)  
**Submitted:** 2026-09-16T18:24:35.715Z  

```cpp
class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n + k, vector<long long>(2 * k + 1));

        // dp[i][j] = C(i, j)
        for (int i = 0; i <= n + k - 1; i++) {
            dp[i][0] = 1;

            for (int j = 1; j <= 2 * k; j++) {
                if (j <= i) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
        }

        return dp[n + k - 1][2 * k];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)