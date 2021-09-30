#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10,MOD=1e9+7;
int a,b,n,m,k,mark[M];
bool fard;
vector<int>g[M];
//
#define _ %MOD
#define __ %=MOD
int fac[M],ifac[M];
int pw(int a,int b)
{
  if(b==0LL)return 1LL;
  int p=pw(a,b/2LL);
  if(b%2LL==0LL)
    return p*p _;
  return p*p _ * a _;
}
int inv(int a)
{
  return pw(a,MOD-2);
}
int comb(int a,int b)
{
  if(b>a)return 0;
  return fac[a]*ifac[b] _ *ifac[a-b] _;//a!/(b!(a-b)!)
}
void prec()
{
  fac[0]=ifac[0]=1LL;
  for(int i=1;i<M;i++)
    {
      fac[i]=fac[i-1]*i _ ;
      ifac[i]=inv(fac[i]);
    }
}
//
void dfs(int v,int col)
{
  mark[v]=col;
  if(col==1)
    a++;
  else
    b++;
  for(auto u:g[v])
    if(!mark[u])
      dfs(u,3-col);
    else if(mark[u]==mark[v])
      fard=true;
}
int32_t main()
{
  prec();
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  dfs(1,1);
  if(fard)
    cout<<comb(comb(n,2)-m,k)*fac[k] _ <<endl;
  else
    cout<<(comb(comb(n,2)-m,k)*fac[k] _ - comb(a*b-m,k)*fac[k] _ +MOD) _<<endl;
  return 0;
}
/*
C(C(n,2)-m,k)*k!
C(C(n,2)-m,k)*k!-(a*b-m,k)*k!
*/
