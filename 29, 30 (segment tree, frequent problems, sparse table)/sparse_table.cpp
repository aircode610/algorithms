#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
int dp[M][20],a[M],lg[M],n,q;
void precompute()
{
  for(int j=0;(1<<j)<=n;j++)
    for(int i=1;i<=n;i++)
      if(j==0)
	dp[i][j]=a[i];
      else if(i+(1<<(j-1))<=n)
	dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
      else
	dp[i][j]=dp[i][j-1];
  lg[1]=0;
  for(int i=2;i<=n;i++)
    if(__builtin_popcount(i)==1)//(i&(i-1))==0
      lg[i]=lg[i-1]+1;
    else
      lg[i]=lg[i-1];
}
int query(int l,int r)
{
  int len=r-l+1;
  //cout<<dp[l][lg[len]]<<" "<<dp[r-(1<<lg[len])+1][lg[len]]<<endl;
  //cout<<lg[len]<<endl;
  return min(dp[l][lg[len]],dp[r-(1<<lg[len])+1][lg[len]]);
}
int32_t main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  precompute();
  cin>>q;
  while(q--)
    {
      int l,r;
      cin>>l>>r;
      cout<<query(l,r)<<endl;
    }
  return 0;
}
/*
[2,1,4,2,3,1,2,8,0,5]
dpr[i][j]: min element of [i,i+2^j];
dpl[i][j]: min [i,i-2^j];//extra
dpl[i][j]=dpr[i-2^j][j]
[l,r]
1001011
1
10
100
1000
0111
1100
1011
...
[.,.,.,.,.,.,.,.]
 */
