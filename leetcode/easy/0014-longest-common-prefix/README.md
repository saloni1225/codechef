# Longest Common Prefix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

 **Example 1:** 

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

 **Example 2:** 

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

 

 **Constraints:** 

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.2 MB (beats 11.70%)  
**Submitted:** 2026-11-05T09:10:09.585Z  

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";
       sort(strs.begin(),strs.end());
       vector<char>ans;
       string st=strs[0];
       string ed=strs[strs.size()-1];
       for(int i=0;i<min(st.size(),ed.size());i++){
        if(st[i] != ed[i])break;
            ans.push_back(st[i]);
       }
       return string(ans.begin(),ans.end());
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-common-prefix/)