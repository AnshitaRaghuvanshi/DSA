//Check if aone string is subsequence of another
//subseq can be derived by deleting some or no elements without changing order
#include<bits/stdc++.h>
using namespace std;

//compare character at each index from s1 and s2 until i<n and j<m
bool isSubSeq_I(string s1, string s2,int n,int m)
{
  if(n<m)
    return 0;
  int j=0;
  for(int i=0;i<n&&j<m;i++)
  {
    if(s1[i]==s2[j])
    j++;

  }
  return (j==m);
}

bool isSubSeq_R(string s1, string s2,int n,int m)
{
  if(m==0)
    return true;
  if(n==0)
    return false;
  if(s1[n-1]==s2[m-1])
    return isSubSeq_R(s1,s2,n-1,m-1);
  else
    return isSubSeq_R(s1,s2,n-1,m);

}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.length();
  int m=s2.length();
  isSubSeq_I(s1,s2,n,m)?cout<<"YES\n":cout<<"NO\n";//Iterative approach
  isSubSeq_R(s1,s2,n,m)?cout<<"YES\n":cout<<"NO\n";//Recursive approach
  return 0;
}
