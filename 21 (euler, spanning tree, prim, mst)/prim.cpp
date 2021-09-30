#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,INF=1e9;
set<pair<int,int> >s;
vector<pair<int,int> >g[M];
int n,m,par[M],wp[M],ans;
bool mark[M];
void prim(int r)
{
  fill(wp,wp+M,INF);
  wp[r]=0;
  par[r]=r;
  s.insert({0,r});
  while(s.size())
    {
      int v=(*s.begin()).second;
      ans+=(*s.begin()).first;
      mark[v]=true;
      s.erase(*s.begin());
      for(auto p:g[v])
	{
	  int u=p.first;
	  int w=p.second;
	  if(!mark[u])
	    {
	      s.erase({wp[u],u});
	      if(wp[u]>w)
		wp[u]=w,par[u]=v;
	      s.insert({wp[u],u});
	    }
	}
    }
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      g[u].push_back({v,w});
      g[v].push_back({u,w});
    }
  prim(2);
  for(int i=1;i<=n;i++)
    cout<<i<<": "<<par[i]<<endl;
  cout<<ans<<endl;
  return 0;
}
