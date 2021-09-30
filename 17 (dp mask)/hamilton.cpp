#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int dp[20][20][M],n,m,e[20][20];
int32_t main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
    {
      int u,v;cin>>u>>v;
      e[u][v]=e[v][u]=true;
      dp[u][v][(1<<v)|(1<<u)]=true;
    }
  for(int mask=0;mask<(1<<n);mask++)
    for(int v=0;v<n;v++)
      for(int u=0;u<n;u++)
	if(u!=v && (mask&(1<<v)) && (mask&(1<<u)))
	  for(int w=0;w<n;w++)
	    if(w!=u && w!=v && (mask&(1<<w)) && e[v][w])
	      dp[u][v][mask]|=dp[u][w][mask^(1<<v)];
  int all=(1<<n)-1;
  for(int v=0;v<n;v++)
    for(int u=0;u<n;u++)
      if(u!=v && e[u][v] && dp[u][v][all])
	{
	  cout<<"YES"<<endl;
	  return 0;
	}
  cout<<"NO"<<endl;
  return 0;
}
/*
dp[u][v][mask] in {0,1}
dp[0][1][7]=false
dp[0][1][19]=true
dp[u][v][mask]=dp[u][w][mask-(1<<v)] for all w in mask s.t there is an edge between v and w
 */
