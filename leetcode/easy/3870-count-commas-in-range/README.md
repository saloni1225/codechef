# Count Commas in Range

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer `n`.

Return the  **total**  number of commas used when writing all integers from `[1, n]` (inclusive) in  **standard**  number formatting.

In  **standard**  formatting:

- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

 

 **Example 1:** 

 **Input:**  n = 1002

 **Output:**  3

 **Explanation:** 

The numbers `"1,000"`, `"1,001"`, and `"1,002"` each contain one comma, giving a total of 3.

 **Example 2:** 

 **Input:**  n = 998

 **Output:**  0

 **Explanation:** 

All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

 **Constraints:** 

- 1 <= n <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.6 MB (beats 51.38%)  
**Submitted:** 2026-09-08T18:04:57.307Z  

```cpp
class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        long long start = 1000;  // First number that has a comma

        while (start <= n) {
            long long end = start * 1000 - 1;

            // Number of commas for numbers in this range
            long long commas = start / 1000;

            // Only go up to n
            long long last = min((long long)n, end);

            // Count numbers in this range
            long long count = last - start + 1;

            ans += count * commas;

            start *= 1000;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-commas-in-range/)