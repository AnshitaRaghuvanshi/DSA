//Implementing Multi-Dimensional Array using array of pointers
#include<bits/stdc++.h>
using namespace std;
int main()
{
  //To create a 2d array of size mxn
  int m=3,n=2;
  int *arr[m];
  //Allocate memory to each pointer
  for(int i=0;i<m;i++)
  {
    arr[i]=new int[n];
  }

  //Assign values to the array
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
       arr[i][j]=i+j;
    }
  }


 //Display Array
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
