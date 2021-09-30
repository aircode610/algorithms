#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int in[M],n,m;
vector<int>g[M],ans;
deque<int>saf;
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      in[v]++;
    }
  for(int i=0;i<n;i++)
    if(in[i]==0)
      saf.push_back(i);
  while(saf.size())
    {
      int v=saf[0];
      ans.push_back(v);
      saf.pop_front();
      for(auto u:g[v])
	{
	  in[u]--;
	  if(in[u]==0)
	    saf.push_back(u);
	}
    }
  if(ans.size()==n)
    {
      cout<<"YES"<<endl;
      for(auto x:ans)
	cout<<x<<" ";
      cout<<endl;
    }
  else
    cout<<"NO"<<endl;
  return 0;
}
