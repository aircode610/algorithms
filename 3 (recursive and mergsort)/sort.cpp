#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a[100],n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  sort(a+1,a+n+1);
  //reverse(a+1,a+n+1);
  do{
    for(int i=1;i<=n;i++)
      cout<<a[i];
    cout<<endl;
  }while(next_permutation(a+1,a+n+1));
  return 0;
}
//pair<int,int> p={1,2}
//{2,3}>{1,2,3}
