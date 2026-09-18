# Maximum Number of Non-Overlapping Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` of lowercase letters, you need to find the maximum number of  **non-empty**  substrings of `s` that meet the following conditions:

- The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
- A substring that contains a certain character c must also contain all occurrences of c.

Find  *the maximum number of substrings that meet the above conditions*. If there are multiple solutions with the same number of substrings,  *return the one with minimum total length.* It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in  **any**  order.

 

 **Example 1:** 

```
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

```

 **Example 2:** 

```
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s contains only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 86.93%)  
**Memory:** 23.2 MB (beats 97.44%)  
**Submitted:** 2026-09-18T14:01:58.616Z  

```cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            if (first[c] == -1) {
                first[c] = i;
            }

            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid substring for every character
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {

                int current = s[i] - 'a';

                // This character appeared before our left boundary
                if (first[current] < left) {
                    valid = false;
                    break;
                }

                // We need to include all occurrences
                right = max(right, last[current]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Select maximum number of non-overlapping intervals
        sort(intervals.begin(), intervals.end(),
             [](pair<int,int> a, pair<int,int> b) {
                 return a.second < b.second;
             });

        vector<string> answer;

        int previousEnd = -1;

        for (auto interval : intervals) {

            int left = interval.first;
            int right = interval.second;

            if (left > previousEnd) {

                answer.push_back(s.substr(left, right - left + 1));

                previousEnd = right;
            }
        }

        return answer;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)