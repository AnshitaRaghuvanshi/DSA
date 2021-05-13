//Check if given string is pallindrome by Naive and Efficiet approach 
#include<bits/stdc++.h>
using namespace std;

//naive approach TC: θ (n) AS: θ (n)
//reverse the string and compare with original string
void ispallindromeN(string str)
{
  string rev=str;
  reverse(rev.begin(),rev.end());
  if(rev==str)
  cout<<"YES"<<endl;
  else
  cout<<"NO"<<endl;
}

//efficient approach TC: O(n) AS:O(1)
//match characters from start and end until mid is reached
void ispallindromeE(string str)
{
  int n=str.size();
  for(int i=0;i<n/2;i++)
  {
    if(str[i]!=str[n-1-i])
    {
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
}
int main()
{
  string str;
  bool c;
  cin>>str;
  ispallindromeN(str);
  ispallindromeE(str);
}
