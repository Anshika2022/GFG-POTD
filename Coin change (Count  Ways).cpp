class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int m = coins.size();
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; // Base case: One way to make sum = 0 (by choosing nothing)

        for (int i = 0; i < m; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[sum];
    }
};
