//Edit Distance Problem : Solving using DP (Tabulation)
//Problem: Given two strings Find the minimum number of operations that need to be performed on str1 to convert it to str2.
//The possible operations are: Insert Remove Replace
//Time Complexity: O(m x n) Auxiliary Space: O(m x n)
#include <bits/stdc++.h>
using namespace std;

int EditDistance(string s1, string s2, int m, int n){
  int dp[m+1][n+1];
  
  for(int i=0; i<=n; i++) {dp[0][i] = i}; //BC2
  for(int i=0; i<=m; i++) {dp[i][0] = i}; //BC1

  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(s1[i-1] == s2[j-1]) 
      dp[i][j] = dp[i-1][j-1]; //1
      else
      dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));//2
    }
  }
  return dp[m][n];

}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int m=s1.length();
  int n=s2.length();
  cout<<EditDistance(s1,s2,m,n)<<endl;
  return 0;
}


/*
--------------------------------------------------------------------------------------------------------------------
Recursive Approach:
    either pick the coin or don't
    1. If character matches -----> ignore and move to prev character
    2. Else find minimum of the three operations   -----> return 1+min
    Base Case:(BC)
      1. if m becomes 0, insert all remaining n characters of s2  ----> return n
      2. if n becomes 0, delete all remaining m characters of s1  ----> return m
*/
