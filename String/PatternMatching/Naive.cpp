//Naive Pattern Searching Algo
//TC O((n-m+1)*m)  AS O(1)
#include <bits/stdc++.h>
using namespace std;

void NaivePatSearch(string txt, string pat)
{
  int n=txt.length();
  int m=pat.length();
  // for every i match txt with pat for atmost m length
  //if match is not found set j back to 0 and increment i else print i
  for(int i=0;i<=n-m;i++){
    int j;
    for(j=0;j<m;j++){
      if(txt[i+j]!=pat[j])
      break;
    if(j==m)
    cout<<i<<" ";
  }
}
int main()
{
  string txt="abcabcdabcd";
  string pat="abcd";

  NaivePatSearch(txt,pat);
  return 0;
}
