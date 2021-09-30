#include<iostream>
#include<set>
using namespace std;
int main()
{
  set<int>s;
  for(int i=1;i<=20;i+=3)
    s.insert(i);
  s.insert(14);
  s.insert(13);
  s.insert(20);
  for(auto x:s)
    cout<<x<<" ";
  return 0;
}
//g++ -std=gnu++14 set.cpp
