// Given a sorted array A containing N integers both positive and negative.

// You need to create another array containing the squares of all the elements in A and return it in non -
// decreasing order.

// Try to this in
// O(N) time.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
vector<int> solve(vector<int> &A)
{
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back(A[i] * A[i]);
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    int n;
    cout<<"Enter the number of elements "<<endl;
    cin>>n;
    vector<int> V;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        V.push_back(a);
    }
    V = solve(V);
    for(int i =0; i< n; i++){
        cout<<V[i]<<" ";
    }
        return 0;
}