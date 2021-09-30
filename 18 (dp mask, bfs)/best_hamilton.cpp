#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10;
bool dp[20][M];
int n,m,e[20][20];
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      e[u][v]=e[v][u]=true;
    }
  dp[0][1]=true;
  for(int mask=2;mask<(1<<n);mask++)
    for(int v=1;v<n;v++)
      for(int u=0;u<n;u++)
	if(u!=v && (mask&(1<<u)) && (mask&(1<<v)) && e[u][v])
	  dp[v][mask]|=dp[u][mask^(1<<v)];//mask-{v}
  int all=(1<<n)-1;
  if(n>2)
    for(int v=1;v<n;v++)
      if(e[v][0] && dp[v][all])
	return cout<<"YES"<<endl,0;
  cout<<"NO"<<endl;
  return 0;
}
