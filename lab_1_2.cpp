// Patlu and Motu works in a building construction, they have to put some number of bricks  in a building construction, they have to put some number of bricks N from one place to another, and started doing their work. They decided , they end up with a fun challenge who will put the last brick. one place to another, and started doing their work.
// They to follow a simple rule, In the i'th round, Patlu puts i bricks whereas Motu puts ix2 bricks. There are only N bricks, you need to help find the challenge result to find who put the last brick you need to help find the challenge result to find who put the last brick.
// Input: First line contains an integer N.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int x = n;
    for (int i = 1; i <= (n / 3); i++)
    {
        // at each iteration update the value of number of bricks leaft
        x = x - (3 * i);
        // cout<<x;
        // if number of bricks left after a certain iteration is zero then motu wins since he was the last one to place the brciks
        if (x == 0)
        {
            cout << "MOTU" << endl;
            break;
        }
        // if after a certain iteration the number of bricks is -ve find the value of previos left bricks
        else if (x < 0)
        {
            x = x + 3 * i;
            // if(x>i) motu sins since patlu will place only i bricks and there will be bricks left for motu
            if (x > i)
            {
                cout << "MOTU" << endl;
            }
            else
            {
                cout << "PATLU" << endl;
            }
            break;
        }
    }
    return 0;
}
// tc: o(n/3) == 0(n); sc o(1)