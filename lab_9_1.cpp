// 1 Write a program to solve 0 1 knapsack using Dynamic programming.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
// 0_1 knapsack using memoization
int knapsack_m(int n, int w, vector<pair<int, int>> v)
{
    if (w <= 0)
    {
        return 0;
    }
    if (n <= 0)
    {
        return 0;
    }
    // cananot take the item
    if (v[n - 1].first > w)
    {
        return knapsack_m(n - 1, w, v);
    }
    return max(knapsack_m(n - 1, w, v), knapsack_m(n - 1, w - v[n - 1].first, v) + v[n - 1].second);
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
    return 0;
}