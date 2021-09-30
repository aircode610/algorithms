#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int a[M];
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    a[i]=rand()%10000;
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";cout<<endl;
  int x;cin>>x;
  //[l,r] -> [4,7]={4,5,6,7}
  //(l,r) -> (4,7)={5,6}
  //[l,r) -> [4,7)={4,5,6}
  //int cnt=0;
  int l=1,r=n+1,mid;//answer always in [l,r)
  while(r-l>1)
    {
      //cnt++;
      mid=(l+r)/2;
      if(a[mid]>=x)
	l=mid;
      else
	r=mid;
    }
  //cout<<cnt<<endl;
  if(a[l]==x)cout<<"found"<<endl;
  else cout<<"NOT found"<<endl;
  return 0;
}
