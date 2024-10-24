#include <vector>
#include <iostream>
using namespace std;


int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    vector<int> dp(amount + 1, -1);
    for (int i = 0; i < amount + 1; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            int index = i - coins[j];
            if (index == 0) {
                dp[i] = 1;
            } else if (index > 0 && dp[index] > 0) {
                if (dp[i] == -1) {
                    dp[i] = dp[index] + 1;
                } else {
                    dp[i] = min(dp[i], dp[index] + 1);
                }
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[amount];
}

int main() {
    vector<int> coins = {1};
    cout << coinChange(coins, 0) << endl;
    return 0;
}