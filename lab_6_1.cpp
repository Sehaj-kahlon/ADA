// Lab Assignment 6:
//  Given an M × N matrix, which is row-wise and column-wise sorted (with all strictly increasing elements in any row or column), write a program in to report all occurrences of a given element in it in linear time.

// For example,

// Input:
//  
// [ -4 -3 -1  3  5 ]
// [ -3 -2  2  4  6 ]
// [ -1  1  3  5  8 ]
// [  3  4  7  8  9 ]

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
vector<pair<int, int>> find(vector<vector<int>> a, int k, int n, int m)
{
    // O(n^2)
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
// O(n)
vector<pair<int, int>> search(vector<vector<int>> mat, int n, int x)
{
    vector<pair<int, int>> res(-1);
    if (n == 0)
        return res;

    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return res;

    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            // cout << "Element found at " << i << ", " << j;
            res.push_back({i, j});
            return res;
        }
        if (mat[i][j] > x)
            j--;

        // Check if mat[i][j] < x
        else
            i++;
    }

    // cout << "n Element not found";
    return res;
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