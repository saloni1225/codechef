# Defanging an IP Address

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A  *defanged IP address*  replaces every period `"."` with `"[.]"`.

 

 **Example 1:** 

```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

```

 **Example 2:** 

```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

```

 

 **Constraints:** 

- The given address is a valid IPv4 address.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 53.58%)  
**Memory:** 7.7 MB (beats 49.61%)  
**Submitted:** 2026-09-10T11:38:45.471Z  

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        int index=0;
        string result;
        for(int i=0;i<address.size();i++){
            if(address[index]=='.'){
                result+="[.]";
                index++;
            }
            else{
                result+=address[index];
                index++;
            }
        }
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/defanging-an-ip-address/)