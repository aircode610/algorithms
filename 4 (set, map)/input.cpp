#include<iostream>
using namespace std;
const int M=35;
int a[M],b[M],n,k;
void clearing()
{
  fill(a,a+M,0);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
    {
      int x;
      cin>>n>>k;
      for(int i=1;i<=n;i++)
	cin>>a[i];
      for(int i=1;i<=n;i++)
	cin>>b[i];
      clearing();
    }
  long long x=1;
  for(int i=1;i<=n;i++)
    {
      x*=2;
      x%=MOD:
    }
  return 0;
}
