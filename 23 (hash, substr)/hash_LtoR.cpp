#include<bits/stdc++.h>
using namespace std;
#define int long long
#define hash adfasdfasf
const int M=1e6+10,MOD=999983,p=601;
int pp[M],ipp[M],ph[M];
string s;
int pw(int a,int b)
{
  if(b==0LL)return 1LL;
  int p=pw(a,b/2LL);
  if(b%2LL==0LL)
    return p*p %MOD;
  return p*p %MOD * a %MOD;
}
int modinv(int a)
{
  return pw(a,MOD-2);
}
int hash(int l,int r)
{
  return ((ph[r]-ph[l-1]+MOD)*ipp[l])%MOD;
  //s[l]*p^l+s[l+1]*p^(l+1)+...+s[r]*p^r;
}
int32_t main()
{
  cin>>s;
  s='.'+s;
  pp[0]=1;
  for(int i=1;i<M;i++)
    {
      (pp[i]=pp[i-1]*p)%=MOD;
      ipp[i]=modinv(pp[i]);
    }
  for(int i=1;i<s.size();i++)
    (ph[i]=ph[i-1]+s[i]*pp[i])%=MOD;
  cout<<hash(4,7)<<endl;//hash(s.substr(4,4));
  /*int ans=0;
  for(int i=4;i<=7;i++)
    (ans+=s[i]*pp[i-4])%=MOD;
  cout<<ans<<endl;*/
  return 0;
}
