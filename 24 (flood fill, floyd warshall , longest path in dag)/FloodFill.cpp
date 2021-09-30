#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e2+10;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
//{1,1},{1,-1},{-1,1},{-1,-1}
int n,m;
bool mark[M][M];
char mp[M][M];
void dfs(int x,int y)
{
  //(x-1,y),(x+1,y),(x,y+1),(x,y-1)
  mark[x][y]=true;
  for(int d=0;d<4;d++)
    {
      int nx=x+dir[d][0],ny=y+dir[d][1];
      if(!mark[nx][ny] && mp[nx][ny]=='*')
	dfs(nx,ny);
    }
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>mp[i][j];
  dfs(1,1);
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
	cout<<mark[i][j];
      cout<<endl;
    }
  return 0;
}
/*
4 6
****#*
##***#
***#**
**###*
*/
