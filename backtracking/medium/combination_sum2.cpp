class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int> nums, int target, int curr, int idx, int n) {
        if (curr > target) return;
        if (curr == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums, target, curr + nums[i], i + 1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        backtrack(candidates, target, 0, 0, n);
        return ans;
    }
};