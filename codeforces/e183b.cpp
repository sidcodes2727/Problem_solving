#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin>>n>>k;
    string s;
    cin >> s;
    vector<char> v(n,'+');
    int l = 0;
    int r = n - 1;
    for (auto &i : s)
    {
        if(k--) break;
        if (l > r)  break;
        if (i == '0'){
            v[l] = '-';
            l++;
        }
        else if (i == '1'){
            v[r] = '-';
            r--;
        }
        else{
            v[l] = '?';
            v[r] = '?';
            l++;
            r--;
        }
    }
    for(auto &i: v)  cout<<i;
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
