#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
vector<int>g[M],rg[M],s;
set<int>d[M];
int n,m,col[M];
bool mark[M],del[M];
void dfs1(int v)
{
  mark[v]=true;
  for(auto u:g[v])
    if(!mark[u])
      dfs1(u);
  s.push_back(v);
}
void dfs2(int v,int c)
{
  //cout<<v<<" "<<c<<endl;
  del[v]=true;
  col[v]=c;
  for(auto u:rg[v])
    if(!del[u])
      dfs2(u,c);
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      rg[v].push_back(u);
    }
  //cout<<rg[1][0]<<endl;
  for(int i=1;i<=n;i++)
    if(!mark[i])
      dfs1(i);
  //for(auto x:s)cout<<x<<" "<<endl;
  int c=0;
  for(int i=s.size()-1;i>=0;i--)
    if(!del[s[i]])
      dfs2(s[i],++c);
  for(int i=1;i<=n;i++)
    cout<<i<<": "<<col[i]<<endl;
  for(int v=1;v<=n;v++)
    for(auto u:g[v])
      if(col[u]!=col[v])
	d[col[v]].insert(col[u]);
  return 0;
}
