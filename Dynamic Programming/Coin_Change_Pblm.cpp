#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int m, int n) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main() {
    int coins[] = {1, 3, 4};
    int m = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;

    int result = minCoins(coins, m, amount);
    if (result != -1)
        cout << "Minimum number of coins needed : " << result << endl;
    else
        cout << "Can't be changed" << endl;

    return 0;
}
