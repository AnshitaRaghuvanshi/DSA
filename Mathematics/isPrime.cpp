//To check if a given number is prime
#include<bits/stdc++.h>
using namespace std;

//TC O(n)
bool isPrimeNaive(int n)
{
  if(n==1)return false;
  for(int i=2;i<n;i++)
    if(n%i==0)
    return false;
  return true;
}

//TC O(√n)
bool isPrimeBetter(int n)
{
  if(n==1) return false;
  for(int i=0;i*i<n;i++)
    if(n%i==0)
    return false;
  return true;
}

bool isPrimeEfficient(int n)
{
  if(n==1) return false;
  if(n==2 || n==3) return true;
  if(n%2==0 || n%3==0) return false;
  for(int i=5;i*i<=n;i=i+6)
  {
    if(n%i==0||n%(i+2)==0)
    return false;
  }
  return true;
}

int main()
{
   int a;
   cin>>a;
   (isPrimeNaive(a))?cout<<"YES\n":cout<<"NO\n";
   (isPrimeBetter(a))?cout<<"YES\n":cout<<"NO\n";
   (isPrimeEfficient(a))?cout<<"YES\n":cout<<"NO\n";
}
