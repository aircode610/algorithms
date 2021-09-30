#include<iostream>
#include<vector>
using namespace std;
void chap(vector<int>now,vector<int> v)
{
  if(v.size()==0)
    {
      for(int i=0;i<now.size();i++)
	cout<<now[i];
      cout<<endl;
      return;
    }
  for(int i=0;i<v.size();i++)
    {
      now.push_back(v[i]);
      vector<int>w;
      for(int j=0;j<v.size();j++)
	if(i!=j)
	  w.push_back(v[j]);
      chap(now,w);//{1},{2,3,4,5}
      now.pop_back();
    }
}
int main()
{
  int n;cin>>n;
  chap({},{1,2,3,4,5});
  return 0;
}
//g++ -std=gnu++14 permutationrec.cpp

