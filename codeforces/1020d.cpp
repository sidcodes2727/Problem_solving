#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    
    vector<int> pre(n, 0);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && a[i] >= b[j]) j++;
        pre[i] = j;
    }

    
    if (j == m) {
        cout << 0 << "\n";
        return;
    }

    
    vector<int> suff(n + 1, 0);
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && a[i] >= b[j]) j--;
        suff[i] = m - 1 - j; 
    }

    int ans = INT_MAX;

    for (int i = 0; i <= n; i++) {
        int left = (i == 0 ? 0 : pre[i - 1]);
        int right = (i == n ? 0 : suff[i]);
        if (left + right == m - 1 && left < m)
            ans = min(ans, b[left]);
    }

    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
