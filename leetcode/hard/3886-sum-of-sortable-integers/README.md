# Sum of Sortable Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`.

An integer `k` is called  **sortable**  if `k`  **divides**  `n` and you can sort `nums` in  **non-decreasing**  order by sequentially performing the following operations:

- Partition nums into consecutive subarrays of length k.
- Cyclically rotate each subarray independently any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

 

 **Example 1:** 

 **Input:**  nums = [3,1,2]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
- Only k = 3 is sortable. Hence, the answer is 3.

 **Example 2:** 

 **Input:**  nums = [7,6,5]

 **Output:**  0

 **Explanation:** 

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
- No k is sortable. Hence, the answer is 0.

 **Example 3:** 

 **Input:**  nums = [5,8]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 2, possible divisors are 1 and 2.
- Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.

 

 **Constraints:** 

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 27 ms (beats 90.44%)  
**Memory:** 99.1 MB (beats 30.88%)  
**Submitted:** 2026-10-20T18:03:24.121Z  

```cpp
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> desc(n);  // desc[i]: number of descents nums[j] > nums[j + 1] with j < i
        for (int i = 1; i < n; i++) desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        vector<int> premax(n), sufmin(n);
        inclusive_scan(nums.begin(), nums.end(), premax.begin(), [](int a, int b) { return max(a, b); });  // premax[i]: max of nums[0..i]
        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(), [](int a, int b) { return min(a, b); });  // sufmin[i]: min of nums[i..n-1]
        vector<bool> cut(n, true);  // cut[m]: nums[0..m-1] holds exactly the m smallest values
        for (int m = 1; m < n; m++) cut[m] = premax[m - 1] <= sufmin[m];

        auto rotatable = [&](int l, int r) {  // nums[l..r] is a rotated sorted run: at most one cyclic descent
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
        };
        auto sortable = [&](int k) {  // every block starts at a valid cut and can be rotated into order
            for (int l = 0; l < n; l += k)
                if (!cut[l] || !rotatable(l, l + k - 1)) return false;
            return true;
        };

        vector<int> divisors;
        for (int k = 1; k <= n; k++) if (n % k == 0) divisors.push_back(k);
        auto good = divisors | views::filter(sortable);
        return accumulate(good.begin(), good.end(), 0);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-sortable-integers/)