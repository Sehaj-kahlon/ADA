// Write a Program to Reverse a given stack of integers using recursion. Create a recurrence relation and calculate its Time Complexity.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
void insert_bottom(stack<int> &s, int x)
{
    if (s.size() == 0)
    {
        s.push(x);
    }
    else
    {
        int a = s.top();
        s.pop();
        insert_bottom(s, x);
        s.push(a);
    }
}
void reverse(stack<int> &s)
{
    if (s.size() > 0)
    {
        int x = s.top();
        s.pop();
        reverse(s);
        insert_bottom(s, x);
    }
    return;
}
int main()
{
    int n;
    // cout<<"Enter the number of elements to be added in the stack";
    cin >> n;
    stack<int> s, sr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }
    sr = s;
    // cout the original stack
    while (!sr.empty())
    {
        cout << sr.top() << " ";
        sr.pop();
    }
    cout << endl;
    reverse(s);
    // print the reverses stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
// Time Complexity: O(N2).
// Auxiliary Space: O(N) use of Stack