#include<bits/stdc++.h>
using namespace std;
#define int long long
#define hash dafdfasdf
const int M=1e6+10,MOD=999983,p=541;
set<string>h[M];
int n,q,pp[M],hr[M],hl[M];
int hash(string s)//Rabin-Karp
{
  int ret=0;
  for(int i=1;i<s.size();i++)
    (ret+=s[i]*pp[i])%=MOD;
  return ret;
}
int32_t main()
{
  cin>>n>>q;
  pp[0]=1;
  for(int i=1;i<M;i++)
    pp[i]=pp[i-1]*p%MOD;
  for(int i=1;i<=n;i++)
    {
      string s;
      cin>>s;
      s='.'+s;
      h[hash(s)].insert(s);
      //cout<<hash(s)<<endl;
    }
  while(q--)
    {
      string s;
      cin>>s;
      s='.'+s;
      hr[s.size()]=0;
      for(int i=1;i<s.size();i++)
	(hl[i]=hl[i-1]+s[i]*pp[i])%=MOD;
      for(int i=s.size()-1;i>=1;i--)
	(hr[i]=hr[i+1]+s[i]*pp[i])%=MOD;
      string t=s;
      bool found=false;
      for(int i=1;i<s.size();i++)
	{
	  t[i]='a'+(t[i]-'a'+1)%3;
	  //cout<<t<<endl;
	  int hs=(hl[i-1]+hr[i+1]+t[i]*pp[i])%MOD;
	  //cout<<hs<<endl;
	  if(h[hs].find(t)!=h[hs].end())
	    found=true;
	  t[i]='a'+(t[i]-'a'+1)%3;
	  //cout<<t<<endl;
	  hs=(hl[i-1]+hr[i+1]+t[i]*pp[i])%MOD;
	  //cout<<hs<<endl;
	  if(h[hs].find(t)!=h[hs].end())
	    found=true;
	  t[i]='a'+(t[i]-'a'+1)%3;//t==s
	}
      if(found)
	cout<<"YES"<<endl;
      else
	cout<<"NO"<<endl;
    }
  return 0;
}
