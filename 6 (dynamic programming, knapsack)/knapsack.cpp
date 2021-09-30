#include<bits/stdc++.h>
using namespace std;
const int M=1e3+10;
int ans,dp[M][M],n,W,c[M],w[M];
int main()
{
  cin>>n>>W;
  for(int i=1;i<=n;i++)
    cin>>w[i];
  for(int i=1;i<=n;i++)
    cin>>c[i];
  for(int i=1;i<=n;i++)
    for(int j=0;j<=W;j++)
      if(j>=w[i])
	dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
      else
	dp[i][j]=dp[i-1][j];
  /*for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=W;j++)
	cout<<dp[i][j]<<" ";
      cout<<endl;
    }*/
  for(int j=1;j<=W;j++)
    ans=max(ans,dp[n][j]);
  cout<<ans<<endl;
  return 0;
}
/*
n W
w=[w1,w2,...,wn]
c=[c1,c2,...,cn]

3 7
5  3 3
15 8 8

dp[i][j]=best answer for first i element and weight of knapsack j.
update: dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
bases: dp[0][0]=0;
answer: dp[n][j],j<=W
*/
