// 1 Write a program in Python to solve 0 1 knapsack using Dynamic programming.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long

int main()
{
    // inputs
    // number of items
    int n;
    cin >> n;
    // weights and profit
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    // weight of the bag
    int w;
    cin >> w;
    // create a dp table (2-D vector) of n_1 rows and w+1 columns
    vector<vector<int>> dp[n + 1][w + 1];
    // make the elements of 0th row and 0th column as zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            dp[0][j] = 0;
        }
        dp[i][0] = 0;
    }

    return 0;
}