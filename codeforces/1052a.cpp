#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<int,int> mp;
    for (int x : v) mp[x]++;

    vector<int> f;
    for (auto &p : mp) f.push_back(p.second);

    int ans = 0;
    for (int x = 1; x <= n; x++) {   
        int cnt = 0;
        for (int fi : f) if (fi >= x) cnt++;
        ans = max(ans, cnt * x);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
