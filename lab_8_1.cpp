/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Input Format:
The first argument of input contains a string, A. The second argument of input contains a string, B.
Output Format:
Return an integer, representing the minimum number of steps required.
Constraints:
1 <= length(A), length(B) <= 450
Examples:
Input 1: A = "abad" B = "abac" Output 1: 1 Explanation 1: Operation 1: Replace d with c. Input 2: A = "Anshuman" B = "Antihuman" Output 2: 2 Explanation 2: => Operation 1: Replace s with t. => Operation 2: Insert i
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
#define ll long long
int minDistance(string word1, string word2)
{
   int m = word1.length();
   int n = word2.length();
   // using tabulation
   // 1. creating a table
   int dp[m + 1][n + 1];
   for (int i = 0; i <= m; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         // filling empty string row`s and columns
         if (i == 0)
         {
            dp[i][j] = j;
         }
         else if (j == 0)
         {
            dp[i][j] = i;
         }
         // if the characters matches
         else if (word1[i - 1] == word2[j - 1])
         {
            // dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            dp[i][j] = dp[i - 1][j - 1];
         }
         else
         {
            dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
         }
      }
   }
   return dp[m][n];
};
//using topdown  -- topdown used recursion and memoisation 
int editDistance(string a , string b, int m, int n){
   //base condition for recursion
   if(m ==0 ){
      return n;

   }
   if(n == 0){
      return m;
   } 
//dividing it into subproblems
 //if the last elements are same
 if(a[m-1] == b[n-1]){
   //recursive call on the arrays with last elements removed
  return editDistance(a, b, m-1, n-1);
 }
 //if the last characters are not same - consider all the three operations insert remove and replace
 else {
   return 1 + min({editDistance(a, b,m, n-1), editDistance(a, b, m-1, n), editDistance(a, b, m-1, n-1)});
 }
}
int main()
{
   string a, b;
   cin >> a >> b;
   // int n = a.length();
   // int m = b.length();
   // int count = 0;
   // cout<<minDistance(a, b);
   cout<<editDistance(a, b, a.length(), b.length());
   return 0;
}