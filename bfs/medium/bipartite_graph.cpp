class Solution {
public:

    bool bfs(int src, vector<int> &color, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]) return false;
            }
        }
        return true;
    }

    bool dfs(int node, vector<int> &color, vector<vector<int>> &graph) {
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                if (!(dfs(it, color, graph))) return false;
            }
            else if (color[it] == color[node]) return false;

        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // if(!bfs(i,color,graph)) return false;
                if (!dfs(i, color, graph)) return false;
            }
        }
        return true;
    }
};