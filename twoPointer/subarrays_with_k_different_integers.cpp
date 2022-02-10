class Solution {
public:

    int helper(vector<int> &nums, int n, int k) {
        unordered_map<int, int> hash;
        int ans = 0;
        int start = 0, end = 0;
        while (end < n) {
            hash[nums[end++]]++;
            while (hash.size() > k) {
                hash[nums[start]]--;
                if (hash[nums[start]] == 0) hash.erase(nums[start]);
                start++;
            }
            ans += end - start + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums, n, k) - helper(nums, n, k - 1);
    }
};