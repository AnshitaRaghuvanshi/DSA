//To find longest common subsequnce among two strings
#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000]; // to avoid resolving solved subproblems
                      //(overlapping problems seen in recursion)

//TC Takes exponential time in worst case O(2^n)
int LCSRecusion(string s1,string s2, int m,int n){
  if(m==0||n==0) return 0;
  if(s1[m-1]==s2[n-1])
  return (1+LCSRecusion(s1,s2,m-1,n-1));
  else
  return max(LCSRecusion(s1,s2,m-1,n),LCSRecusion(s1,s2,m,n-1));
}

//TC  θ(mn)
int LCSMemorization(string s1, string s2, int m,int n)
{
  if(memo[m][n]!=-1) return memo[m][n]; //if already solved
  if(m==0 || n==0) memo[m][n]=0;
  else
  {
    if(s1[m-1]==s2[n-1])
    memo[m][n]=1+LCSMemorization(s1,s2,m-1,n-1);
    else
    memo[m][n]=max(LCSMemorization(s1,s2,m-1,n),LCSMemorization(s1,s2,m,n-1));
  }
  return memo[m][n];
}

int LCSTabulation(string s1,string s2,int m,int n)
{
  int dp[m+1][n+1];
  for(int i=0;i<m+1;i++) dp[i][0]=0; //if either string becomes Empty
  for(int i=0;i<n+1;i++) dp[0][i]=0;//nothing would be common so set 0
  for(int i=1;i<m+1;i++)
    for(int j=1;j<n+1;j++)
      if(s1[i-1]==s2[j-1])
        dp[i][j]=1+dp[i-1][j-1];//prevDiagonalElement+1
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//max of Leftadjacent and TopAdjacent
  return dp[m][n];
}
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   int n=s2.length();
   int m=s1.length();
   std::cout << LCSRecusion(s1,s2,m,n)<< '\n';
   memset(memo,-1,sizeof(memo));
   std::cout << LCSMemorization(s1,s2,m,n)<< '\n';
   std::cout << LCSTabulation(s1,s2,m,n)<< '\n';
}
