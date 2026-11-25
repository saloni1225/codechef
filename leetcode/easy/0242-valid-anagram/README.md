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
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-11-25T18:03:24.605Z  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ans(26,0);
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