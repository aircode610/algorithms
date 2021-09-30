#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> a[1000];
int n;
bool cmp(pair<int,int> p,pair<int,int> q)
{
  if(p.second<q.second)
    return true;
  else if(p.second>q.second)
    return false;
  else
    return p.first<=q.first;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i].first>>a[i].second;
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++)
    cout<<a[i].first<<" "<<a[i].second<<endl;
  return 0;
}
//a<b & b<c => a<c
