#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,MOD=1e9+7;
int x,y;
int pw(int a,int b)
{
  if(b==0)return 1;
  int p=pw(a,b/2);
  if(b%2==0)
    return (p*p)%MOD;
  return (((p * p)%MOD) * a)%MOD;
}
int modinv(int a)
{
  return pw(a,MOD-2);
}
int32_t main()
{
  cin>>x>>y;
  /*int p=1;
  for(int i=1;i<=y;i++)
    {
      p*=x;
      p%=MOD;
    }
  cout<<p<<endl;*/
  //cout<<pw(x,y)<<endl;
  cout<<modinv(y)<<endl;
  cout<<x*modinv(y) % MOD<<endl;
  return 0;
}

  //3453^5321
  //k*MOD+r
//pw(x,(MOD-1))=1
//modinv(x)=pw(x,(MOD-2)) ~ 1/x
//a/b=a*modinv(b);
//4*modinv(2)=2
//a*1=a*pw(b,MOD-1)
