#include<bits/stdc++.h>
using namespace std;

//TC O(2^n)  as array of size n has 2^n subsets
// if weight of item is greater than Capacity, ignore this item
// otherwise find max of two cases, picking up item and not picking up item

int KnapsackRecursive(int W, int wt[], int v[], int n)
{
  if(n==0 || W==0) return 0; //base case
  if(wt[n-1]>W)
  return KnapsackRecursive(W,wt,v,n-1);
  else
  return max(v[n-1]+KnapsackRecursive(W-wt[n-1],wt,v,n-1),KnapsackRecursive(W,wt,v,n-1));
}

//TC θ(W*n)
//tabulation , create table and set 0th row and 0th column equalto 0
//if weight of item is greater than current capacity(j) ignore item copy value of above cell
// otherwise find max of two cases, picking up item and not picking up item
int KnapsackIterativeDP(int W, int wt[], int v[], int n)
{
  int dp[n+1][W+1];
  for(int i=0;i<n+1;i++) dp[i][0]=0;
  for(int i=0;i<W+1;i++) dp[0][i]=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=W;j++)
      if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(v[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);

  return dp[n][W];
}

int main()
{
  int n=0,W=0;
  cout<<"Enter no. of items"<<endl;
  cin>>n;
  int v[n]={0}, wt[n]={0};
  cout<<"Enter values/profits:"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  cout<<"Enter weights:"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>wt[i];
  }
  cout<<"Enter max Capacity:"<<endl;
  cin>>W;

  cout<<KnapsackRecursive(W,wt,v,n)<<endl;
  cout<<KnapsackIterativeDP(W,wt,v,n)<<endl;
  return 0;
}
