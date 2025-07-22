#include <bits/stdc++.h>
using namespace std;

void greedy(vector<int>& coins, int amount) {

    sort(coins.begin(), coins.end(), greater<int>());

    int count = 0;
    vector<int> usedCoins;

    for (int i = 0; i < coins.size(); i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            usedCoins.push_back(coins[i]);
        }
    }

    cout << "The number of coins used is : " << count << endl;
    cout << "Coins used : ";
    for (int coin : usedCoins) {
        cout << coin << " ";
    }
    cout << endl;
}

int main() {
    int n, amount;

    cout << "Enter the coin number : ";
    cin >> n;

    cout << "Enter the amount : ";
    cin >> amount;

    vector<int> coins(n);
    cout << "Enter the value of each coin : ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    greedy(coins, amount);

    return 0;
}
