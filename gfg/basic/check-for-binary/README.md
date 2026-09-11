# Check for Binary String

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given a non-empty sequence of characters  **s**, return  **true** if sequence is Binary, else return  **false**.

 **Examples:** 

```
Input: s = "101"
Output: true
Explanation: Since string contains only '0' and '1', output is true.

```

```
Input: s = "75"
Output: false
Explanation: Since string contains digits other than '0' and '1', output is false.
```

 **Constraints:** 
1 <= s.size() <= 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-11T08:54:55.977Z  

```cpp
class Solution {
  public:
    bool isBinary(string& s) {
    for(int i=0;i<s.length();i++){
        if(s[i]!='0' && s[i]!='1'){
            return false;
        }
    }
    return true;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/check-for-binary/1)