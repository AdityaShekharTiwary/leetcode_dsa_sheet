class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int>nums, int idx, int n) {
        ans.push_back(temp);
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums, i + 1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        backtrack(nums, 0, n);
        return ans;
    }
};