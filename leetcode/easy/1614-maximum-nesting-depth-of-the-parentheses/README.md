# Maximum Nesting Depth of the Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a  **valid parentheses string**  `s`, return the  **nesting depth**  of `s`. The nesting depth is the  **maximum**  number of nested parentheses.

 

 **Example 1:** 

 **Input:**  s = "(1+(2*3)+((8)/4))+1"

 **Output:**  3

 **Explanation:** 

Digit 8 is inside of 3 nested parentheses in the string.

 **Example 2:** 

 **Input:**  s = "(1)+((2))+(((3)))"

 **Output:**  3

 **Explanation:** 

Digit 3 is inside of 3 nested parentheses in the string.

 **Example 3:** 

 **Input:**  s = "()(())((()()))"

 **Output:**  3

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
- It is guaranteed that parentheses expression s is a VPS.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.5 MB (beats 24.11%)  
**Submitted:** 2026-09-28T19:13:46.904Z  

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int par=0;
        int maxpar=0;
        for(char c: s){
            if( c == '('){
                par++;
                maxpar=max(par,maxpar);
            }
            else if(c == ')'){
                par--;
            }
        }
        return maxpar;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)