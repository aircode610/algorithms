#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int T,n,a[M],b[M],S;
bool comp(int k)
{
  for(int i=1;i<=n;i++)
    b[i]=a[i]+i*k;
  sort(b+1,b+n+1);
  T=0;
  for(int i=1;i<=k;i++)
    T+=b[i];
  if(T<=S)
    return true;
  return false;
}
int main()
{
  cin>>n>>S;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  int l=0,r=n+1,mid;//[l,r)
  while(r-l>1)
    {
      mid=(l+r)/2;
      if(comp(mid))
	l=mid;
      else
	r=mid;
    }
  comp(l);
  cout<<l<<" "<<T<<endl;
  return 0;
}
/*
{1,2}
2+1*2+3+2*2
{2,3,5},k=2
{4,7,11}
 */
//1,1,1,1,1,1,1,0,0,0,0,0,0
