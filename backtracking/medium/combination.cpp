class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int n, int k, int curr) {
        for (auto it : temp) cout << it << " ";
        cout << endl;
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = curr; i <= n; i++) {
            temp.push_back(i);
            backtrack(n, k, i + 1);
            temp.pop_back();

        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }
};