# Rotate String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `goal`, return `true`  *if and only if*  `s`  *can become*  `goal`  *after some number of  **shifts**  on*  `s`.

A  **shift**  on `s` consists of moving the leftmost character of `s` to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

 

 **Example 1:** 

```
Input: s = "abcde", goal = "cdeab"
Output: true

```

 **Example 2:** 

```
Input: s = "abcde", goal = "abced"
Output: false

```

 

 **Constraints:** 

- 1 <= s.length, goal.length <= 100
- s and goal consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.5 MB  
**Submitted:** 2026-09-10T15:15:21.133Z  

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
        return false;
        }
        for(int i=0;i<n;i++){
            if(s==goal){
                return true;
            }
            char temp=s[0];
            for(int i=1;i<n;i++){
                s[i-1]=s[i];
            }
            s[n-1]=temp;
            }
            return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotate-string/)