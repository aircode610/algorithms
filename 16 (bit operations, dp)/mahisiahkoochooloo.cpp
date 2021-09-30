#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=10;
int a[M][M],dp[M][M],ans;
int p(int mask)
{
  for(int i=0;i<25;i++)
    if(mask&(1<<i))
      a[i/5+1][i%5+1]=1;
    else
      a[i/5+1][i%5+1]=0;
  dp[1][1]=1;
  for(int i=1;i<=5;i++)
    for(int j=1;j<=5;j++)
      if(a[i][j]==1 && i+j>2)
	dp[i][j]=dp[i-1][j]+dp[i][j-1];
      else if(i+j>2)
	dp[i][j]=0;
  return dp[5][5];
}
int32_t main()
{
  for(int mask=0;mask<(1<<23);mask++)
    if(p(((1<<24)|(mask<<1))|1)==1)
      ans++;
  cout<<ans<<endl;
  return 0;
}
