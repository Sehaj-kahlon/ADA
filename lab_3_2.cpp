// Given a string 'S'.Write a program to find an array of all possible strings in any order that can be formed by transforming every letter individually to the lowercase or the uppercase.Note : 1. You can print the array in any order .2. The string 'S' only contains English alphabets and digits.

#include <bits/stdc++.h>
using namespace std;
void permute(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }
    char ch = tolower(ip[0]);
    char ch2 = toupper(ip[0]);
    // removing front char one at a time
    ip = ip.substr(1);
    permute(ip, op + ch);
    permute(ip, op + ch2);
}
int main()
{
    string ip = "aBA";
    permute(ip, "");
    return 0;
}
// Time Complexity: O(n*2n))
// Auxiliary Space: O(n)