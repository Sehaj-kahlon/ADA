// Write  a program  that  prompts  for and reads  in  a string, then prints  a message  saying whether it  is  a palindrome.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
// find the funciton is pallindrome or not
bool isPallin(string s, int n)
{
    bool ans = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            ans = false;
            break;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (isPallin(s, n))
    {
        cout << "The given string is a Pallindrome" << endl;
    }
    else
    {
        cout << "The given string is not a Pallindrome" << endl;
    }
    return 0;
}