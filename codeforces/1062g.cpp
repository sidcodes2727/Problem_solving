#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int n;
vector<ll> a, c, vals;
vector<vector<ll>> dp;

ll solve(int i, int j) {
    if (i == n) return 0; 
    ll &res = dp[i][j];
    if (res != -1) return res;

    res = INF;
    for (int k = j; k < (int)vals.size(); k++) {
        ll cost = (a[i] == vals[k] ? 0 : c[i]);
        res = min(res, cost + solve(i + 1, k));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        c.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();

        dp.assign(n + 1, vector<ll>(m + 1, -1));

        ll ans = INF;
        for (int k = 0; k < m; k++) {
            ll cost = (a[0] == vals[k] ? 0 : c[0]);
            ans = min(ans, cost + solve(1, k));
        }

        cout << ans <<endl;
    }
}
