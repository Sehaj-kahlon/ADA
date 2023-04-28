// Given a sorted Vay A containing N integers both positive and negative.

// You need to create another Vay containing the squares of all the elements in A and return it in non -
// decreasing order.

// Try to this in
// O(N) time.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
// nlogn
vector<int> solve(vector<int> &A)
{
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back(A[i] * A[i]);
    }
    sort(v.begin(), v.end()); // nlogn
    return v;
}
void sortSquares(vector<int> V, int n)
{
    // first divide Vay into negative and positive part
    int K = 0;
    for (K = 0; K < n; K++)
        if (V[K] >= 0)
            break;

    int i = K - 1;
    int j = K;
    int ind = 0;

    int temp[n];
    while (i >= 0 && j < n)
    {
        if (V[i] * V[i] < V[j] * V[j])
        {
            temp[ind] = V[i] * V[i];
            i--;
        }
        else
        {
            temp[ind] = V[j] * V[j];
            j++;
        }
        ind++;
    }

    while (i >= 0)
    {
        temp[ind] = V[i] * V[i];
        i--;
        ind++;
    }

    while (j < n)
    {
        temp[ind] = V[j] * V[j];
        j++;
        ind++;
    }

    for (int i = 0; i < n; i++)
        V[i] = temp[i];
}
int main()
{
    int n;
    cout << "Enter the number of elements " << endl;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }
    vector<int> v = solve(V);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    sortSquares(V, n);

    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << V[i] << " ";
    return 0;
}
// Time complexity: O(n)
// space complexity: O(n)