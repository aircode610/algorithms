#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10,INF=100000000;
int dp[M],a[M],n,lis;
int main()
{
  cin>>n;
  fill(dp+1,dp+M,INF);
  for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      int l=0,r=lis+1,mid;//(0,lis+1]
      while(r-l>1)
	{
	  mid=(l+r)/2;
	  if(dp[mid]>=a[i])
	    r=mid;
	  else
	    l=mid;
	}
      dp[r]=a[i];
      lis=max(lis,r);
    }
  cout<<lis<<endl;
  for(int i=1;i<=lis;i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  return 0;
}
/*
1,5,3,6,2,5,3,|4|,5,7,5
LIS=5
for on i from 1 to n
dp[j]=best last of all subsequences with length j
dp={1,2,3,4,5,7,INF,INF,INF,...}
 */
