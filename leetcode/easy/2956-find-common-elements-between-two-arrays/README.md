# Find Common Elements Between Two Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given two integer arrays `nums1` and `nums2` of sizes `n` and `m`, respectively. Calculate the following values:

- answer1 : the number of indices i such that nums1[i] exists in nums2.
- answer2 : the number of indices i such that nums2[i] exists in nums1.

Return `[answer1,answer2]`.

 

Original
C++
 **Example 1:** 

 **Input:**  nums1 = [2,3,2], nums2 = [1,2]

 **Output:**  [2,1]

 **Explanation:** 

 **Example 2:** 

 **Input:**  nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]

 **Output:**  [3,4]

 **Explanation:** 

The elements at indices 1, 2, and 3 in `nums1` exist in `nums2` as well. So `answer1` is 3.

The elements at indices 0, 1, 3, and 4 in `nums2` exist in `nums1`. So `answer2` is 4.

 **Example 3:** 

 **Input:**  nums1 = [3,4,2,3], nums2 = [1,5]

 **Output:**  [0,0]

 **Explanation:** 

No numbers are common between `nums1` and `nums2`, so answer is [0,0].

 

 **Constraints:** 

- n == nums1.length
- m == nums2.length
- 1 <= n, m <= 100
- 1 <= nums1[i], nums2[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 60.23%)  
**Memory:** 64.5 MB (beats 99.39%)  
**Submitted:** 2026-11-12T13:40:44.796Z  

```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int count1 =0;
        int count2=0;
        for(int i =0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    count1++;
                    break;
                }
            }
        }
        ans.push_back(count1);
          for(int i =0;i<nums2.size();i++){
            for(int j = 0;j<nums1.size();j++){
                if(nums2[i] == nums1[j]){
                    count2++;
                    break;
                }
            }
        }
        ans.push_back(count2);
        return  ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-common-elements-between-two-arrays/)