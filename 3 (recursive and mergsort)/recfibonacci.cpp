#include<iostream>
using namespace std;
long long F[100];
long long f(int n)
{
  if(F[n])
    return F[n];
  if(n==1)
    return F[1]=1LL;
  if(n==2)
    return F[2]=2LL;
  return F[n]=f(n-1)+f(n-2);
}
int main()
{
  int n;
  cin>>n;
  cout<<f(n)<<endl;
  return 0;
}
//f(1)=1
//f(2)=2
//f(n)=f(n-1)+f(n-2)
