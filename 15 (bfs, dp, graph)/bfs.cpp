#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int n,m,dis[M],mark[M];
deque <int> saf,g[M];
void bfs(int r)//O(n+m)
{
  mark[r]=true;
  saf.push_back(r);
  while(saf.size())
    {
      int v=saf[0];
      saf.pop_front();
      for(auto u:g[v])
	if(!mark[u])
	  {
	    saf.push_back(u);
	    mark[u]=true;
	    dis[u]=dis[v]+1;
	  }
    }
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  bfs(1);
  for(int i=0;i<n;i++)
    cout<<i<<": "<<dis[i]<<endl;
  return 0;
}
