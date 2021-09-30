#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
vector<int>g[M];
int dp[M],n,m,w[M];
bool mark[M];
void dfs(int v)
{
  mark[v]=true;
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i]])
      {
	dfs(g[v][i]);
	dp[v]=max(dp[v],dp[g[v][i]]);
      }
  dp[v]+=w[v];
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
  dfs(1);
  cout<<dp[1]<<endl;
  //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
  return 0;
}
