#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int ans,n,m,dp[M];
vector<int>g[M];
bool mark[M];
int mem(int v)
{
  if(mark[v])
    return dp[v];
  mark[v]=true;
  for(auto u:g[v])
    dp[v]=max(mem(u)+1,dp[v]);
  return dp[v];
}
int32_t main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
    }
  for(int i=1;i<=n;i++)
    ans=max(ans,mem(i));
  cout<<ans<<endl;
  return 0;
}
