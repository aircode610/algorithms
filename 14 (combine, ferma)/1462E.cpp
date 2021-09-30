#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e5+10,MOD=1e9+7;
int n,m,k,c[M],s[M],fac[M],ifac[M],ans;
int pw(int a,int b)
{
  if(b==0)return 1;
  int p=pw(a,b/2);
  if(b%2==0)
    return (p*p)%MOD;
  return (((p * p)%MOD) * a)%MOD;
}
int modinv(int a)
{
  return pw(a,MOD-2);
}
int comb(int a,int b)
{
  if(b>a)return 0;
  return fac[a]*ifac[b] %MOD *ifac[a-b] %MOD;
}
int32_t main()
{
  fac[0]=ifac[0]=1;
  for(int i=1;i<M;i++)
    {
      (fac[i]=fac[i-1]*i)%=MOD;
      ifac[i]=modinv(fac[i]);
    }
  int t;cin>>t;
  while(t--)
    {
      cin>>n>>m>>k;
      for(int i=1;i<=n;i++)
	{
	  int x;cin>>x;
	  c[x]++;
	}
      for(int i=1;i<=n;i++)
	s[i]=s[i-1]+c[i];
      //c[4]+c[5]+c[6]+c[7] -> s[7]-s[3]
      //s[i]: sum of elements from 1 to i
      for(int i=1;i<=n;i++)
	{
	  int l=max(1LL,i-k);//l to i
	  int len=s[i]-s[l-1];
	  (ans+=comb(len,m)-comb(len-c[i],m)+MOD)%=MOD;
	}
      cout<<ans<<endl;
      ans=0;
      for(int i=1;i<=n;i++)
	c[i]=s[i]=0;
    }
  return 0;
}
/*
1,1,1,1,2,2,2,3,3,4,4,4,5,6,6,6,7,7,7,7,8,...
comb(11,3)-comb(7,3)
 */
