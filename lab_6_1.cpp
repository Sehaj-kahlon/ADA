#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
vector<pair<int, int>> find(vector<vector<int>> a, int k, int n, int m)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == k)
            {
                ans.push_back({i, j});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<int>> v(n, vector<int>(m));
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j];
        }
    }
    vector<pair<int, int>> a;
    a = find(v, k, n, m);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].first;
    }

    return 0;
}