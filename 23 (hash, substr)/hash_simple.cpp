#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10;
const int p=999983;
const int q=823;
int n;
set<int>h[M];
int hash(int x)
{
  return x*q%p;
}
int32_t main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      h[hash(x)].insert(x);
    }
  int query;
  cin>>query;
  while(query--)
    {
      int x;cin>>x;
      if(h[hash(x)].find(x)==h[hash(x)].end())
	cout<<"Not found"<<endl;
      else
	cout<<"Found"<<endl;
    }
  return 0;
}
