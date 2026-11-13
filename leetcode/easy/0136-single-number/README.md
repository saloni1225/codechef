# Single Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a  **non-empty**  array of integers `nums`, every element appears  *twice*  except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [2,2,1]

 **Output:**  1

 **Example 2:** 

 **Input:**  nums = [4,1,2,1,2]

 **Output:**  4

 **Example 3:** 

 **Input:**  nums = [1]

 **Output:**  1

 

 **Constraints:** 

- 1 <= nums.length <= 3 * 104
- -3  *104 <= nums[i] <= 3*  104
- Each element in the array appears twice except for one element which appears only once.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 12.76%)  
**Memory:** 23.9 MB (beats 6.10%)  
**Submitted:** 2026-11-13T17:53:34.377Z  

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      //int count 0;
    unordered_map<int,int>mp;
      for(auto x:nums){
        mp[x]++;
      }
      for(auto y:mp){
        if(y.second==1){
            return y.first;
        }
      }
      return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/single-number/)