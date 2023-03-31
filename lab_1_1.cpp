/*
Simran is running up a staircase with N steps, and can hop(jump) either 1 step, 2 steps or 3 steps at a time. You have to count, how many possible ways Simran can run up to the stairs.
Input Format:
Input contains integer N that is number of steps
Output Format:
Output for each integer N the no of possible ways w.
Constraints
1≤N≤30
SAMPLE INPUT: 4
SAMPLE OUTPUT: 7
*/
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
const int mod = 1000000007;
class GFG
{
public:
    int findStep(int n)
    {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        else
            return findStep(n - 3) + findStep(n - 2) + findStep(n - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    GFG obj;
    cout << obj.findStep(n) << endl;
    ;
    return 0;
}