#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int fen[M],n;
int lb(int x)//1011000->1010111-->1111
{
  return ((x^(x-1))&x);
}
void update(int k,int x)
{
  if(k>n)return;
  fen[k]+=x;
  update(k+lb(k),x);
}
int query(int k)
{
  if(k==0)return 0;
  return query(k-lb(k))+fen[k];
}
int32_t main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      update(i,x);
    }
  int q;
  cin>>q;
  while(q--)
    {
      int l,r;
      cin>>l>>r;
      cout<<query(r)-query(l-1)<<endl;
    }
  return 0;
}
