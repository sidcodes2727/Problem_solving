#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    int coins = 0;
    int psum = 0;
    int nsum = 0;
    vector<int> pos(n, 0);
    vector<int> neg(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            psum += v[i];
        }
        else
        {
            nsum -= v[i];
        }
        pos[i] = psum;
        neg[i] = nsum;
    }
    int ans = max(psum, nsum);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pos[i] + nsum - neg[i]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
