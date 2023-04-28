#include <iostream>
// Write a program that reads in two integers and uses  recursion to compute the first raised to the second power.
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
// program to find power one raised to another
int power(int a, int b)
{
    // base condition
    if (a == 0)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
    return 0;
}
// Time Complexity: O(n)
// Auxiliary Space: O(n) -- size of the recursive stack