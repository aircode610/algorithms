#include<iostream>
#include<map>
using namespace std;
int main()
{
  map<string,int>mp;
  mp["ali"]=13;
  mp["reza"]=14;
  cout<<mp["reza"]<<endl;
  if(mp.find("ali")==mp.end())
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
  mp.erase("ali");
  cout<<mp.size()<<endl;
  cout<<mp["ali"]<<endl;
  cout<<mp.size()<<endl;
  return 0;
}
