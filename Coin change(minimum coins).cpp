class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
    std::vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= sum; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int sum = 11;
    int result = minCoins(coins, sum);
    if (result != -1) {
        std::cout << "Minimum coins required: " << result << std::endl;
    } else {
        std::cout << "It's not possible to make the sum with the given coins." << std::endl;
    }
    return 0;
    }
};
