# Reverse Substrings Between Each Pair of Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should  **not**  contain any brackets.

 

 **Example 1:** 

```
Input: s = "(abcd)"
Output: "dcba"

```

 **Example 2:** 

```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

```

 **Example 3:** 

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s only contains lower case English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.7 MB (beats 16.21%)  
**Submitted:** 2026-09-27T18:59:03.071Z  

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                st.push(curr);
                curr = "";
            }

            else if (ch == ')') {
                reverse(curr.begin(), curr.end());

                curr = st.top() + curr;
                st.pop();
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)