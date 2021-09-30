#include<iostream>
using namespace std;
const long long M=1e8;
bool p[M];
int main()
{
  fill(p,p+M,1);
  p[1]=p[0]=false;
  for(int i=2;i<M;i++)
    if(p[i])
      for(int j=i;(long long)i*j<M;j++)
	p[i*j]=false;
  cout<<p[31]<<endl;
  return 0;
}
