#include <bits/stdc++.h>
using namespace std;

int coinRow(vector<int> &coins)
{
    int n = coins.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return coins[0];

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = coins[0];

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], coins[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main()
{
    vector<int> coins = {5, 1, 2, 10, 6, 2};

    cout << "Maximum value is : " << coinRow(coins) << endl;

    return 0;
}
