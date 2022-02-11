class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> vis;

    void backtrack(vector<int>&nums, int idx, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == true || (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == false)) continue;
            vis[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, i + 1, n);
            vis[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vis.resize(n, false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, n);
        return ans;
    }
};