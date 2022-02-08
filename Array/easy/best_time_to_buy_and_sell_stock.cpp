class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr_max = 0, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr_max = max(curr_max, prices[i]);
            ans = max(ans, curr_max - prices[i]);
        }
        return ans;
    }
};