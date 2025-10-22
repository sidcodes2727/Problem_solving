#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> i2;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<i2> vi2;
typedef vector<vi2> v2i2;
typedef vector<ll> vll;
typedef vector<vll> v2ll;
typedef pair<ll, ll> ll2;
typedef vector<ll2> vll2;
typedef vector<vll2> v2ll2;
void pyes() {cout<<"YES\n";} 
void pno() {cout<<"NO\n";}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    int m1 = 0 ;
    int z = 0;
    for(auto &i: v){
        if(i==-1)   m1++;
        else if(i==0)   z++;
    }
    cout<< (m1%2)*2 + z <<endl;
}

  int main()
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
    {
      solve();
    }
  }