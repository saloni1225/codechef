# Valid Anagram

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

 

Original
C++
 **Example 1:** 

 **Input:**  s = "anagram", t = "nagaram"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "rat", t = "car"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

 

 **Follow up:**  What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 53.65%)  
**Memory:** 9.7 MB (beats 67.55%)  
**Submitted:** 2026-11-25T18:03:15.909Z  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ans(256,0);
        if(s.size() != t.size()) return false;
        for(int i=0;i<t.size();i++){
            ans[s[i] - 'a']++;
            ans[t[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(ans[i] != 0) return false;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-anagram/)