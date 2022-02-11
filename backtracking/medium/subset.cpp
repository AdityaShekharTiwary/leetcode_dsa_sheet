class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int> nums, int idx, int n) {
        ans.push_back(temp);
        for (int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i + 1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        temp.clear();
        backtrack(nums, 0, n);
        return ans;
    }
};