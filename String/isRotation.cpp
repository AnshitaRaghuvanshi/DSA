//Tocheck if a string is rotation of another
//Rotation same characters, same order, just rotated by some moves eg abcd , dabc

//TC: θ(n)   AS: θ(n)
#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2)
{
  if(s1.length()!=s2.length())
  return false;

  string s=s1+s1;  //s="abcdabcd"

  return(s.find(s2)!=string::npos);
}
int main()
{
    string s1= "abdc";
    string s2="dcab";
    isRotation(s1,s2)?cout<<"True\n":cout<<"False\n";

    return 0;
}
