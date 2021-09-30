#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
const int MOD=1e9+7;
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
int32_t main()
{
  prec();
  cout<<comb(6,3)<<endl;
  return 0;
}
