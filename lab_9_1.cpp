// 1 Write a program to solve 0 1 knapsack using Dynamic programming.
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int n1 = 1e9 + 7;
const int n2 = 1e3 + 2;
#define ll long long
// 0_1 knapsack using memoization
// int knapsack_m(int n, int w, vector<pair<int, int>> v)
// {
//     if (w <= 0)
//     {
//         return 0;
//     }
//     if (n <= 0)
//     {
//         return 0;
//     }
//     // cananot take the item
//     if (v[n - 1].first > w)
//     {
//         return knapsack_m(n - 1, w, v);
//     }
//     return max(knapsack_m(n - 1, w, v), knapsack_m(n - 1, w - v[n - 1].first, v) + v[n - 1].second);
// }
// 0_1 knapsack using Tabulation
int knapsack_t(int n, int w, vector<pair<int, int>> v)
{
    // create a dp table of n+1 roes and w+1 columns

    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] == 0;
            }
            else if (v[i - 1].first <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    // inputs
    // number of items
    int n;
    cin >> n;
    // weight of the bag
    int w;
    cin >> w;
    // weights and profit
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    cout << knapsack_t(n, w, v);
    return 0;
}