#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,m,part[M];
vector<int>g[M];
bool NO;
void dfs(int v,int col)
{
	part[v]=col;
	for(auto u:g[v])
		if(!part[u])
			dfs(u,3-col);
		else if(part[u]==part[v])
			NO=true;
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
	dfs(1,1);
	if(NO)
		cout<<"Not bipartite!"<<endl;
	else
		for(int i=1;i<=n;i++)
			cout<<part[i]<<" ";
	return 0;
}