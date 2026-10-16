# Subarrays Distinct Element Sum of Squares II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed** integer array `nums`.

The  **distinct count**  of a subarray of `nums` is defined as:

- Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].

Return  *the sum of the  **squares**  of  **distinct counts**  of all subarrays of* `nums`.

Since the answer may be very large, return it  **modulo**  `109 + 7`.

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

```

 **Example 2:** 

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** Python  
**Runtime:** 586 ms (beats 100.00%)  
**Memory:** 39.9 MB (beats 96.55%)  
**Submitted:** 2026-10-16T12:29:52.478Z  

```py
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        cnt, tot = [0] * (n + 1), [0] * (n + 1) 
        last, ans = {}, 0
        for r, x in enumerate(nums):
            p = last.get(x, -1)
            c = s = 0
            i = n - p - 1 
            while i:
                c += cnt[i]
                s += tot[i]
                i -= i & -i
            ans += (n - r) * ((r - p) ** 2 - 2 * (s - p * c))
            i = n - p  
            while i <= n:
                cnt[i] += 1
                tot[i] += p
                i += i & -i
            last[x] = r
        return ans % (10**9 + 7)
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)