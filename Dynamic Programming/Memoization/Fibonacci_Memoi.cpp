#include <bits/stdc++.h>
using namespace std;
int Fib_Mem(int n, vector<int> &memo)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = Fib_Mem(n - 1, memo) + Fib_Mem(n - 2, memo);

    return memo[n];
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector<int> memo(n + 1, -1);

    cout << "Fibonacci series : ";
    for (int i = 0; i <= n; i++)
    {
        cout << Fib_Mem(i, memo) << " ";
    }

    return 0;
}
