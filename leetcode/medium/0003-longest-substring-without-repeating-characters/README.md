# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** C++  
**Runtime:** 17 ms (beats 66.32%)  
**Memory:** 17.9 MB (beats 80.67%)  
**Submitted:** 2026-09-18T13:59:44.972Z  

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //your code goes here
        int first=0,second=0,len=0;
        vector<bool>substr(256,0);
        while(second<s.size()){
            while(substr[s[second]]){
                substr[s[first]]=0;
                first++;
            }
            substr[s[second]]=1;
            len=max(len,(second-first+1));
            second++;
        }
        return len;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)