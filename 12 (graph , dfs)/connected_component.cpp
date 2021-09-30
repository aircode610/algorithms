#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
vector<int> g[M];
int mark[M];
int n,m,cnt;
void dfs(int v)
{
  mark[v]=cnt;
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i]])
      dfs(g[v][i]);
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  for(int i=1;i<=n;i++)
    if(!mark[i])
      {
	cnt++;
	dfs(i);
      }
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++)
    cout<<mark[i]<<" ";
  return 0;
}
//1 1 1 1 1 1 2 2 2 3
