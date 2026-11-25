# Valid Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A phrase is a  **palindrome**  if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a  **palindrome**, or* `false` *otherwise*.

 

Original
C++
 **Example 1:** 

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

```

 **Example 2:** 

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

```

 **Example 3:** 

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

```

 

 **Constraints:** 

- 1 <= s.length <= 2 * 105
- s consists only of printable ASCII characters.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 22.29%)  
**Memory:** 10.5 MB (beats 10.87%)  
**Submitted:** 2026-11-25T17:45:00.250Z  

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>ans;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ans.push_back(tolower(s[i]));
            }
        }
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i] != ans[j]){
                return 0;
            }
            i++;j--;
        }
        return 1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-palindrome/)