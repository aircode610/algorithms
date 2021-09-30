#include<iostream>
#include<vector>
using namespace std;
int a[100],n;
void merge_sort(int l,int r)
{
  if(l==r)return;
  int mid=(l+r)/2;
  merge_sort(l,mid);
  merge_sort(mid+1,r);
  //merge from l to r
  vector<int>v;
  int p=l,q=mid+1;
  while(p<=mid || q<=r)
    {
      if(p>mid)
	v.push_back(a[q++]);
      else if(q>r)
	v.push_back(a[p++]);
      else if(a[p]<a[q])
	v.push_back(a[p++]);
      else
	v.push_back(a[q++]);
    }
  for(int i=0;i<v.size();i++)
      a[l+i]=v[i];
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  merge_sort(1,n);
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
//sort(v.begin(),v.end())
