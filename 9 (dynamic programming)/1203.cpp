#include<bits/stdc++.h>
using namespace std;
const int M=30030;
int n,v[M],dp[M],up[M];
void prt(int t)
{
  if(t==0)return;
  if(up[t]==0)
    prt(t-1);
  else
    {
      prt(up[t]-1);
      cout<<up[t]<<" "<<t<<endl;
    }
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      int s,t;
      cin>>s>>t;
      v[t]=max(v[t],s);
    }
  for(int i=1;i<=30000;i++)
    {
      dp[i]=dp[i-1];
      if(v[i]!=0)
	{
	  if(dp[i]<dp[v[i]-1]+1)
	    {
	      dp[i]=dp[v[i]-1]+1;
	      up[i]=v[i];
	    }
	}
    }
  cout<<dp[30000]<<endl;
  prt(30000);
  return 0;
}
