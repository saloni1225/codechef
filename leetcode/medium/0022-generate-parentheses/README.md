# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 79.44%)  
**Memory:** 15.8 MB (beats 35.81%)  
**Submitted:** 2026-10-02T17:49:17.675Z  

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getParenthesis(0, 0, "", n, res);
        return res;
    }

    void getParenthesis(int open, int close, string s, int n, vector<string>& res) {
        if(s.length() == 2 * n) {
            res.push_back(s);
        }

        if(open < n) {
            getParenthesis(open + 1, close, s + "(", n, res);
        }

        if(close < open) {
            getParenthesis(open, close + 1, s + ")", n, res);
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)