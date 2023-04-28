// It’s Tushar’s birthday today and he has N friends.Friends are numbered[0, 1, 2, ...., N - 1] and ith friend have a positive strength B[i].Today being his birthday, his friends have planned to give him birthday bombs(kicks).Tushar 's friends know Tushar' s pain bearing limit and would hit accordingly.If Tushar’s resistance is denoted by A(>= 0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength(sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no.of kicks hit are maximum.Also note that each friend can kick an unlimited number of times(If a friend hits x times, his strength will be counted x times) Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.NOTE :

//     [ a1, a2, ...., am ] is lexicographically smaller than[b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2)....                                                                                                                                                                          The first argument contains an integer,
//     A of length N.The second argument contains an array of integers B.

//     Output Format

//     Return an array of integer,
//     as described in the problem statement.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
vector<int> res(0);
vector<int> solve(int a, vector<int> &v)
{
    // max possible lenght of the ans
    // find the least element in the vector v

    // array of relevaant friends
    if (v.size() == 0)
    {
        return res;
    }
    int cur_min = INT_MAX;
    // friends to be considered for ans
    vector<int> v1(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] < cur_min)
        {
            cur_min = v[i];
        }
        v1[i] = cur_min;
    }
    int length = a / v1[0];
    if (length == 0)
    {
        return res;
    }
    int j = 0;
    while (length)
    {
        if ((a - v[j]) >= (length - 1) * v1[j])
        {
            res.push_back(j);
            length--;
            a -= v[j];
        }
        else
        {
            j++;
        }
    }
    return res;
}

int main()
{
    // inputs
    // n friends
    int n;
    cin >> n;
    // a strength of tushar
    int a;
    cin >> a;
    // array denoting strengths of different friends
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // output

    return 0;
}