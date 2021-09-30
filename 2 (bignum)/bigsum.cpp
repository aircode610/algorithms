#include<bits/stdc++.h>
using namespace std;
vector<int> tovector(string s)
{
  vector<int>ret;
  for(int i=s.size()-1;i>=0;i--)
    ret.push_back(s[i]-'0');
  return ret;
}
vector<int> jam(vector<int> a,vector<int> b)
{
  vector<int>ret(60);
  a.resize(60);
  //for(auto x:a)cout<<x;
  b.resize(60);
  for(int i=0;i<59;i++)
    {
      ret[i+1]=(a[i]+b[i]+ret[i])/10;
      ret[i]=(a[i]+b[i]+ret[i])%10;
    }
  while(ret.back()==0)
    ret.pop_back();
  return ret;
}
int main()
{
  string s,t;
  cin>>s>>t;
  //vector<int> a=tovector(s),b=tovector(t);
  vector<int> sum=jam(tovector(s),tovector(t));
  for(auto x:sum)cout<<x;
  return 0;
}
