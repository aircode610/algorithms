#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
map<pair<int,int> ,bool>mark;
int n,m;
vector<int>g[M],e;
void dfs(int v)
{
  for(auto u:g[v])
    if(!mark[{v,u}])
      {
	mark[{v,u}]=mark[{u,v}]=true;
	dfs(u);
      }
  e.push_back(v);
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  dfs(1);
  for(auto v:e)
    cout<<v<<" ";
  cout<<endl;
  return 0;
}
