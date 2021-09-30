#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,INF=1e9;
set<pair<int,int> >s;
int n,m,dis[M];
bool mark[M];
vector<pair<int,int> >g[M];
void dijkstra(int r)//m*log(n)
{
  fill(dis,dis+M,INF);
  dis[r]=0;
  s.insert({dis[r],r});
  while(s.size())
    {
      int v=(*s.begin()).second;
      s.erase(*s.begin());
      mark[v]=true;
      for(auto p:g[v])
	{
	  int u=p.first;
	  if(!mark[u])
	  {
	    s.erase({dis[u],u});
	    dis[u]=min(dis[u],dis[v]+p.second);
	    s.insert({dis[u],u});
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
      g[v].push_back({u,w});
      g[u].push_back({v,w});
    }
  dijkstra(1);
  for(int i=1;i<=n;i++)
    cout<<dis[i]<<" ";
  cout<<endl;
  return 0;
}
