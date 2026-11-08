# Count Servers that Communicate

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

 **Example 1:** 

```
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

 **Example 2:** 

```
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

```

 **Example 3:** 

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m <= 250
- 1 <= n <= 250
- grid[i][j] == 0 or 1

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 40.75%)  
**Memory:** 26.6 MB (beats 69.75%)  
**Submitted:** 2026-11-08T18:36:11.787Z  

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> countRow(n, 0);
        vector<int> countCol(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    countRow[i]++;
                    countCol[j]++;
                }
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && (countRow[i] > 1 || countCol[j] > 1)) {
                    res++;
                }
            }
        }

        return res;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-servers-that-communicate/)