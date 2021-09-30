#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int m[M][3],n,dp[M],ans=M,far[M];
vector<int>g[M],ansv;
void dfs(int v,int par)
{
  m[v][0]=m[v][1]=m[v][2]=-1;
  for(auto u:g[v])
    if(u!=par)
      {
	dfs(u,v);
	dp[v]=max(dp[v],dp[u]+1);
	m[v][0]=dp[u];
	sort(m[v],m[v]+3);
      }
}
void dfs2(int v,int par,int up)
{
  far[v]=max(dp[v],up);
  ans=min(ans,far[v]);
  //cout<<v<<" "<<dp[v]<<" "<<up<<endl;
  for(auto u:g[v])
    if(u!=par)
      {
	if(dp[u]!=m[v][2])
	  dfs2(u,v,max(m[v][2]+2,up+1));
	else
	  dfs2(u,v,max(m[v][1]+2,up+1));
      }
}
int main()
{
  cin>>n;
  for(int i=2;i<=n;i++)
    {
      int par;cin>>par;
      g[par].push_back(i);
      g[i].push_back(par);
    }
  dfs(1,1);
  dfs2(1,1,0);
  //for(int i=1;i<=n;i++)cout<<far[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)
    if(far[i]==ans)
      ansv.push_back(i);
  sort(ansv.begin(),ansv.end());
  for(auto v:ansv)
    cout<<v<<" ";
  cout<<endl;
  return 0;
}
/*
dp[v]: length of longest path in subtree of v and starts on v
*/
