# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An  *island*  is a maximal 4-directionally connected group of `0s` and a  *closed island*  is an island  **totally**  (all left, top, right, bottom) surrounded by `1s.`

Return the number of  *closed islands*.

 

 **Example 1:** 

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

 **Example 2:** 

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

 **Example 3:** 

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

 **Constraints:** 

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 55.01%)  
**Memory:** 13 MB (beats 95.61%)  
**Submitted:** 2026-10-25T12:25:20.197Z  

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](auto&& self, int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) return;
            grid[i][j] = 1;
            self(self, i + 1, j);
            self(self, i - 1, j);
            self(self, i, j + 1);
            self(self, i, j - 1);
        };
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(dfs, i, 0);
            if (grid[i][n - 1] == 0) dfs(dfs, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0) dfs(dfs, 0, j);
            if (grid[m - 1][j] == 0) dfs(dfs, m - 1, j);
        }
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++ans;
                    dfs(dfs, i, j);
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)