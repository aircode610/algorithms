#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10;
struct node{
  int left;
  int right;
  int sum;
  int lazy;
};
node st[M];
int n,a[M],q;
void push_lazy(int i)
{
  st[i].sum+=st[i].lazy*(st[i].right-st[i].left+1);
  st[2*i].lazy+=st[i].lazy;
  st[2*i+1].lazy+=st[i].lazy;
  st[i].lazy=0;
}
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
  push_lazy(i);
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
void update(int i,int l,int r,int x)
{
  push_lazy(i);
  if(l==st[i].left && r==st[i].right)
    {
      st[i].sum+=x*(st[i].right-st[i].left+1);
      if(st[i].left!=st[i].right)
	{
	  st[2*i].lazy+=x;
	  st[2*i+1].lazy+=x;
	}
      return;
    }
  int mid=(st[i].left+st[i].right)/2;
  if(mid>=r)
    update(2*i,l,r,x);
  else if(mid<l)
    update(2*i+1,l,r,x);
  else
    {
      update(2*i,l,mid,x);
      update(2*i+1,mid+1,r,x);
    }
  push_lazy(2*i);
  push_lazy(2*i+1);
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
	  int l,r,x;
	  cin>>l>>r>>x;
	  update(1,l,r,x);
	}
    }
  return 0;
}
