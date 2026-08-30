# Count Integers Appearing in a Single Block

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums`.

An integer `x` is  **special**  if all occurrences of `x` in `nums` appear in a single  **contiguous**  block.

Return the number of  **distinct**  special integers in `nums`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,2,1]

 **Output:**  1

 **Explanation:** 

- 1 appears at indices 0 and 3, forming two separate blocks, so it is not special.
- 2 appears in a single contiguous block at indices [1, 2], so it is special.

Therefore, there is one special integer.

 **Example 2:** 

 **Input:**  nums = [3,3,1,2,2,1]

 **Output:**  2

 **Explanation:** 

- 3 appears in a single contiguous block at indices [0, 1], so it is special.
- 1 appears at indices 2 and 5, forming two separate blocks, so it is not special.
- 2 appears in a single contiguous block at indices [3, 4], so it is special.

Therefore, there are two special integers.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 804 ms (beats 39.11%)  
**Memory:** 67.3 MB (beats 65.75%)  
**Submitted:** 2026-08-30T06:48:46.479Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/)