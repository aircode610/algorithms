#include<bits/stdc++.h>
using namespace std;
const int M=110;
int dp[M][M];
string a,b;
int main()
{
  cin>>a>>b;
  a="-"+a;
  b="-"+b;
  for(int i=1;i<a.size();i++){
    for(int j=1;j<b.size();j++)
      {
	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	if(a[i]==b[j])
	  dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
	cout<<dp[i][j]<<" ";
      }
    cout<<endl;}
  cout<<dp[a.size()-1][b.size()-1]<<endl;
  return 0;
}
/*
a="asdfaas d faaa"
b="afasdfaa d faaasdfa"

dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
or
dp[i][j]=dp[i-1][j-1]+1;

answer: dp[n][m];

"ab c   "
"a c d e"
*/
