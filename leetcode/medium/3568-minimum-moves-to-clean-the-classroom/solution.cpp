class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int totalMask = (1 << litterCount) - 1;

        // maxEnergy[r][c][mask]
        vector<vector<vector<int>>> maxEnergy(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, en] = q.front();
                q.pop();

                if (mask == totalMask) {
                    return moves;
                }

                // If energy is 0, we must be standing on R
                if (en == 0 && classroom[r][c] != 'R') {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int newEnergy = en - 1;

                    if (newEnergy < 0) {
                        continue;
                    }

                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Already reached this state with
                    // equal or greater energy
                    if (maxEnergy[nr][nc][newMask] >= newEnergy) {
                        continue;
                    }

                    maxEnergy[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};