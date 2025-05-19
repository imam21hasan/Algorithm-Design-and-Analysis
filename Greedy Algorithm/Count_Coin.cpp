#include <iostream>
using namespace std;

void countCoin(int coins[], int n, int amount)
{
    int i, count[n], totalCoins = 0;

    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            count[i]++;
            totalCoins++;
        }
    }

    cout << "Coins used :" << endl;
    for (i = 0; i < n; i++)
    {
        if (count[i] != 0)
        {
            cout << count[i] << " coin's of " << coins[i] << endl;
        }
    }

    cout << "Total coins needed : " << totalCoins << endl;
}

int main()
{
    int coins[] = {25, 10, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    cout << "Enter the amount : ";
    cin >> amount;

    countCoin(coins, n, amount);

    return 0;
}
