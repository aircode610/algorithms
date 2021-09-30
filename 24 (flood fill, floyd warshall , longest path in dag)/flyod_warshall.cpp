#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=110,INF=1e9;
int up[M][M],dis[M][M],n,m;
void wfl()
{
  for(int k=1;k<=n;k++)
    for(int v=1;v<=n;v++)
      for(int u=1;u<=n;u++)
	if(dis[v][k]+dis[k][u]<dis[v][u])
	  {
	    up[v][u]=k;
	    dis[v][u]=dis[v][k]+dis[k][u];
	  }
}
void print_path(int u,int v)//[u,v)
{
  if(up[u][v]==0)
    return;
  print_path(u,up[u][v]);
  cout<<up[u][v]<<" ";
  print_path(up[u][v],v);
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(i!=j)
	dis[i][j]=INF;
  for(int i=0;i<m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      dis[u][v]=w;
      dis[v][u]=w;
    }
  wfl();
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
	cout<<dis[i][j]<<" ";
      cout<<endl;
    }
  int x,y;
  cin>>x>>y;
  cout<<x<<" ";
  print_path(x,y);
  cout<<y<<endl;
  return 0;
}
