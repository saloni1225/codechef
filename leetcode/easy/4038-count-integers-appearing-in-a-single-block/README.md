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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 21.1 MB (beats 20.81%)  
**Submitted:** 2026-08-30T06:48:57.317Z  

```cpp
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_set<int> bad;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                if (seen.count(nums[i])) {
                    bad.insert(nums[i]);
                }
            }

            seen.insert(nums[i]);
        }

        return seen.size() - bad.size();
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/)