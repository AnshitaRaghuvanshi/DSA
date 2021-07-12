//Coin Change Problem : Solving using DP (Tabulation)
//Problem: Given a sum N, find the number of ways to make change for N cents,
//if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
#include <bits/stdc++.h>
using namespace std;
int CountChange(int coins[], int n, int sum){
  int dp[sum+1][n+1];

  for(int i=0; i<n+1; i++){
    dp[0][i] = 1; //BC1
  }

  for(int i=0;i<sum+1;i++){
    dp[i][0] = 0; //BC2
  }

  for(int i=1;i<sum+1;i++){
    for(int j=1;j<n+1;j++){
      dp[i][j] = dp[i][j-1]; //1
      if(coins[j-1] <= i){
        dp[i][j] += dp[i-coins[j-1]][j];
      }
    }
  }
  return dp[sum][n];
}

int main(){
  int m=3; //size of array;
  int coins[3]={1,2,3};
  int sum=4;
  cout<<CountChange(coins, m, sum)<<endl;
  return 0;
}



/*
--------------------------------------------------------------------------------------------------------------------
Recursive Approach:
    either pick the coin or don't
    1. If the coin is not picked : count(coins, n-1, sum)  -----> coin is ignored
    2. If coin is picked : count(coins, n, sum- coins[n-1])   -----> unlimited supply of coin so n is not decreased
    Base Case:(BC)
      1. if sum becomes 0, no more coins have to be picked ----> return 1
      2. if no coin is left and sum>=0 , no coin is left to be picked ----> return 0
*/
