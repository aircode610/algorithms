#include<bits/stdc++.h>
using namespace std;
const int M=105;
int n,a[M][M],ans=-130,dp[M][M];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
  for(int i1=1;i1<=n;i1++)
    for(int j1=1;j1<=n;j1++)
      for(int i2=1;i2<=i1;i2++)
	for(int j2=1;j2<=j1;j2++)
	  ans=max(dp[i1][j1]-dp[i2-1][j1]-dp[i1][j2-1]+dp[i2-1][j2-1],ans);
  cout<<ans<<endl;
  return 0;
}
