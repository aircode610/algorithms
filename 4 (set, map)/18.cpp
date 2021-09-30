#include<iostream>
#include<algorithm>
using namespace std;
int a[100][100];
int f(int x,int y)
{
  if(x==15)
    return a[x][y];
  return max(f(x+1,y),f(x+1,y+1))+a[x][y];
}
int main()
{
  for(int i=1;i<=15;i++)
    for(int j=1;j<=i;j++)
      cin>>a[i][j];
  cout<<f(1,1)<<endl;
  return 0;
}
