#include<bits/stdc++.h>
using namespace std;
const int M=200+10;
int dp[M][10],C[10]={1,2,5,10,20,50,100,200};
int main()
{
  for(int i=1;i<=200;i++)
    for(int j=0;C[j]<=i && j<8;j++)
      {
	for(int k=0;k<=j;k++)
	  dp[i][j]+=dp[i-C[j]][k];
	if(i==C[j])
	  dp[i][j]++;
      }
  int ans=0;
  for(int j=0;j<8;j++)
    ans+=dp[200][j];
  cout<<ans<<endl;
  return 0;
}
/*
C={1,2,5,10,20,50,100,200}
dp[i][j]=ways of making i such that largest coin is C[j].
update: 
dp[5]=dp[0]+dp[4]+dp[3]
5=(2,2,1)=(1,2,2)
(2,)
(1,2,2)
answer: dp[200][j],j in C
 */
