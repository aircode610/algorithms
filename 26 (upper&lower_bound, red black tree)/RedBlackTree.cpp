#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main()
{
  //every thing is like std::set
  ordered_set<int> s;
  for(int i=0;i<=20;i+=3)
    s.insert(i);
  s.erase(12);
  s.erase(4);
  cout<<"first element "<<*s.begin()<<endl;//0
  cout<<"Size is "<<s.size()<<endl;//6
  cout<<"last element "<<*s.rbegin()<<endl;//18
  cout<<"upper_bound of 11 is "<<*s.upper_bound(11)<<endl;//15
  cout<<"lower_bound of 15 is "<<*s.lower_bound(15)<<endl;//15
  if(s.find(9)!=s.end())cout<<"There is "<<9<<endl;//9
  for(auto i:s)cout<<i<<" ";cout<<endl;//0 3 6 9 15 18
  cout<<"order of 4 is "<<s.order_of_key(4)<<endl;//2
  cout<<"order of 6 is "<<s.order_of_key(6)<<endl;//2
  cout<<"5th element is "<<*s.find_by_order(5)<<endl;//18 (0-based)
  s.clear();
  cout<<"size after clearing is "<<s.size()<<endl;//0
  return 0;
}
