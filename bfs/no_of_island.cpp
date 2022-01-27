// DFS Approach

class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i + 1, j);
            dfs(grid, i - 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
        }
        else return;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


// BFS Approach

class Solution {
public:
    int n, m;

    int r[4] = {1, 0, -1, 0};
    int c[4] = {0, 1, 0, -1};

    bool isValid(vector<vector<char>> grid, int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1') return true;
        return false;
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = r[k] + a;
                int y = c[k] + b;
                if (isValid(grid, x, y)) {
                    q.push({x, y});
                    grid[x][y] = '0';
                }
                else continue;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};