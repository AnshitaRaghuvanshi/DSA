//Edit Distance Problem convert s1 to s2 using insert del or replace using min operations
#include<bits/stdc++.h>
using namespace std;
int RecursiveED(string s1,string s2, int m,int n)
{
  if(m==0)
  return n;  //if s1 is empty we will have to insert all m characters
  if(n==0)
  return m;  //if s2 is empty we will have to delete all n characters
  if(s1[m-1]==s2[n-1])
  RecursiveED(s1,s2,m-1,n-1); //if characters match ignore them
  else{
    return (1+min(RecursiveED(s1,s2,m-1,n),min(RecursiveED(s1,s2,m,n-1),RecursiveED(s1,s2,m-1,n-1))));
    // else find minimum of  deletion  ^        insertion ^                   replacement ^
  }
}


int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int m=s1.length(),n=s2.length();
  cout<<RecursiveED(s1,s2,m,n);


  return 0;
}
