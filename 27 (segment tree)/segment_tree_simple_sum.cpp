#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
struct node{
  int left;
  int right;
  int sum;
};
node st[M];
int n,a[M],q;
void build_tree(int i,int l,int r)
{
  st[i].left=l;
  st[i].right=r;
  if(l==r)
    {
      st[i].sum=a[l];
      return;
    }
  int mid=(l+r)/2;//[l,mid],[mid+1,r]
  build_tree(2*i,l,mid);
  build_tree(2*i+1,mid+1,r);
  st[i].sum=st[2*i].sum+st[2*i+1].sum;
}
int query(int i,int l,int r)
{
  if(l==st[i].left && r==st[i].right)
    return st[i].sum;
  int mid=(st[i].left+st[i].right)/2;
  if(r<=mid)//[l,r] is in [st[i].left,mid]
    return query(2*i,l,r);
  if(l>mid)//[l,r] is in [mid+1,st[i].right]
    return query(2*i+1,l,r);
  //[l,r] shoud be divided to two segment
  return query(2*i,l,mid)+query(2*i+1,mid+1,r);
}
void update(int i,int ind,int x)
{
  if(st[i].left==st[i].right)
    {
      a[ind]=x;
      st[i].sum=x;
      return;
    }
  int mid=(st[i].left+st[i].right)/2;
  if(ind<=mid)
    update(2*i,ind,x);
  else
    update(2*i+1,ind,x);
  st[i].sum=st[2*i].sum+st[2*i+1].sum;
}
int32_t main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  build_tree(1,1,n);
  cin>>q;
  while(q--)
    {
      int type;
      cin>>type;
      if(type==1)
	{
	  int l,r;
	  cin>>l>>r;
	  cout<<query(1,l,r)<<endl;
	}
      else
	{
	  int i,x;
	  cin>>i>>x;
	  update(1,i,x);
	}
    }
  return 0;
}
