//To find gcd of two numbers
//Note: gcd is always equal or less than the min of 2 numbers

#include<bits/stdc++.h>
using namespace std;

//Naive Solution TC O(min(a,b))
int NaiveGCD(int a,int b)
{
  int res=min(a,b);
  while(res>0)
  {
    if(a%res==0 && b%res==0)
    break;
    res--;
  }
  return res;
}

//Euclidean Algorithm [let a=gx and b=gy then a-b=g(x-y) where g is gcd(a,b)]
int EucledianGCD(int a,int b)
{
  while(a!=b)
  {
    if(a>b)
      a=a-b;
    else
      b=b-a;
  }
  return a;

}

//Optimsed Implementation of Euclidean Algorithm TC O(log(min(a,b)))
int OptimisedEucledianGCD(int a,int b)
{
  if(b==0)
  return a;
  else
  return OptimisedEucledianGCD(b,a%b);
}

int main()
{
   int a,b;
   cin>>a>>b;
   cout<<NaiveGCD(a,b)<<"\n";
   cout<<EucledianGCD(a,b)<<"\n";
   cout<<OptimisedEucledianGCD(a,b)<<"\n";
}
