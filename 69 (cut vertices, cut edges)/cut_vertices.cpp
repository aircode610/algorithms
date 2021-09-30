#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=1e5+10;
int n,m,r,dep[M];
bool mark[M],cv[M];
vector<int>g[M];
int dfs(int v,int h)
{
	mark[v]=true;
	dep[v]=h;
	int ret=M,cnt=0;
	for(auto u:g[v])
		if(!mark[u])
		{
			cnt++;
			int back=dfs(u,h+1);
			if(back==h)
				cv[v]=true;
			ret=min(back,ret);
		}
		else
			ret=min(ret,dep[u]);
	if(v==r && cnt==1)
		cv[v]=false;
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
	//	cin>>r;
	r=0;
	dfs(r,0);
	for(int i=0;i<n;i++)
		if(cv[i])
			cout<<i<<endl;
	return 0;
}