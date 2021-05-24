//KMP Pattern Searching Algo
//TC O(n)  AS O(n)
#include <bits/stdc++.h>
using namespace std;

//Filling Longest proper prefix suffix array
//if characters match update len and lps
//if characters do not match recursively apply len=lps[len-1], until len=0
void fillLPS(string str,int lps[])
{
  int n=str.length();
  int len=0,i=1;
  lps[0]=0;
  while(i<n){
    if(str[i]==str[len]){
      len++;
      lps[i]=len;
      i++;
    }
    else{
      if(len==0){
        lps[i]=0;
        i++;
      }
      else
        len=lps[len-1];
    }
  }
}

//if characters dont match set j to the value in lps[j-1]
//This avoids checking characters that are already matching
void KMP(string txt, string pat)
{
  int n=txt.length();
  int m=pat.length();
  int lps[m];
  fillLPS(pat,lps);
  int i=0,j=0;
  while(i<n){
    if(txt[i]==pat[j]){
      i++;
      j++;
    }
    if(j==m){
      cout<<i-j<<endl;
      j=lps[j-1];
    }
    else if(i<n && txt[i]!=pat[j]){
      if(j==0)
      i++;
      else
      j=lps[j-1];
    }
  }
}


int main()
{
  string txt="ababcabababa";
  string pat="ababa";

  KMP(txt,pat);
  return 0;
}
