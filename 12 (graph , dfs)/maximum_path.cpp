#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int dp[M],n,ans,w[M];
vector<int>g[M];
void dfs(int v,int par)
{
  for(auto u:g[v])
    if(u!=par)
      {
	dfs(u,v);
	ans=max(ans,dp[v]+dp[u]+w[v]);
	dp[v]=max(dp[v],dp[u]);
      }
  dp[v]+=w[v];
  ans=max(dp[v],ans);
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>w[i];
  for(int i=1;i<n;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  dfs(1,1);
  cout<<ans<<endl;
  return 0;
}
