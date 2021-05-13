//Reverse a string
#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 60
string Reverse(string str)
{
  int n=str.size();
  for(int i=0;i<n/2;i++)
  {
    char temp=str[i];
    str[i]=str[n-1-i];
    str[n-1-i]=temp;
  }
  return str;
}
int main()
{
  //2 input methods
  string str;
  getline(cin,str);
  //char str[MAXLEN];
  //cin.getline(str,MAXLEN);

  string rev1=Reverse(str);
  cout<<rev1<<endl;

  // Using reverse function in stl
    reverse(str.begin(), str.end());
    cout<<str<<endl;

}
