#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int par[M],sz[M],n,q;
int root(int v)
{
  if(par[v]==v)
    return v;
  return par[v]=root(par[v]);
}
void join(int u,int v)
{
  int ru=root(u),rv=root(v);
  if(ru==rv)
    return;
  par[ru]=rv;
  sz[rv]+=sz[ru];
}
int32_t main()
{
  cin>>n>>q;
  for(int i=1;i<=n;i++)
    par[i]=i,sz[i]=1;
  while(q--)
    {
      int type;
      cin>>type;
      if(type==1)
	{
	  int u,v;
	  cin>>u>>v;
	  join(u,v);
	}
      else
	{
	  int v;
	  cin>>v;
	  cout<<sz[root(v)]<<endl;
	}
    }
  return 0;
}
