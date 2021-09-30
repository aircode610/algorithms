#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=1e5+10;
int n,m,r,dep[M];
bool mark[M],cv[M];
vector<int>g[M];
vector<pair<int,int> > ans;
int dfs(int v,int par,int h)
{
	mark[v]=true;
	dep[v]=h;
	int ret=M;
	for(auto u:g[v])
		if(!mark[u])
		{
			int back=dfs(u,v,h+1);
			if(back>h)
				ans.push_back({min(u,v),max(u,v)});
			ret=min(back,ret);
		}
		else if(u!=par)
			ret=min(ret,dep[u]);
	return ret;
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
	dfs(0,0,0);
	sort(ans.begin(),ans.end());
	for(auto p:ans)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}