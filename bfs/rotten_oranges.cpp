class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int r = x + row[k];
                    int c = y + col[k];
                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1) {
                        q.push({r, c});
                        fresh--;
                        grid[r][c] = 2;
                    }
                }
            }
            ans++;

        }
        if (fresh != 0) return -1;
        if (ans == -1) return 0;
        return ans;
    }
};