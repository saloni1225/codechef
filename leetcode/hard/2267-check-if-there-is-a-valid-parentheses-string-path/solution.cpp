class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(m + n, false)
            )
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int bal = 0; bal < m + n; bal++) {
                    if (i > 0 && dp[i - 1][j][bal]) {
                        int nextBal = bal + change;
                        if (nextBal >= 0 && nextBal < m + n)
                            dp[i][j][nextBal] = true;
                    }

                    if (j > 0 && dp[i][j - 1][bal]) {
                        int nextBal = bal + change;
                        if (nextBal >= 0 && nextBal < m + n)
                            dp[i][j][nextBal] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};