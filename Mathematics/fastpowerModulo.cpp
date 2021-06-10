//Calculating power using Modulo Exponention
#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
long long fastPower(long long x,long long y)
{
  long long temp=1;
  while(y>0)
  {
    if(y%2==1)
    temp=(temp*x)%M;
    x=(x*x)%M;
    y=y/2;
  }
  return temp;
}
int main()
{
  long long x,exp;
  cin>>x>>exp;
  //Calculating x^y
  cout<<fastPower(x,exp);
  return 0;
}
