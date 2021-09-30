#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
vector<pair<int,pair<int,int> > >e;
vector<pair<int,int> >ans;
int n,par[M],sum,m;
int root(int v)
{
  if(par[v]==v)
    return v;
  return par[v]=root(par[v]);
}
void join(int u,int v,int w)
{
  int ru=root(u),rv=root(v);
  if(ru==rv)
    return;
  par[ru]=rv;
  ans.push_back({u,v});
  cout<<u<<" "<<v<<" "<<w<<endl;
  sum+=w;
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      e.push_back({w,{u,v}});
    }
  sort(e.begin(),e.end());
  for(int i=1;i<=n;i++)
    par[i]=i;
  for(auto p:e)
    {
      join(p.second.first,p.second.second,p.first);
    }
  cout<<sum<<endl;
  for(auto p:ans)
    cout<<p.first<<" "<<p.second<<endl;
  return 0;
}
