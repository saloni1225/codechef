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